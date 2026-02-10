#include <iostream>
#include <fstream>

class Menue{
	
	public:

		int menueEingabe;
		std::string nameEingabe, emailEingabe, passwortEingabe;
		std::string emailAnmeldung, passwortAnmeldung;	
		std::string dEmail, dName , dPasswort;	


		void menueAnzeige() {

			std::cout << "******************************************" << std::endl << std::endl;
			std::cout << " Willkommen " << std::endl << std::endl;
			std::cout << " 1. regristrieren\n"
					  << " 2. anmelden\n"
					  << " 3. beenden\n\n\n";
			std::cout << "******************************************" << std::endl << std::endl;

			std::cin >> menueEingabe;

			switch (menueEingabe){

				case 1:
					regristrierung();
				break;

				case 2:
					anmelden();
				break;

				case 3:
					exit(0);
				break;

				default:
					std::cout << "Ungueltige Eingabe bitte mach es erneut." << std::endl;
				break;

			}

		}

		void regristrierung() {

			std::cout << "Name: \n";
			std::cin >> nameEingabe;


			std::cout << "E-Mail: \n";
			std::cin >> emailEingabe;


			std::cout << "Passwort: \n";
			std::cin >> passwortEingabe;
			

			// fstream library wird genutzt um Daten in eine Datei zu schreiben
			// ofstream erstellt die Datei und schreibt die Daten in der angegebenen Reihenfolge
			// Problem jeder der Zugriff auf users_dat.txt hat kann die Passwörter im Klartext sehen , lesen und verändern
			std::ofstream registrierung("data/v1_users_dat.txt", std::ios::app);
			registrierung << emailEingabe << "  " << passwortEingabe << "  " << nameEingabe << std::endl;
			registrierung.close();
			
			std::cout << "Regristrierung erfolgreich!\n";

		}
		
		void anmelden() {

			std::cout << "Bitte gib deine E-Mail ein: ";
			std::cin >> emailAnmeldung;


			std::cout << "Bitte gib dein Passwort ein: ";
			std::cin >> passwortAnmeldung;

			// ifstream liest die von der vorherigen erstellte datei zum lesen und vergleichen der Daten
			std::ifstream anmeldung("data/v1_users_dat.txt");

			bool gefunden = false;

			// liest die datei zeilenweise und vergleicht die eingegebenen daten mit den gespeicherten
			while (anmeldung >> dEmail >> dPasswort >> dName) {

				if (dEmail == emailAnmeldung) {

					if (dPasswort == passwortAnmeldung) {
						std::cout << "Anmeldung erfolgreich!\n";

						gefunden = true;

					}
					else {

						std::cout << "Falsches Passwort!\n";
						gefunden = true;

					}

					break; 
				}
			}

			if (gefunden == false) {

				std::cout << "Benutzer nicht gefunden!\n";

			}
		}
		

};


int main()
{
	Menue menue;

	while (true) {

		menue.menueAnzeige();
	}


	return 0;
}
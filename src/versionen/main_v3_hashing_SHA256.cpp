#include <iostream>
#include <fstream>
#include <picosha2.h>

class Menue {

public:

	int menueEingabe;
	std::string nameEingabe, emailEingabe, passwortEingabe; 
	std::string emailAnmeldung, passwortAnmeldung;	
	std::string dEmail, dName, dPasswort;	

	void menueAnzeige() {

		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Willkommen " << std::endl << std::endl;
		std::cout << " 1. regristrieren\n"
				  << " 2. anmelden\n"
				  << " 3. beenden\n\n\n";
		std::cout << "******************************************" << std::endl << std::endl;


		std::cin >> menueEingabe;


		switch (menueEingabe) {

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
			std::cout << "Ungültige Eingabe, bitte versuch es erneut." << std::endl;
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


		// Variable fürs Speichern des gehashten Passwort
		std::string hash_hex_passwort; 

		// Hashen des Passworts und Speichern im string hash_hex_passwort
		picosha2::hash256_hex_string(passwortEingabe, hash_hex_passwort); 


		std::ofstream registrierung("data/v3_users_dat.txt", std::ios::app);

		registrierung << emailEingabe << "  " << hash_hex_passwort << "  " << nameEingabe << std::endl;
		registrierung.close();

		std::cout << "Regristrierung erfolgreich\n";

	}

	void anmelden() {

		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> emailAnmeldung;

		std::cout << "Bitte gib dein Passwort ein: ";
		std::cin >> passwortAnmeldung;


		// Hashen des eingegebenen Passworts für die Anmeldung
		picosha2::hash256_hex_string(passwortAnmeldung, passwortAnmeldung);

		std::ifstream anmeldung("data/v3_users_dat.txt");


		bool gefunden = false;


		while (anmeldung >> dEmail >> dPasswort >> dName) {

			if (dEmail == emailAnmeldung) {

				if (dPasswort == passwortAnmeldung) {

					std::cout << "Anmeldung erfolgreich! Willkommen zurueck " << dName << std::endl;

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
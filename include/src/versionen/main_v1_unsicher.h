#pragma once

#include <iostream>
#include <fstream>

class MenueV1{
private:

	std::string dEmail, dName, dPasswort;

public:

		void menueAnzeige() {

			int menueEingabe;

			std::cout << "******************************************" << std::endl << std::endl;
			std::cout << " Willkommen " << std::endl << std::endl;
			std::cout << " 1. registrieren\n"
					  << " 2. anmelden\n"
					  << " 3. zurueck\n"
					  << " 4. beenden\n\n\n";
			std::cout << "******************************************" << std::endl << std::endl;

			std::cin >> menueEingabe;

			switch (menueEingabe){

				case 1:
					registrierung();
				break;

				case 2:
					anmelden();
				break;

				case 3:
					return;
				break;

				case 4:
					exit(0);
				break;

				default:
					std::cout << "Ungueltige Eingabe bitte versuche es erneut." << std::endl;
				break;

			}

		}

		void registrierung() {

			std::string nameEingabe, emailEingabe, passwortEingabe;

			std::cout << "Name: ";
			std::cin >> nameEingabe;


			std::cout << "E-Mail: ";
			std::cin >> emailEingabe;


			std::cout << "Passwort: ";
			std::cin >> passwortEingabe;
			

			// fstream library wird genutzt um Daten in eine Datei zu schreiben
			// ofstream erstellt die Datei und schreibt die Daten in der angegebenen Reihenfolge
			// Problem jeder der Zugriff auf users_dat.txt hat kann die Passwörter im Klartext sehen , lesen und verändern
			std::ofstream registrierung("data/user/v1_users_dat.txt", std::ios::app);
			registrierung << emailEingabe << "  " << passwortEingabe << "  " << nameEingabe << std::endl;
			registrierung.close();
			
			std::cout << "Registrierung erfolgreich!\n\n";

		}
		
		void anmelden() {

			std::string emailAnmeldung, passwortAnmeldung;

			std::cout << "Bitte gib deine E-Mail ein: ";
			std::cin >> emailAnmeldung;


			std::cout << "Bitte gib dein Passwort ein: ";
			std::cin >> passwortAnmeldung;

			// ifstream liest die von der vorherigen erstellte datei zum lesen und vergleichen der Daten
			std::ifstream anmeldung("data/user/v1_users_dat.txt");

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
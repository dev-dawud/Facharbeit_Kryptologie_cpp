#include <iostream>
#include <fstream>
#include "md5.h" // einfache MD5 Implementierung durch eine einfache header only library

class Menue {

public:

	int menueEingabe;									
	std::string nameEingabe, emailEingabe, passwortEingabe;
	std::string emailAnmeldung, passwortAnmeldung;		
	std::string dEmail, dName, dPasswort;		


	MD5 md5;

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
			std::cout << "Ungueltige Eingabe, bitte versuch es erneut" << std::endl;
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
		

		// passwort wird durch den MD5 algorithmus gehashed (also verschlüsselt) bevor es gespeichert wird
		passwortEingabe = md5(passwortEingabe);

		std::ofstream registrierung("data/v2_users_dat.txt", std::ios::app);
		registrierung << emailEingabe << "  " << passwortEingabe << "  " << nameEingabe << std::endl;
		registrierung.close();


		std::cout << "Regristrierung erfolgreich!\n";

	}

	void anmelden() {

		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> emailAnmeldung;


		std::cout << "Bitte gib dein Passwort ein: ";
		std::cin >> passwortAnmeldung;

		// wenn das Passwort das eingegeben wird dasselbe wie beid der Regristriereung ist, kriegt es denselben Hashwert
		// hier wird es erneut gehashed damit es mit dem gespeicherten gehashten Passwort verglichen werden kann
		passwortAnmeldung = md5(passwortAnmeldung);

		std::ifstream anmeldung("data/v2_users_dat.txt");


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

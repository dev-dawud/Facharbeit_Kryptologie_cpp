#include <iostream>
#include <fstream>
#include <picosha2.h>
#include <random> // Für die Generierung von Salt brauche ich die random library

class Menue {

public:

	int menueEingabe;
	std::string nameEingabe, emailEingabe, passwortEingabe; 
	std::string emailAnmeldung, passwortAnmeldung;		
	std::string dEmail, dName, dPasswort , dSalt;
	std::string salt , passwortSalt;

	const std::string zeichen =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"0123456789"
		"!@#$%^&*";


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

		// <random> bibliothek wird genutzt um eine zufallkette zu generieren genaurere infos:  https://learn.microsoft.com/en-us/cpp/standard-library/random?view=msvc-170 
		// rd wird definiert um eine Zufallszahl zu generieren die als Seed für den Generator dient
		std::random_device rd;

		// Generator wird mit dem Seed initialisiert
		std::mt19937 generator(rd());

		std::uniform_int_distribution<> dist(0, zeichen.size() - 1);

		// Generiere einen Salt mit einer Länge von 16 Zeichen
		for (int i = 0; i < 16; ++i) {

			salt += zeichen[dist(generator)];
		
		}

		passwortEingabe += salt; // Salt wird zum Passwort hinzufügefugt


		std::string hash_hex_passwort;
		picosha2::hash256_hex_string(passwortEingabe, hash_hex_passwort); 


		std::ofstream registrierung("data/v4_users_dat.txt", std::ios::app);
		registrierung << emailEingabe << " " << salt << " " << hash_hex_passwort << " " << nameEingabe << std::endl;
		registrierung.close();

		ramLoeschen(passwortEingabe);
		ramLoeschen(salt);

		std::cout << "Regristrierung erfolgreich!\n";

	}

	void anmelden() {

		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> emailAnmeldung;

		std::cout << "Bitte gib dein Passwort ein: ";
		std::cin >> passwortAnmeldung;

		// picosha2::hash256_hex_string(passwortAnmeldung, passwortAnmeldung);

		std::ifstream anmeldung("data/v4_users_dat.txt");


		bool gefunden = false;


		while (anmeldung >> dEmail >> dSalt >> dPasswort >> dName) {

			if (dEmail == emailAnmeldung) {

				// Das Passwort wird mit dem Salt gehasht damit man es mit dem gespeicherten Hash zu vergleichen
				std::string Passwort = passwortAnmeldung + dSalt;

				picosha2::hash256_hex_string(Passwort, passwortAnmeldung);

				// Alle restlichen Daten , Variablen im RAM werden gelöscht bzw mit 0000 überschrieben
				ramLoeschen(Passwort);
				ramLoeschen(dSalt);
				ramLoeschen(dEmail);
				ramLoeschen(dName);

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

		ramLoeschen(passwortAnmeldung);

		if (gefunden == false) {

			std::cout << "Benutzer nicht gefunden!\n";

		}
	}

	// Funktion überschreibt Daten im RAM mit 0000 damit sie nicht mehr lesbar sind
	void ramLoeschen(std::string &eingabe) {

		for (size_t i = 0; i < eingabe.size(); ++i) {

			// "volatile" ist dafür da dass der compiler die Anweisung befolgt und nicht überspringt
			volatile char* p = &eingabe[i];

			*p = '\0';

		}
		// Am Ende wird die Eingabe geleert damit die nicht mehr lesbar ist
		eingabe.clear();

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
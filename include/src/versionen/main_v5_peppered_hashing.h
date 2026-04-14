#include <iostream>
#include "backend/AuthManager-v5.h"
#include <string>

// In v5 ist das Programm in einen Frontend und Backend unterteilt. In AuthManager.h findet man den Backend Bereich
// Im frontend breich wird das Menü in der konsole angezeigt und input und output verarbeitet


class MenueV5 {
private: 

	AuthManagerV5 AuthManagerV5;

public:

	void menueAnzeige() {

		int menueEingabe;

		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Willkommen " << std::endl << std::endl;
		std::cout << " 1. regristrieren\n"
				  << " 2. anmelden\n"
				  << " 3. zurueck\n"
				  << " 4. beenden\n\n\n";
		std::cout << "******************************************" << std::endl << std::endl;

		
		std::cin >> menueEingabe;


		switch (menueEingabe) {

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
			std::cout << "Ungültige Eingabe, bitte versuche es erneut." << std::endl;
		break;

		}

	}


	void registrierung() {

		// n e p sind parameter für die Funktion bRegistrieren() in AuthManager.h
		// n  name e email p passwort
		std::string n, e, p;

		std::cout << "******* REGISTRIERUNG *******" << std::endl << std::endl;

		std::cout << "Bitte gib deinen Namen ein (nur Vorname!): ";

		// getline bansprucht die ganze zeile
		std::getline(std::cin >> std::ws, n);


		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> e;

		std::cout << "Bitte gib dein Passwort ein: ";
		std::cin >> p;


		if (AuthManagerV5.bRegistrieren(n, e, p) == true) {

			std::cout << "Registrierung erfolgreich!\n";

		}
		else{

			std::cout << "Registrierung fehlgeschlagen!\n";
		}


	}


	void anmelden() {

		std::string e, p;

		std::cout << "********** ANMELDUNG **********" << std::endl << std::endl;

		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> e;

		std::cout << "Bitte gib dein Passwort ein: ";
		std::cin >> p;


		if (AuthManagerV5.bAnmelden(e, p) == true) {

			std::cout << "Anmeldung erfolgreich!\n";

		}
		else {

			std::cout << "Anmeldung fehlgeschlagen!\n";
		}

	}



};
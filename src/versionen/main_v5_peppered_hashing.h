#include <iostream>
#include "../../include/AuthManager-v5.h"
#include <string>

// In v5 habe ich das Programm in einen Frontend und backend unterteilt. In AuthManager.h findet man den Backend bereich
// Im frontend breich wird das Menü in der konsole angezeigt und input und output verarbeitet


class MenueV5 {

public:
	
	// AuthManager.h ist mein Objekt, dass ich definiere um die Funktionen der Klasse AuthManager zu benutzen
    AuthManagerV5 AuthManagerV5; 

public:

	int menueEingabe;
	std::string nameEingabe, emailEingabe, passwortEingabe;	
	std::string emailAnmeldung, passwortAnmeldung;	
	std::string dEmail, dName, dPasswort, dSalt;
	std::string salt, passwortSalt;	


	
	void menueAnzeige() {

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
			regristrierung();
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
			std::cout << "Ungültige Eingabe, bitte mach es erneut." << std::endl;
		break;

		}

	}


	void regristrierung() {

		// n e p sind parameter für die Funktion bRegistrieren() in AuthManager.h
		// n name e email p passwort
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

			std::cout << "Regristrierung erfolgreich!\n";

		}
		else{

			std::cout << "Regristrierung fehlgeschlagen!\n";
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
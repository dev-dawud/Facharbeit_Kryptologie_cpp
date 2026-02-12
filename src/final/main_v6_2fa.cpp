#include <iostream>
#include <AuthManager.h> 
#include <windows.h>
#include <stdlib.h>
#include <filesystem>

class Menue {

public:

	AuthManager AuthManager;

public:

	int menueEingabe;


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
			std::cout << "Ungültige Eingabe, bitte mach es erneut." << std::endl;
		break;

		}

	}


	void regristrierung() {

		std::string n, e, p, t;

		std::cout << "******* REGISTRIERUNG *******" << std::endl << std::endl;



		std::cout << "Bitte gib deinen Namen ein (nur Vorname!): ";
		std::getline(std::cin >> std::ws, n);


		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> e;

		// überprüft ob @ vorkommt bei der eingabe und npos gibt an wenn es nicht gefunden wurde und ein fehlermeldung kommt
		if (e.find('@') == std::string::npos) {

			std::cout << "E-Mail-Adresse ungueltig Bitte versuche es erneut\n";
			return;
		}

		std::cout << "Bitte gib deine Tel. ein: ";
		std::cin >> t;

		if (t.length() != 9) {

			std::cout << "Telefonnummer nicht gueltig Bitte versuche es erneut\n\n";
			return;
		}


		std::cout << "Bitte erstelle ein Passwort: ";
		std::cin >> p;



		if (AuthManager.bRegistrieren(n, e, p , t) == true) {

			std::cout << "Regristrierung erfolgreich!\n";

		}
		else {

			std::cout << "Regristrierung fehlgeschlagen!\n" 
					  << "Bitte versuche es erneut\n";
		}

	}


	void anmelden() {

		std::string e, p, t;

		std::cout << "\n********** ANMELDUNG **********" << std::endl << std::endl;

		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> e;

		std::cout << "Bitte gib dein Passwort ein: ";
		std::cin >> p;


		if (AuthManager.bAnmelden(e, p) == true) {

			zweiFaktor_auth();

		}
		else {

			std::cout << "Anmeldung fehlgeschlagen!\n" << "Bitte versuche es erneut\n\n";

		}

	}

	void zweiFaktor_auth() {

		std::string c;

		std::cout << "Wir schicken dir einen 6 stelligen code zu ";

		AuthManager.codeSenden(c);
		//system("start data\\users_tel.txt");


		std::cout << "Bitte geben sie ihren 6 stelligen Code ein: " << std::endl;
		std::cin >> c;

		if (AuthManager.bZweiFaktor_auth(c) == true) {

			std::cout << "Anmeldung erfolgreich\n";
		}
		else {

			std::cout << "Anmeldung fehlgeschlagen\n";
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
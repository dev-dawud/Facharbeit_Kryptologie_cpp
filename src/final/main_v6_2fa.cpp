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
	std::string nameEingabe, emailEingabe, passwortEingabe;
	std::string emailAnmeldung, passwortAnmeldung;
	std::string dEmail, dName, dPasswort, dSalt;
	std::string salt, passwortSalt;


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



		std::cout << "Bitte gib deinen Namen ein: ";
		std::getline(std::cin >> std::ws, n);


		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> e;


		std::cout << "Bitte gib deine Tel. ein: ";
		std::cin >> t;


		std::cout << "Bitte gib dein Passwort ein: ";
		std::cin >> p;


		if (AuthManager.bRegistrieren(n, e, p , t) == true) {

			std::cout << "Regristrierung erfolgreich!\n";

		}
		else {

			std::cout << "Regristrierung fehlgeschlagen!\n";
		}


	}


	void anmelden() {

		std::string e, p, t;

		std::cout << "********** ANMELDUNG **********" << std::endl << std::endl;

		std::cout << "Bitte gib deine E-Mail ein: ";
		std::cin >> e;

		std::cout << "Bitte gib dein Passwort ein: ";
		std::cin >> p;


		if (AuthManager.bAnmelden(e, p) == true) {

			std::cout << "Anmeldung erfolgreich!\n";

			zweiFaktor_auth();

		}
		else {

			std::cout << "Anmeldung fehlgeschlagen!\n";
		}

	}

	void zweiFaktor_auth() {

		std::string c;

		std::cout << "Wir schicken dir einen 6 stelligen code bei ";

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
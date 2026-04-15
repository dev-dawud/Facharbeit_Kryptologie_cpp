#pragma once

#include <iostream>
#include <fstream>
#include "../include/librarys/md5.h" // einfache MD5 Implementierung durch eine einfache header only library

class MenueV2 {
private:

	MD5 md5;

	std::string dEmail, dName, dPasswort;

public:

	void menueAnzeige() {

		int menueEingabe;

		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Willkommen " << std::endl << std::endl;
		std::cout << " 1. registrieren\n"
				  << " 2. anmelden\n"
				  << " 3. anmelden\n"
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
			std::cout << "Ungueltige Eingabe, bitte versuche es erneut" << std::endl;
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


		// passwort wird durch den MD5 algorithmus gehashed bevor es gespeichert wird
		passwortEingabe = md5(passwortEingabe);

		std::ofstream registrierung("data/user/v2_users_dat.txt", std::ios::app);
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

		// wenn das Passwort das eingegeben wird dasselbe wie beid der Registriereung ist, 
		// kriegt es denselben Hashwert und kann mit dem der in der Datei gespeicherten Hash vergleichen
		passwortAnmeldung = md5(passwortAnmeldung);

		std::ifstream anmeldung("data/user/v2_users_dat.txt");


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
#pragma once

#include <iostream>
#include <random>
#include "../include/librarys/picosha2.h"
#include "../include/src/versionen/backend/AuthManager.h"
#include "../include/librarys/md5.h"

std::string salt;

class hashGenerator {
private:

	std::string pEingabe, md5Hash, passwort;

	char saltEingabe;
	MD5 md5;
	AuthManagerV6 authManagerV6;

public:

	void hashgenerator() {

		int hashgenEingabe;

		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Hash Generator " << std::endl << std::endl;
		std::cout << "1. MD5\n"
			<< "2. SHA256\n"
			<< "3. zurueck\n\n";
		std::cout << "******************************************" << std::endl << std::endl;

		std::cin >> hashgenEingabe;

		switch (hashgenEingabe) {
		case 1:
			hashgeneratorMD5();
			break;

		case 2:
			hashgeneratorSHA256();
			break;

		default:
			std::cout << "Ungueltige Eingabe bitte versuche es erneut.";
			break;
		}

	}

	void hashgeneratorMD5() {

		std::cout << "\nBitte gib dein Passwort ein: ";

		std::cin >> pEingabe;

		std::cout << "\nMöchtest du einen salt hinzufügen (J/j | N/n): ";
		std::cin >> saltEingabe;

		std::cout << std::endl;

		if (saltEingabe == 'J' || saltEingabe == 'j') {

			authManagerV6.generiereSalt(salt);

			passwort = pEingabe + salt;

			md5Hash = md5(passwort);

			std::cout << "Hash: " << md5Hash << std::endl;

		}
		else if (saltEingabe == 'N' || saltEingabe == 'n') {

			md5Hash = md5(pEingabe);

			std::cout << "Hash: " << md5Hash << std::endl;
		}
		else {

			std::cout << "Ungueltige Eingabe versuch es erneut.";

			return;
		}
	}

	void hashgeneratorSHA256() {

		std::string pEingabe, sha256Hash;
		char saltEingabe;

		std::cout << "\nBitte gib dein Passwort ein: ";

		std::cin >> pEingabe;

		std::cout << "Möchtest du einen salt hinzufügen (J/j | N/n): ";
		std::cin >> saltEingabe;

		if (saltEingabe == 'J' || saltEingabe == 'j') {

			authManagerV6.generiereSalt(salt);

			passwort = pEingabe + salt;

			picosha2::hash256_hex_string(passwort, sha256Hash);

			std::cout << "Hash: " << sha256Hash << std::endl;

		}
		else if (saltEingabe == 'N' || saltEingabe == 'n') {

			picosha2::hash256_hex_string(pEingabe, sha256Hash);

			std::cout << "Hash: " << sha256Hash << std::endl;
		}
		else {

			std::cout << "Ungueltige Eingabe versuch es erneut.";

			return;
		}
	}
};
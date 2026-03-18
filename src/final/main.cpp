#include <iostream>
#include "../versionen/main_v1_unsicher.h"
#include "../versionen/main_v2_hashing_MD5.h"
#include "../versionen/main_v3_hashing_SHA256.h"
#include "../versionen/main_v4_salted_hashing.h"
#include "../versionen/main_v5_peppered_hashing.h"
#include "../versionen/main_v6_2fa.h"
#include "../tools/tool.h"
#include "../../include/picosha2.h"

std::string salt, passwort;

class Menue {
public:

	MenueV1 menueV1;
	MenueV2 menueV2;
	MenueV3 menueV3;
	MenueV4 menueV4;
	MenueV5 menueV5;
	MenueV6 menueV6;

	Tool Tools;

	void menueAnzeige() {



		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Willkommen " << std::endl << std::endl;
		std::cout << "1. Versionen\n"
				  << "2. tools\n"
				  << "3. Hash Generator\n"
				  << "4. beenden\n\n";
		std::cout << "******************************************" << std::endl << std::endl;

		int menueEingabe;

		std::cin >> menueEingabe;

		switch (menueEingabe) {
			
			case 1:
				versionen();
			break;
			
			case 2:
				Tools.tool();
			break;

			case 3:
				hashgenerator();
			break;
			
			case 4:
				exit(0);
			break;

			default:
				std::cout << "Ungueltige Eingabe bitte mach es erneut." << std::endl;
			break;
		}
	}

	void versionen() {

		int versionEingabe;

		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Versionen " << std::endl << std::endl;
		std::cout << "1. Version 1\n"
				  << "2. Version 2\n"
				  << "3. Version 3\n"
				  << "4. Version 4\n"
				  << "5. Version 5\n"
				  << "6. Version 6\n"
				  << "7. zurueck\n\n";
		std::cout << "******************************************" << std::endl << std::endl;

		std::cin >> versionEingabe;

		switch (versionEingabe) {
			
			case 1:
				menueV1.menueAnzeige();
			break;

			case 2:
				menueV2.menueAnzeige();	
			break;

			case 3:
				menueV3.menueAnzeige();
			break;

			case 4:
				menueV4.menueAnzeige();
			break;

			case 5:
				menueV5.menueAnzeige();
			break;

			case 6:
				menueV6.menueAnzeige();
			break;
			
			case 7:
				return;
			break;

			default:
				std::cout << "Ungueltige Eingabe bitte mach es erneut." << std::endl;
			break;
		}
	}

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
			std::cout << "Ungueltige Eingabe bitte mach es erneut.";
			break;
		}

	}

	void hashgeneratorMD5() {

		std::string pEingabe, md5Hash;
		char saltEingabe;
		MD5 md5;

		std::cout << "\nBitte gib dein Passwort ein: ";

		std::cin >> pEingabe;

		std::cout << "Möchtest du einen salt hinzufügen (J/j | N/n): ";
		std::cin >> saltEingabe;

		if (saltEingabe == 'J' || saltEingabe == 'j') {

			AuthManagerV6 authManagerV6;

			generiereSalt();

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

		if(saltEingabe == 'J' || saltEingabe == 'j'){

			generiereSalt();

			passwort = pEingabe + salt;

			picosha2::hash256_hex_string(passwort , sha256Hash);

			std::cout << "Hash: " << sha256Hash << std::endl;

		}
		else if (saltEingabe == 'N' || saltEingabe == 'n') {

			picosha2::hash256_hex_string(pEingabe , sha256Hash);

			std::cout << "Hash: " << sha256Hash << std::endl;
		}
		else{
			std::cout << "Ungueltige Eingabe versuch es erneut.";
			return;
		}
	}

	void generiereSalt() {

		const std::string zeichen =
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"0123456789"
			"!@#$%^&*";

		salt = "";

		std::random_device rd;
		std::mt19937 generator(rd());

		std::uniform_int_distribution<> dist(0, static_cast<int>(zeichen.size()) - 1);

		for (int i = 0; i < 4; ++i) {

			salt += zeichen[dist(generator)];
		}
	}
};

int main() {

	Menue menue;

	while (true) {

		menue.menueAnzeige();

	}

	return 0;
}
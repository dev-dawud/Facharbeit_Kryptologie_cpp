#include <iostream>
#include "../versionen/main_v1_unsicher.h"
#include "../versionen/main_v2_hashing_MD5.h"
#include "../versionen/main_v3_hashing_SHA256.h"
#include "../versionen/main_v4_salted_hashing.h"
#include "../versionen/main_v5_peppered_hashing.h"
#include "../versionen/main_v6_2fa.h"

class Menue {
public:

	MenueV1 menueV1;
	MenueV2 menueV2;
	MenueV3 menueV3;
	MenueV4 menueV4;
	MenueV5 menueV5;
	MenueV6 menueV6;

	void menueAnzeige() {

		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Willkommen " << std::endl << std::endl;
		std::cout << "1. Versionen\n"
				  << "2. beenden\n\n";
		std::cout << "******************************************" << std::endl << std::endl;

		int menueEingabe;

		std::cin >> menueEingabe;

		switch (menueEingabe) {
			
			case 1:
				versionen();
			break;

			case 2:
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
};

int main() {

	Menue menue;

	while (true) {

		menue.menueAnzeige();

	}

	return 0;
}
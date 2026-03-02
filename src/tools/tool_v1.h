#pragma once

#include <iostream>
#include <fstream>
#include "../../include/AuthManager.h"
#include <string>
class Tool {
public: 

	void tool(){
		
		int toolEingabe;

		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Willkommen bei den tools\n\n";
		std::cout << "1. Datei auslesen\n"
				  << "2. Rainbow Table\n"
				  << "3. Brute Force\n"
				  << "4. beenden\n\n";
		std::cout << "******************************************" << std::endl << std::endl;

		std::cin >> toolEingabe;

		switch (toolEingabe) {

		case 1:
			dateiAuslesen();
		break;

		case 2:
			rainbowTable();
		break;

		case 3:
			//bruteForce();
		break;

		case 4:
			exit(0);
		break;

		default:
			std::cout << "Ungueltige Eingabe, bitte mach es erneut" << std::endl;
		break;


		}
	
	}

	void dateiAuslesen() {

		int dateiEingabe;
		std::string zeile;

		std::cout << "Welche Datei soll ausgelesen werden? (1-6) \n";

		std::cin >> dateiEingabe;

		switch (dateiEingabe){
			
		case 1: {
			std::ifstream datei("data/user/v1_users_dat.txt");

			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
		break;

		case 2: {
			std::ifstream datei("data/user/v2_users_dat.txt");

			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
		break;

		case 3:{
			std::ifstream datei("data/user/v3_users_dat.txt");

			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
		break;

		case 4:{
			std::ifstream datei("data/user/v4_users_dat.txt");


			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
		break;

		case 5:{
			std::ifstream datei("data/user/v5_users_dat.txt");

			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
		break;

		case 6:{
			std::ifstream datei("data/user/v6_users_dat.txt");

			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
		break;

		default:
			std::cout << "Ungueltige Eingabe, bitte mach es erneut" << std::endl;
		break;
		}
    }
	void rainbowTable() {
		
		std::string email = "davidwahab869@gmail.com";
		std::string code = "61f152f62c4a29f6";

		std::string hash;

		std::cout << "Bitte gib denn Hash ein: ";
		std::cin >> hash;

		std::string url = "https://md5decrypt.net/en/Api/api.php?hash=" + hash + "&hash_type=md5&email=" + email + "&code=" + code;

		std::system(("start \"\" \"" + url + "\"").c_str());

	}
};	
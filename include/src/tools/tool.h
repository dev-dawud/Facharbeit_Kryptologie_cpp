#pragma once

#include <iostream>
#include <fstream>
#include "../include/src/versionen/backend/AuthManager.h"
#include <string>
#include "main_hack.h"
#include "main_brute_force.h"
#include "main_rainbow_table.h"

class Tool {
public:

	void tool() {

		int toolEingabe;

		std::cout << "******************************************" << std::endl << std::endl;
		std::cout << " Willkommen bei den tools\n\n";
		std::cout << "1. Datei auslesen\n"
			<< "2. Rainbow Table\n"
			<< "3. Brute Force\n"
			<< "4. automatisch\n"
			<< "5. beenden\n\n";
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
			bruteForce();
			break;

		case 4:
			automatisch();
			break;

		case 5:
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

		switch (dateiEingabe) {

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

		case 3: {
			std::ifstream datei("data/user/v3_users_dat.txt");

			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
			  break;

		case 4: {
			std::ifstream datei("data/user/v4_users_dat.txt");


			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
			  break;

		case 5: {
			std::ifstream datei("data/user/v5_users_dat.txt");

			while (std::getline(datei, zeile)) {

				std::cout << zeile << std::endl;
			}
			datei.close();
		}
			  break;

		case 6: {
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

		mainTool maintool;

		maintool.rainbowTable();

	}

	void bruteForce() {
		BruteForce bruteForce;

		bruteForce.erkenneHash();
	}

	void automatisch() {
		mainTool maintool;

		maintool.rainbowTable();
		maintool.bruteForce(maintool.zielHash, maintool.typ);
	}
};
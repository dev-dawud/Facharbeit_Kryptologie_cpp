#pragma once

#include <iostream>		
#include <fstream>
#include <random>	
#include <thread>
#include <chrono>
#include "../include/librarys/picosha2.h"
#include <windows.h>

class AuthManagerV6 {

private:

	std::string dEmail, dName, dPasswort, dSalt, dTel;
	std::string salt, passwortSalt, code;

	const std::string codeZeichen = "0123456789";

	const std::string zeichen =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"0123456789"
		"!@#$%^&*";

	const std::string pepper = "d3r_p3pp3r_ist_imm3r_3in_f3st3r_w3rt_und_wird_imm3r_irg3ndwo_im_cod3_od3r_3xt3rn3_f3stplatt3_v3rst3ckt";

	void ramLoeschen(std::string& eingabe) {

		for (size_t i = 0; i < eingabe.size(); ++i) {

			volatile char* p = &eingabe[i];

			*p = '\0';
		}

		eingabe.clear();

	}

	void generiereCode() {

		code = "";

		std::random_device rd;
		std::mt19937 generator(rd());

		std::uniform_int_distribution<> dist(0, static_cast<int>(codeZeichen.size()) - 1);

		for (int i = 0; i < 6; ++i) {

			code += codeZeichen[dist(generator)];
		}
	}

public:

	void generiereSalt(std::string returnSalt) {

		returnSalt = "";

		std::random_device rd;
		std::mt19937 generator(rd());

		std::uniform_int_distribution<> dist(0, static_cast<int>(zeichen.size()) - 1);

		for (int i = 0; i < 16; ++i) {

			returnSalt += zeichen[dist(generator)];
		}
	}

	void codeSenden(std::string tel) {

<<<<<<< HEAD:include/AuthManager.h
=======
		***REMOVED***
>>>>>>> 8165ed4 (hinzufügen einer hashgenerator Klasse und übersichtlichere main.cpp / anpassen der Odnerstrukur):include/src/versionen/backend/AuthManager.h
		SYSTEMTIME st;
		GetLocalTime(&st);


		std::string checkNummer;

		if (tel.empty()) {

			checkNummer = dTel;
		}
		else {

			checkNummer = tel;
		}

		if (checkNummer.empty()) {

			std::cout << "\nFehler: Keine Telefonnummer gefunden :(\n" << std::endl;
			return;
		}



		std::cout << "\nsenden... \n";

		generiereCode();


		std::this_thread::sleep_for(std::chrono::seconds(5));


		std::cout << "Code gesendet an " << checkNummer << std::endl;
		std::cout << code << std::endl;

		std::cout << "gesendet um: " << st.wDay << "." << st.wMonth << "." << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << std::endl;
	}

	bool bZweiFaktor_auth(std::string c) {

		if (c == code) {

			return true;
		}

		return false;
	}

	bool bRegistrieren(std::string name, std::string email, std::string passwort, std::string tel) {

		generiereSalt(salt);


		passwort = passwort + pepper + salt;

		std::string hash_hex_passwort;

		picosha2::hash256_hex_string(passwort, hash_hex_passwort);

		std::ofstream registrierung("data/user/v6_users_dat.txt", std::ios::app);

		registrierung << salt << " " << tel << " " << hash_hex_passwort << " " << email << " " << name << std::endl;
		registrierung.close();

		ramLoeschen(passwort);
		ramLoeschen(salt);

		return true;
	}

	bool bAnmelden(std::string email, std::string passwort) {

		std::ifstream anmeldung("data/user/v6_users_dat.txt");

		while (anmeldung >> dSalt >> dTel >> dPasswort >> dEmail >> dName) {

			if (dEmail == email) {

				std::string kombi = passwort + pepper + dSalt;
				std::string berechneterHash;
				picosha2::hash256_hex_string(kombi, berechneterHash);

				ramLoeschen(kombi);

				if (dPasswort == berechneterHash) {

					ramLoeschen(passwort);
					ramLoeschen(dSalt);
					ramLoeschen(dPasswort);

					return true;
				}
			}
		}

		ramLoeschen(passwort);

		return false;
	}
};
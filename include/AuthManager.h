#pragma once
#include <iostream>		
#include <fstream>
#include <picosha2.h>
#include <random>	
#include <thread>
#include <chrono>


// Backend Bereich des Programms
// //In dieser Klasse sind die Funktionen für die Regristrierung und Anmeldung des users
class AuthManager {


private:

	int menueEingabe;
	std::string nameEingabe, emailEingabe, passwortEingabe;
	std::string emailAnmeldung, passwortAnmeldung;
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

	void generiereSalt() {

		salt = "";

		std::random_device rd;
		std::mt19937 generator(rd());

		std::uniform_int_distribution<> dist(0, zeichen.size() - 1);


		for (int i = 0; i < 16; ++i) {

			salt += zeichen[dist(generator)];

		}

	}


public:

	void codeSenden(std::string tel) {
		
		std::string checkNummer;

		if (tel.empty()) {

			// Nummer wird überprüft ob die in der Datei existiert wenn ja wird die Nummer aus der Datei genommen wenn nein wird die eingegebene Nummer von bregistrieren() genommen
			checkNummer = dTel;
		}
		else {

			checkNummer = tel;

		}

		if(checkNummer.empty()) {

			std::cout << "Fehler: Keine Telefonnummer gefunden :(" << std::endl;

			return;
		}

		std::cout << "\nsenden... \n";

		generiereCode();

		std::this_thread::sleep_for(std::chrono::seconds(5));

		std::cout << "Code gesendet an " << tel << ": " << code << std::endl;
	}

	bool bZweiFaktor_auth(std::string c) {

		if (c == code) {

			return true;
		}
		else {

			return false;
		}
	}
	bool bRegistrieren(std::string name, std::string email, std::string passwort, std::string tel) {

		generiereSalt();

		passwort = passwort + pepper + salt;

		std::string hash_hex_passwort;
		picosha2::hash256_hex_string(passwort, hash_hex_passwort);


		std::ofstream registrierung("data/v6_users_dat.txt", std::ios::app);

		registrierung << email << " " << salt << " " << hash_hex_passwort << " " << name << " " << tel << std::endl;

		registrierung.close();


		ramLoeschen(passwort);
		ramLoeschen(salt);


		return true;
	}

	bool bAnmelden(std::string email, std::string passwort) {


		std::ifstream anmeldung("data/v6_users_dat.txt");


		while (anmeldung >> dEmail >> dSalt >> dPasswort >> dName >> dTel) {

			if (dEmail == email) {

				std::string kombi = passwort + pepper + dSalt;

				std::string berechneterHash;
				picosha2::hash256_hex_string(kombi, berechneterHash);


				ramLoeschen(kombi);


				if (dPasswort == berechneterHash) {

					ramLoeschen(passwort);
					ramLoeschen(dSalt);
					ramLoeschen(dPasswort);
					ramLoeschen(dTel);

					return true;
				}
			}
		}

		ramLoeschen(passwort);

		return false;
	}


};
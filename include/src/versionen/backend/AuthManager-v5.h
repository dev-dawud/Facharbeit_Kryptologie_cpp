#pragma once

#include <iostream>		
#include <fstream>
#include "../include/librarys/picosha2.h"
#include <random>

// Backend Bereich des Programms
// In dieser Klasse sind die Funktionen für die Regristrierung und Anmeldung des users
class AuthManagerV5 {

	
private:

	std::string dEmail, dName, dPasswort, dSalt;
	std::string salt, passwortSalt;

	const std::string pepper = "d3r_p3pp3r_ist_imm3r_3in_f3st3r_w3rt_und_wird_imm3r_irg3ndwo_im_cod3_od3r_3xt3rn3_f3stplatt3_v3rst3ckt";

	const std::string zeichen =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"0123456789"
		"!@#$%^&*";




	// ramLoeschen() ist privat weil man es nur intern in der klasse benutzen darf um sicher zu sein dass daten wie passwörter nicht im ram verbleiben
	void ramLoeschen(std::string& eingabe) {

	
		for (size_t i = 0; i < eingabe.size(); ++i) {

			volatile char* p = &eingabe[i];

			*p = '\0';

		}
		eingabe.clear(); 

	}

	
	void generiereSalt() {

		// um Potenzierung zu vermeiden wird der salt immer auf leer definiert bevor ein neuer generiert wird
		salt = "";


		std::random_device rd;
		std::mt19937 generator(rd());

		std::uniform_int_distribution<> dist(0, zeichen.size() - 1);


		for (int i = 0; i < 16; ++i) {
			
			salt += zeichen[dist(generator)];

		}

	}

	// Öffentlicher Bereich der Klasse 
	// Hier sind die Funktionen für die Registrierung und Anmeldung des users
public:

	bool bRegistrieren(std::string name, std::string email, std::string passwort) {

		generiereSalt();

		passwort = passwort + pepper + salt;

		std::string hash_hex_passwort;
		picosha2::hash256_hex_string(passwort, hash_hex_passwort);


		std::ofstream registrierung("data/user/v5_users_dat.txt", std::ios::app);
		registrierung << email << " " << salt << " " << hash_hex_passwort << " " << name << std::endl;

		registrierung.close();


		ramLoeschen(passwort); 
		ramLoeschen(salt);


		return true;
	}

	bool bAnmelden(std::string email, std::string passwort) {

		
		std::ifstream anmeldung("data/user/v5_users_dat.txt");


		while (anmeldung >> dEmail >> dSalt >> dPasswort >> dName) {

			if (dEmail == email) {

				std::string kombi = passwort + pepper + dSalt;

				std::string berechneterHash;

				picosha2::hash256_hex_string(kombi, berechneterHash);

				ramLoeschen(kombi);


				if (dPasswort == berechneterHash) {
					ramLoeschen(passwort);
					return true;
				}
			}
		}

		ramLoeschen(passwort);

		return false;
	}


};

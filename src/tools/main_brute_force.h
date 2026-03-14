#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "../../include/picosha2.h"
#include "../../include/md5.h"
#include "main_hack.h"

class BruteForce {
public:

    void erkenneHash() {

        mainTool maintool;
        int typ = 0;
        std::string hashPassword, passwordVersuch;


        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";


        std::cout << "Bitte geben sie den Hash ein der geprüft werden soll: ";

        std::cin >> hashPassword;

        if (hashPassword.length() == 32) {

            typ = 32;

            std::cout << "hash ist MD5\n";
        }
        else if (hashPassword.length() == 64) {

            typ = 64;

            std::cout << "hahs ist SHA-256\n";
        }
        else {

            std::cout << "Fehler: Ungueltige Hash laenge!\n";

            return;
        }

		auto start = std::chrono::high_resolution_clock::now();

		maintool.bruteForce(hashPassword, typ);

		auto end = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double> laenge = end - start;

		std::cout << "Es hat " << laenge.count() << " Sekunden gedauert\n";

    }
};
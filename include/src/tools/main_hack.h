#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "../include/librarys/picosha2.h"
#include "../include/librarys/md5.h"

class mainTool {
public:

    std::string hash;
    std::string Zeile;
    std::string hashZeile;
    std::string passwordVersuch, password;
    std::string versuchHash, zielHash;

    // Typ wird als erkennung für die Brute Force genutzt damit sie weiß ob es md5 oder sha algo ist
    int typ;

    MD5 md5;

    void rainbowTable() {

        bool gefunden = false;
        bool APIgefunden = false;


        std::cout << "Bitte geben sie ihren Hash ein: ";
        std::cin >> hash;

        zielHash = hash;

        if (hash.length() == 32) {

            typ = 32;

            std::cout << "Rainbowtable wird geladen...\n";

            std::fstream tabelle("data/list/rockyou.txt");

            auto start = std::chrono::high_resolution_clock::now();

            while (std::getline(tabelle, Zeile)) {

                hashZeile = md5(Zeile);

                if (hash == hashZeile) {

                    gefunden = true;

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> laenge = end - start;

                    std::cout << "Es hat " << laenge.count() << " Sekunden gedauert\n";

                    break;
                }

            }

            tabelle.close();

            if (gefunden == true) {

                std::cout << "Passwort gefunden: " << Zeile << std::endl;

            }
            else {

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laenge = end - start;

                std::cout << "Es hat " << laenge.count() << " Sekunden gedauert\n";

                std::cout << "Passwort wird weiter gesucht...\n";

                std::string email = "davidwahab869@gmail.com";
                std::string code = "61f152f62c4a29f6";

                std::string url = "https://md5decrypt.net/en/Api/api.php?hash=" + hash + "&hash_type=md5&email=" + email + "&code=" + code;


                std::system(("start \"\" \"" + url + "\"").c_str());


                if (APIgefunden == true) {

                    std::cout << "Passwort gefunden!";

                    return;
                }
                else {

                    std::cout << "\nPasswort nicht gefunden\n" << std::endl;
                    char eingabe;

                    std::cout << "\nMöchtest du BruteForce starten?\n";

                    std::cin >> eingabe;

                    if (eingabe == 'J' || eingabe == 'j') {

                        std::cout << "Brute Force wird gestartet... \n" << std::endl;
                        bruteForce(zielHash, typ);
                    }
                    else {
                        return;
                    }
                }


            }
        }
        else if (hash.length() == 64) {

            typ = 64;

            std::cout << "Rainbowtable wird geladen...\n";

            std::fstream tabelle("data/list/rockyou.txt");

            auto start = std::chrono::high_resolution_clock::now();

            while (std::getline(tabelle, Zeile)) {

                picosha2::hash256_hex_string(Zeile, hashZeile);

                if (hash == hashZeile) {

                    gefunden = true;

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> laenge = end - start;

                    std::cout << "Es hat " << laenge.count() << " Sekunden gedauert\n";

                    break;
                }

            }

            tabelle.close();

            if (gefunden == true) {

                std::cout << "Passwort gefunden: " << Zeile << std::endl;

            }
            else {

                std::string email = "davidwahab869@gmail.com";
                std::string code = "61f152f62c4a29f6";

                std::string url = "https://md5decrypt.net/en/Api/api.php?hash=" + hash + "&hash_type=sha256&email=" + email + "&code=" + code;


                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laenge = end - start;

                std::cout << "Es hat " << laenge.count() << " Sekunden gedauert\n";

                std::system(("start \"\" \"" + url + "\"").c_str());

                if (APIgefunden == true) {

                    std::cout << "Passwort gefunden!";

                    return;
                }
                else {

                    std::cout << "\nPasswort nicht gefunden\n" << std::endl;

                    char eingabe2;

                    std::cout << "\nMöchtest du BruteForce starten?\n";

                    std::cin >> eingabe2;

                    if (eingabe2 == 'J' || eingabe2 == 'j') {

                        std::cout << "Brute Force wird gestartet... \n" << std::endl;
                        bruteForce(zielHash, typ);
                    }
                    else {
                        return;
                    }
                }

            }


        }
        else {
            std::cout << "Ungültiger Hashwert!" << std::endl;
        }
    }

    // dieser BruteForce code ist nicht optimiert und effozient, er dient einfach nur umd die funktionalität zu zeigen


    // funktion ruft sich selbst immer wieder auf um alle möglichen Kombinationen zu generieren
	// aktuell ist die bisher generierte Kombination
    bool rekursivBruteForce(std::string aktuell, int length, const std::string alphabet, const std::string zielHash, int typ) {
        
        std::string versuchHash;

        if (aktuell.length() == length) {

            if (typ == 32) {

                versuchHash = md5(aktuell);
            }

            else {

                picosha2::hash256_hex_string(aktuell, versuchHash);
            }

            if (versuchHash == zielHash) {

                std::cout << "Brute Force erfolgreich\n" << "Passwort:" << aktuell << std::endl;

                return true;
            }

            return false;
        }

        for (char a : alphabet) {

			// ruft sich selbst auf um zu überpüfen ob die aktuelle Kombination das Passwort ist, wenn nicht wird die nächste Kombination generiert
            if (rekursivBruteForce(aktuell + a, length, alphabet, zielHash, typ)) {

                return true;
            }
        }

        return false;
    }

    void bruteForce(std::string zielHash, int typ) {

        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
        int maxPasswortLaenge = 12;

        std::cout << "Brute Force gestartet... \n";

        for (int i = 1; i <= maxPasswortLaenge; ++i) {

            if (rekursivBruteForce("", i, alphabet, zielHash, typ)) {

                break;
            }
        }
    }
    /*
    void threads() {

        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";

        std::string teil1 = "abcdefghijklmnopqrstuvwxyz";
        std::string teil2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string teil3 = "0123456789";
        std::string teil4 = "!@#$ % ^&*";

        std::thread Thread1(bruteForce, teil1, zielHash, typ);
        std::thread Thread2(bruteForce, teil2, zielHash, typ);
        std::thread Thread3(bruteForce, teil3, zielHash, typ);
        std::thread Thread4(bruteForce, teil4, zielHash, typ);

        Thread1.join();
        Thread2.join();
        Thread3.join();
        Thread4.join();
    }
    */
};

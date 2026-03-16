#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "../../include/picosha2.h"
#include "../../include/md5.h"

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


            while (std::getline(tabelle, Zeile)) {

                hashZeile = md5(Zeile);

                if (hash == hashZeile) {

                    gefunden = true;

                    break;
                }

            }

            tabelle.close();

            if (gefunden == true) {

                std::cout << "Passwort gefunden: " << Zeile << std::endl;

            }
            else {

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
                    std::cout << "Brute Force wird gestartet... \n" << std::endl;

                    bruteForce(zielHash, typ);
                }


            }
        }
        else if (hash.length() == 64) {

            typ = 64;

            std::cout << "Rainbowtable wird geladen...\n";

            std::fstream tabelle("data/list/rockyou.txt");


            while (std::getline(tabelle, Zeile)) {

                picosha2::hash256_hex_string(Zeile, hashZeile);

                if (hash == hashZeile) {

                    gefunden = true;

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


                std::system(("start \"\" \"" + url + "\"").c_str());

                APIgefunden = true;

                if (APIgefunden == true) {

                    std::cout << "Passwort gefunden!";

                    return;
                }
                else {

                    std::cout << "\nPasswort nicht gefunden\n" << std::endl;
                    std::cout << "Brute Force wird gestartet... \n" << std::endl;

                    bruteForce(zielHash, typ);
                }

            }


        }
        else {
            std::cout << "Ungültiger Hashwert!" << std::endl;
        }
    }

    // dieser BruteForce code ist nicht optimiert und effozient, er dient einfach nur umd die funktionalität zu zeigen
   
    void bruteForce(/*std::string alphabet,*/std::string zielHash, int typ) {

        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";

        std::string passwordVersuch;
        std::string versuchHash;

        std::cout << "... \n";

        // 1. Kombination von 1 Zeichen
        // : bedeutet dass a jedes zeichen aus dem alphabet annimmt
        for (char a : alphabet) {

            passwordVersuch = a;

            if (typ == 32) {

                versuchHash = md5(passwordVersuch);
            }
            else {

                picosha2::hash256_hex_string(passwordVersuch, versuchHash);
            }

            if (versuchHash == zielHash) {

                std::cout << "Brute Force erfolgreich\n" << "Passwort:" << passwordVersuch << std::endl;
                return;

            }
        }

        for (char a : alphabet) {

            for (char b : alphabet) {

                passwordVersuch = std::string(1, a) + b;

                if (typ == 32) {

                    versuchHash = md5(passwordVersuch);
                }
                else {

                    picosha2::hash256_hex_string(passwordVersuch, versuchHash);
                }

                if (versuchHash == zielHash) {

                    std::cout << "Brute Force erfolgreich\n" << "Passwort:" << passwordVersuch << std::endl;
                    return;

                }
            }
        }

        for (char a : alphabet) {

            for (char b : alphabet) {

                for (char c : alphabet) {

                    passwordVersuch = std::string(1, a) + b + c;

                    if (typ == 32) {

                        versuchHash = md5(passwordVersuch);
                    }
                    else {

                        picosha2::hash256_hex_string(passwordVersuch, versuchHash);
                    }

                    if (versuchHash == zielHash) {

                        std::cout << "Brute Force erfolgreich\n" << "Passwort:" << passwordVersuch << std::endl;
                        return;

                    }
                }
            }
        }

        for (char a : alphabet) {

            for (char b : alphabet) {

                for (char c : alphabet) {

                    for (char d : alphabet) {

                        passwordVersuch = std::string(1, a) + b + c + d;

                        if (typ == 32) {

                            versuchHash = md5(passwordVersuch);
                        }
                        else {

                            picosha2::hash256_hex_string(passwordVersuch, versuchHash);
                        }

                        if (versuchHash == zielHash) {

                            std::cout << "Brute Force erfolgreich\n" << "Passwort:" << passwordVersuch << std::endl;
                            return;

                        }
                    }
                }
            }
        }

        for (char a : alphabet) {

            for (char b : alphabet) {

                for (char c : alphabet) {

                    for (char d : alphabet) {

                        for (char e : alphabet) {

                            passwordVersuch = std::string(1, a) + b + c + d + e;

                            if (typ == 32) {

                                versuchHash = md5(passwordVersuch);
                            }
                            else {

                                picosha2::hash256_hex_string(passwordVersuch, versuchHash);
                            }

                            if (versuchHash == zielHash) {

                                std::cout << "Brute Force erfolgreich\n" << "Passwort:" << passwordVersuch << std::endl;
                                return;

                            }
                        }
                    }
                }
            }
        }

        for (char a : alphabet) {

            for (char b : alphabet) {

                for (char c : alphabet) {

                    for (char d : alphabet) {

                        for (char e : alphabet) {

                            for (char f : alphabet) {

                                passwordVersuch = std::string(1, a) + b + c + d + e + f;

                                if (typ == 32) {

                                    versuchHash = md5(passwordVersuch);
                                }
                                else {

                                    picosha2::hash256_hex_string(passwordVersuch, versuchHash);
                                }

                                if (versuchHash == zielHash) {

                                    std::cout << "Brute Force erfolgreich\n" << "Passwort:" << passwordVersuch << std::endl;
                                    return;

                                }
                            }
                        }
                    }
                }
            }
        }

        for (char a : alphabet) {

            for (char b : alphabet) {

                for (char c : alphabet) {

                    for (char d : alphabet) {

                        for (char e : alphabet) {

                            for (char f : alphabet) {

                                for (char g : alphabet) {

                                    passwordVersuch = std::string(1, a) + b + c + d + e + f + g;

                                    if (typ == 32) {

                                        versuchHash = md5(passwordVersuch);
                                    }
                                    else {

                                        picosha2::hash256_hex_string(passwordVersuch, versuchHash);
                                    }

                                    if (versuchHash == zielHash) {

                                        std::cout << "Brute Force erfolgreich\n" << "Passwort:" << passwordVersuch << std::endl;
                                        return;

                                    }
                                }
                            }
                        }
                    }
                }
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


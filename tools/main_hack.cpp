#include <iostream>
#include <fstream>
#include <string>
#include <md5.h>

void rainbowTable();
void bruteForce();

void rainbowTable() {

	std::string hash;
	std::string Zeile;
	std::string hashZeile;

	bool gefunden = false;
	bool APIgefunden = false;

	MD5 md5;

	std::cout << "Bitte geben sie ihren Hashwert ein : ";
	std::cin >> hash;

	std::fstream tabelle("data/list/rockyou.txt");


	while (std::getline(tabelle, Zeile)) {

		hashZeile = md5(Zeile);

		if (hash == hashZeile) {

			gefunden = true;

			break;
		}
		
	}

	tabelle.close();

	if(gefunden == true) {

		std::cout << "Passwort gefunden: " << Zeile << std::endl;

	}
	else {

		std::string email = "davidwahab869@gmail.com";
		std::string code = "61f152f62c4a29f6";

		std::string url = "https://md5decrypt.net/en/Api/api.php?hash=" + hash + "&hash_type=md5&email=" + email + "&code=" + code;


		std::system(("start \"\" \"" + url + "\"").c_str());

		if (APIgefunden == true) {

			std::cout << "Passwort gefunden!";

			return;
		}
		else {

			std::cout << "Passwort nicht gefunden" << std::endl;

			//bruteForce();
		}
		

		}
}

void bruteForce() {

    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    
    std::string passwordVersuch , password;

    for (char a : alphabet) {

        passwordVersuch = a;

        if (passwordVersuch == password) {

            std::cout << "Passwort gefunden: " << passwordVersuch << std::endl;

            return;
        }
    }

    // 2. Kombination von 2 Zeichen
    for (char a : alphabet) {

        for (char b : alphabet) {

            // a wird in ein string umgewandelt um es mit b zu verbinden
            passwordVersuch = std::string(1, a) + b;

            if (passwordVersuch == password) {

                std::cout << "Passwort gefunden: " << passwordVersuch << std::endl;

                return;
            }
        }
    }

    // 3. Kombination von 3 Zeichen
    for (char a : alphabet) {

        for (char b : alphabet) {

            for (char c : alphabet) {

                passwordVersuch = std::string(1, a) + b + c;

                if (passwordVersuch == password) {

                    std::cout << "Passwort gefunden: " << passwordVersuch << std::endl;

                    return;
                }
            }
        }
    }

    // 4. Kombination von 4 Zeichen
    for (char a : alphabet) {

        for (char b : alphabet) {

            for (char c : alphabet) {

                for (char d : alphabet) {

                    passwordVersuch = std::string(1, a) + b + c + d;

                    if (passwordVersuch == password) {

                        std::cout << "Passwort gefunden: " << passwordVersuch << std::endl;

                        return;
                    }
                }
            }
        }
    }

    // 5. Kombination von 5 Zeichen
    for (char a : alphabet) {

        for (char b : alphabet) {

            for (char c : alphabet) {

                for (char d : alphabet) {

                    for (char e : alphabet) {

                        passwordVersuch = std::string(1, a) + b + c + d + e;

                        if (passwordVersuch == password) {

                            std::cout << "Passwort gefunden: " << passwordVersuch << std::endl;

                            return;
                        }
                    }
                }
            }
        }
    }

}


int main() {

	rainbowTable();


	return 0;
}

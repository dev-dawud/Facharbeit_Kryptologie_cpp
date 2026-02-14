#include <iostream>
#include <fstream>
#include <string>

void bruteForce() {

    // Das sind alle mögliche Kombinationen die durch gegeangen werden
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	std::string password = "12345";
	std::string passwordVersuch;

    // 1. Kombination von 1 Zeichen
    // : bedeutet dass a jedes zeichen aus dem alphabet annimmt
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


    bruteForce();



    return 0;
}
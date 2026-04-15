#pragma once

#include <iostream>
#include <cmath>

class Entropy {
private:

public:

	void entropy() {

		std::string entrEingabe;

		std::cout << "Geben sie das Passwort ein was sie testen möchten: ";
		std::cin >> entrEingabe;

		berechneEntropy(entrEingabe);
	}

	void berechneEntropy(std::string entropyEingabe) {

		// vereinfachte Formel von Shannon: H = n * log2(s)
		// entropy ist das resultierende Maß der Stärke vom Passwort in bits
		// s ist die Anzahl der möglichen Zeichen die im Passwort auftreten können
		// n ist die Länge des Passworts
		// genauere Erklärung dazu in 2.1 "Grundlagen der Passwortsicherheit" der Facharbeit
		double entropy = 0.0;
		int s = 96;
		int n = entropyEingabe.length();

		entropy = n * log2(s);

		std::cout << "Die Entropie des Passworts beträgt: " << entropy << " bits" << std::endl;

		if (entropy < 24) {

			std::cout << "Das Passwort ist sehr schwach." << std::endl;
		}
		else if (entropy < 49) {

			std::cout << "Das Passwort ist schwach." << std::endl;
		}
		else if (entropy < 74) {

			std::cout << "Das Passwort ist akzeptabel." << std::endl;
		}
		else if (entropy < 100) {

			std::cout << "Das Passwort ist stark." << std::endl;
		}
		else if (entropy >= 100) {

			std::cout << "Das Passwort ist sehr stark." << std::endl;
		}

	}
};
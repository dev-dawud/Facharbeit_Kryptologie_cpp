#pragma	once

#include <iostream>
#include <fstream>

class RainbowTable {
public:

	void rainbowTable() {

		// Für die API muss man die dazugehörige E-Mail und den personalisieren Code eingeben in der URL
		std::string email = "davidwahab869@gmail.com";
		std::string code = "61f152f62c4a29f6";

		std::string hash;

		std::cout << "Bitte gib denn Hash ein: ";
		std::cin >> hash;

		// Hier wird die API genutzt um den Hash zu entschlüsseln
		std::string url = "https://md5decrypt.net/en/Api/api.php?hash=" + hash + "&hash_type=md5&email=" + email + "&code=" + code;

		// da die URL sonderzeichen hat muss man diese in " setzen damit der Link klappt
		std::system(("start \"\" \"" + url + "\"").c_str());

	}
};

#include <iostream>


void RainbowTable() {

	std::string email = "davidwahab869@gmail.com";
	std::string code = "61f152f62c4a29f6";
	std::string hash;

	std::cout << "Bitte gib denn Hash ein: ";
	std::cin >> hash;

	std::string url = "https://md5decrypt.net/en/Api/api.php?hash=" + hash + "&hash_type=md5&email=" + email + "&code=" + code;

	// \"\"\"" braucht man wenn meine urkl sonderzeichen wie & hat
	// c_str() wandelt sozusagen den url der ist ja moderne c++ in das veraltetet c string um da system() nur c string akzeptiert
	std::system(("start \"\" \"" + url + "\"").c_str());
	
}

int main() {

	RainbowTable();

	return 0;
}
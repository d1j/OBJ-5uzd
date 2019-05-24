#include <iostream>
#include <fstream>
#include <limits>
#include "task.h"

int int_ivestis() {
	int kint;
	while (!(std::cin >> kint)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nIvesta bloga reiksme. Iveskite reiksme is naujo: ";
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return kint;
}

bool ar_failas_egzistuoja(std::string pav) {
	std::ifstream in(pav);
	bool retVal = in.good();
	in.close();
	return retVal;
}

int main() {
	task obj;
	int pasirink;
	bool power = true;
	std::string in;
	while (power) {
		std::cout << "1. Pasikartojanciu zodziu paieska.\n2. Pasikartojanciu zodziu paieska eilutese\n3. URL adresu paieska\n4. Iseiti\n:";
		pasirink = int_ivestis();
		while (pasirink < 1 || pasirink > 4) {
			pasirink = int_ivestis();
		}
		std::cout << "Ivesties failas: "; std::cin >> in;
		while (!ar_failas_egzistuoja("./duom/" + in)) {
			std::cout << "Failas neegzistuoja. Iveskite tinkama pavadinima: "; std::cin >> in;
		}
		switch (pasirink) {
		case 1:
			obj.scanFile_1(in);
			break;
		case 2:
			obj.scanFile_2(in);
			break;
		case 3:
			obj.scanFile_3(in);
			break;
		case 4:
			power = false;
			break;
		default:
			break;
		}
		if (pasirink != 4)
			std::cout << "\nRezultatai isvesti i: ./rez/" << in.substr(0, in.find(".")) << "_" << pasirink << ".txt" << std::endl << std::endl;
	}

	return 0;
}
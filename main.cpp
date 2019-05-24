#include <iostream>
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

int main() {
	task obj;
	int pasirink;
	bool power = true;
	std::string in;
	while (power) {
		std::cout << "1. Skaiciuoti zodzius\n2. Skaiciuoti zodzius ir eilutes\n3. Rasti URL adresus\n4. Iseiti\n:";
		pasirink = int_ivestis();
		while (pasirink < 1 || pasirink > 4) {
			pasirink = int_ivestis();
		}
		std::cout << "Ivesties failas: "; std::cin >> in;
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
		std::cout << "\nRezultatai isvesti i: ./rez/" << in << std::endl << std::endl;
	}

	return 0;
}
#include "task.h"

#include <fstream>
#include <iostream>
#include <algorithm>

//32 - space
//39 - '
//65-90 - A-Z
//97-122 - a-z

static bool pred(const char& c) {
	bool first = false;
	bool second = false;

	if ((c >= 64 && c <= 90) || (c >= 97 && c <= 122) || c == 32) {
		return false;
	} return true;
}

void task::processLine_1(std::string line) {
	line.erase(std::remove_if(line.begin(), line.end(), pred), line.end());
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	while (line.length() != 0) {
		auto pos = line.find(' ');
		if (pos == std::string::npos) {
			if (wordsCount.find(line) == wordsCount.end())
				wordsCount[line] = 1;
			else
				wordsCount[line]++;
			line.clear();
		} else {
			auto sub = line.substr(0, pos);
			if (wordsCount.find(sub) == wordsCount.end())
				wordsCount[sub] = 1;
			else
				wordsCount[sub]++;
			line.erase(0, pos);
			while (line[0] == ' ') {
				line.erase(0, 1);
			}
		}
	}
}

void task::scanFile_1(const std::string& in, const std::string& out) {
	std::ifstream input("./duom/" + in);
	while (!input.eof()) {
		std::string a;
		std::getline(input, a);
		processLine_1(a);
	}
	input.close();

	writeResults_1(out);

	clearObject();
}

void task::writeResults_1(const std::string& out) {
	std::ofstream output("./rez/" + out);
	for (auto p = wordsCount.begin(); p != wordsCount.end(); p++)
		if (p->second > 1)
			output << p->first << ": " << p->second << std::endl;
	output.close();
}

void task::processLine_2(std::string line) {

}

void task::processLine_3(std::string line) {

}

void task::scanFile_2(const std::string& in, const std::string& out) {

}

void task::scanFile_3(const std::string& in, const std::string& out) {

}

void task::writeResults_2(const std::string& out) {

}

void task::writeResults_3(const std::string& out) {

}

void task::clearObject() {
	wordsCount.clear();
	occurranceAtLines.clear();
}
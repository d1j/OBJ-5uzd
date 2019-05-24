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
			myErase(line, pos);
		}
	}
}

void task::scanFile_1(const std::string& in) {
	std::string out = in;
	out = out.substr(0, out.find("."));
	out = out + "_1.txt";

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

void task::processLine_2(std::string line, const int& count) {
	line.erase(std::remove_if(line.begin(), line.end(), pred), line.end());
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	while (line.length() != 0) {
		auto pos = line.find(' ');
		if (pos == std::string::npos) {
			if (wordsCount.find(line) == wordsCount.end())
				wordsCount[line] = 1;
			else
				wordsCount[line]++;
			if (occurranceAtLines.find(line) == occurranceAtLines.end()) {
				occurranceAtLines[line].push_back(count);
			} else {
				if (occurranceAtLines[line].back() != count)
					occurranceAtLines[line].push_back(count);
			}
			line.clear();
		} else {
			auto sub = line.substr(0, pos);
			if (wordsCount.find(sub) == wordsCount.end())
				wordsCount[sub] = 1;
			else
				wordsCount[sub]++;
			myErase(line, pos);
			if (occurranceAtLines.find(sub) == occurranceAtLines.end()) {
				occurranceAtLines[sub].push_back(count);
			} else {
				if (occurranceAtLines[sub].back() != count)
					occurranceAtLines[sub].push_back(count);
			}

		}
	}
}

void task::scanFile_2(const std::string& in) {
	std::string out = in;
	out = out.substr(0, out.find("."));
	out = out + "_2.txt";

	std::ifstream input("./duom/" + in);
	int count = 1;
	while (!input.eof()) {
		std::string a;
		std::getline(input, a);
		processLine_2(a, count++);
	}
	input.close();

	writeResults_2(out);

	clearObject();
}

void task::writeResults_2(const std::string& out) {
	std::ofstream output("./rez/" + out);
	auto q = occurranceAtLines.begin();
	for (auto p = wordsCount.begin(); p != wordsCount.end(); p++) {
		if (p->second > 1) {
			output << p->first  <<  " || eilutes: ";
			for (auto i = 0; i < q->second.size(); ++i) {
				output << q->second[i] << " ";
			}
			output << std::endl;
		}
		q++;
	}
	output.close();
}

void task::processLine_3(std::string line) {
	std::vector<std::string> mas = {"https", "www", "http"};
	for (auto i = 0; i < mas.size(); ++i) {
		while (line.find(mas[i]) != std::string::npos && line.length() != 0) {
			auto pos = line.find(mas[i]);
			myErase(line, pos);
			if (line.find(" ") == std::string::npos) {
				url.push_back(line);
				line.clear();
			} else {
				auto end_pos = line.find(" ");
				url.push_back(line.substr(0, end_pos));
				myErase(line, end_pos);
			}
		}
	}
}

void task::scanFile_3(const std::string& in) {
	std::string out = in;
	out = out.substr(0, out.find("."));
	out = out + "_3.txt";

	std::ifstream input("./duom/" + in);
	while (!input.eof()) {
		std::string a;
		std::getline(input, a);
		processLine_3(a);
	}
	input.close();

	writeResults_3(out);

	clearObject();
}

void task::writeResults_3(const std::string& out) {
	std::ofstream output("./rez/" + out);
	for (auto i = 0; i < url.size(); ++i) {
		output << url[i] << std::endl;
	}
	output.close();
}

void task::clearObject() {
	wordsCount.clear();
	occurranceAtLines.clear();
	url.clear();
}

void task::myErase(std::string& line, unsigned int& end) {
	line.erase(0, end);
	while (line[0] == ' ') {
		line.erase(0, 1);
	}
}
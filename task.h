#ifndef TASK_H
#define TASK_H

#include <map>
#include <vector>
#include <string>

class task {
private:
	std::map<std::string, unsigned int> wordsCount;
	std::map<std::string, std::vector<int>> occurranceAtLines;

	void processLine_1(std::string);
	void processLine_2(std::string, const int&);
	void processLine_3(std::string);

	void writeResults_1(const std::string&);
	void writeResults_2(const std::string&);
	void writeResults_3(const std::string&);

	void clearObject();

public:
	task() {}
	~task() {}

	void scanFile_1(const std::string&);
	void scanFile_2(const std::string&);
	void scanFile_3(const std::string&);
};

#endif
#include "StringUtils.h"

void azr::StringUtils::split(const string &s, char delim, vector<string> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

void azr::StringUtils::readFile(std::string path, std::string& target) {
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	target = buffer.str();
}

vector<string> azr::StringUtils::split(const string &s, char delim) {
	vector<string> elems;
	azr::StringUtils::split(s, delim, elems);
	return elems;
}

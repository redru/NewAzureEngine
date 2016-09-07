#include "StringUtils.h"

void azr::StringUtils::split(const string &s, char delim, vector<string> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

vector<string> azr::StringUtils::split(const string &s, char delim) {
	vector<string> elems;
	azr::StringUtils::split(s, delim, elems);
	return elems;
}

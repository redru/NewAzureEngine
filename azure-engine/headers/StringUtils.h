#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

namespace azr {

	class StringUtils {

	public:
		static vector<string> azr::StringUtils::split(const string &s, char delim);
		static void readFile(std::string path, std::string& target);

	private:
		static void azr::StringUtils::split(const string &s, char delim, vector<string> &elems);

	};

}

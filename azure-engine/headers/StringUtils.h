#pragma once
#include <string>
#include <sstream>
#include <vector>

using namespace std;

namespace azr {

	class StringUtils {

	public:
		static vector<string> azr::StringUtils::split(const string &s, char delim);

	private:
		static void azr::StringUtils::split(const string &s, char delim, vector<string> &elems);

	};

}

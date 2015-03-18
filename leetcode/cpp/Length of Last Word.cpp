#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
	int lengthOfLastWord(const char *s) {
		stringstream is(s);
		string str;
		while (is >> str);
		return str.length();
	}
};

int main(int argc, char **argv)
{
	char str[] = "";
	Solution s;
	cout << s.lengthOfLastWord(str) << endl;

	return 0;
}

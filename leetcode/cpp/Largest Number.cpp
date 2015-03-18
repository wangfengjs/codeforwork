#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	string ab, ba;
	stringstream ostream;
	
	ostream << a << b;
	ostream >> ab;

	ostream.clear();
	ostream << b << a;
	ostream >> ba;

	return ab > ba;
}

class Solution {
public:
	string largestNumber(vector<int> &num) {
		string res, tmp;
		stringstream ostream;
		sort(num.begin(), num.end(),cmp);
		for (int i=0; i<num.size(); i++)
		{
			if (num.at(i) == 0 && i==0 && num.size()>1)
			{
				continue;
			}
			ostream << num.at(i);
		}
		ostream >> res;

		if (res[0] == '0' && res.length()>1)
		{
			res.erase(res.begin()+1, res.end());
		}
		return res;
	}
};


int main(int argc, char **argv)
{
	Solution s;
	int array[] = {824,938,1399,5607,6973,5703,9609,4398,8247};
	vector<int> num(array, array+9);
	
	cout << s.largestNumber(num) << endl;
	return 0;
}

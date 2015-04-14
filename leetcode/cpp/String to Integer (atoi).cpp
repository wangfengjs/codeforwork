#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long res = 0;
		bool sign = false;
		int j=0;

		if (str.empty())
		{
			return res;
		}

		// Ïû³ýÇ°µ¼0
		while (str[j] == ' ')
			j++;

		if (str[j] == '-')
		{
			sign = true;
			j++;
		}
		else if (str[j] =='+')
		{
			j++;
		}

		for (int i=j; i<str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9' )
			{
				res = res*10 + str[i] - '0';
			}
			else
			{
				break;
			}

			if (sign&&res > 2147483648)
			{
				res = 2147483648;
				break;
			}
			else if (!sign && res > 2147483647)
			{
				res = 2147483647;
				break;
			}
		}

		if (sign)
		{
			res = -res;
		}

		return res;
	}
};

int main()
{
	string str = "-2147483648";
	Solution s;
	cout << s.myAtoi(str) << endl;
	return 0;
}
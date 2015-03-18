#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		int len_a = a.length();
		int len_b = b.length();
		int loop = min(len_a, len_b);
		int inc = 0;

		for (int i=0; i<loop; i++)
		{
			res.insert(0, 1, a[len_a-1-i]^b[len_b-1-i]^inc + 48);

			inc = ((a[len_a-1-i]-48)&(b[len_b-1-i]-48)) | ((a[len_a-1-i]^b[len_b-1-i])&inc);
		}

		if (loop < len_a)
		{
			for (int i=loop; i<len_a; i++)
			{
				res.insert(0, 1, a[len_a-1-i]^inc);
				inc = a[len_a-1-i]&inc;
			}
		}
		else if(loop < len_b)
		{
			for (int i=loop; i<len_b; i++)
			{
				res.insert(0, 1, b[len_b-1-i]^inc);
				inc = b[len_b-1-i]&inc;
			}
		}

		if (inc)
		{
			res.insert(0, 1,'1');
		}
		return res;
	}
};

int main(int argc, char **argv)
{
	string a, b;
	a = "0", b="0";
	
	Solution s;
	cout << s.addBinary(a, b) << endl;
	return 0;
}

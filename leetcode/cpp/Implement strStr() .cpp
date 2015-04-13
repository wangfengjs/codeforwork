#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int success = -1;

		if (needle == "")
		{
			return 0;
		}

		for (int i=0, start=0, end = needle.size()-1; i<haystack.size(); i++)
		{
			while (start <= end && haystack[i+start] == needle[start] && haystack[i+end] == needle[end])
			{
				start++;
				end--;
			}

			if (start > end)
			{
				success = i;
				return success;
			}
			else
			{
				start = 0;
				end = needle.size()-1; 
			}
		}

		return success;
	}
};

int main()
{
	string haystack = "mississippimissp", needle = "missp";
	Solution s;
	cout << s.strStr(haystack, needle) << endl;
	return 0;
}
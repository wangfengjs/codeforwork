#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

void insert(string &str, int k, int c)
{
	str.insert(k, 1, c);
	
	int len;
	while (true)
	{
		int i;
		len = 1;
		for (i=k+1; i<str.length() && str[i] == str[i-1]; i++) len++;
		//len += i-k;

		for (i=k-1; i>=0 && str[i] == str[i+1]; i--) len++;
		//len += k-i;
		//len--;

		if (len > 2)
		{
			//Ïû³ý²Ù×÷
			str.erase(i+1, len);
			k = i+1;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	
	char s[10001];
	gets(s);
	string str(s);
	//cin >> str;

	int n;
	scanf("%d", &n);
	getchar();

	int k;
	char c;
	for (int i=0; i<n; i++)
	{

		scanf("%d %c", &k, &c);
		insert(str, k, c);
		if (str.empty())
		{
			printf("-\n");
			continue;
		}
		puts(str.c_str());
		//cout << str << endl;
	}
}
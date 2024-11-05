#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;
int record[27],maxn,num;

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		getline(cin, str);
		for (int j = 1; j <= str.size(); j++)
		{
			if(str[j]<='Z'&&str[j]>='A')
			record[str[j] - 64]++;
		}
	}
	for (int i = 1; i <= 26; i++)
	{
		if (record[i] > maxn) { maxn = record[i]; }
    }
	for (int i = maxn; i >= 1; i--)
	{
		for (int j = 1; j <= 26; j++)
		{
			if (record[j] >= i) { printf("*"); if (j != 26) cout << " "; }
			else { printf(" "); if (j != 26)cout << " "; }
			num++;
		}
		if(num!=maxn)printf( "\n");
	}
	for (char i = 65; i <= 90; i++)
	{
		cout << i; if (i != 90)cout << " ";
	}
	return 0;
}
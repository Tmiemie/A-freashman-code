#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str1, str2;
int num=0,j=-1;
int main()
{                    
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 0; i < str1.size(); i++) { if (str1[i] >= 'A' && str1[i] <= 'Z')str1[i] += 32; }
	for (int i = 0; i < str2.size(); i++) { if (str2[i] >= 'A' && str2[i] <= 'Z')str2[i] += 32; }
	auto pos = str2.find(str1);
    while (  pos != string::npos) 
	{
		if ((str2[pos + str1.size()] == ' ') && (str2[pos - 1] == ' ' || pos == 0))
		{
			num++;
			if (num == 1) { j = pos; }
		}
			pos = str2.find(str1, pos + 1);
	} 
	if (num == 0)cout << -1;
	else cout << num<<" " << j;
	return 0;
}
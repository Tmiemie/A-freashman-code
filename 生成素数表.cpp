#include<iostream>
#include<vector>
using namespace std;
int x;
	

int main()
{
	cin >> x;
	vector<bool>prime(x + 1, 1);
	prime[1] = prime[0] = 0;
	for (int i = 2; i * i <= x; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= x; j += i)
			{
				prime[j] = 0;
			}
		}
	}
	for (int i = 0; i <= x; i++)
	{
		if (prime[i])
			cout << i << " ";
	}


	return 0;
}

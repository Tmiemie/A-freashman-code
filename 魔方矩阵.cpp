#include<iostream>
using namespace std;
int n,x,y;
int a[40][40];
int main()
{
	cin >> n;
	a[x=1][y=n / 2 + 1] = 1;
	for (int k = 2; k <= n * n; k++)
	{
		if (x == 1 && y != n)a[x=n][++y] = k;
		else if (y == n && x != 1)a[--x][y=1] = k;
		else if(x==1&&y==n)a[++x][y] = k;
		else if(x!=1&&y!=n&&a[x-1][y+1]==0)a[--x][++y] = k;
		else if(x!=1&&y!=n&&a[x-1][y+1]!=0)a[++x][y] = k;


	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


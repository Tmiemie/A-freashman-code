#include<iostream>
using namespace std;
int n;
int a[21][21];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i][i] = 1, a[i][1] = 1;
    }
    for (int j = 3; j <= n; j++) {
        for (int k = 2; k < j; k++)
        {
            a[j][k] = a[j - 1][k - 1] + a[j - 1][k];
        }

    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;

    }
    return 0;
}
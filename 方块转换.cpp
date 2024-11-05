#include<iostream>
using namespace std;
int n, i, j, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0;
char a[11][11];
char b[11][11];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[i][j] == a[j][n - i + 1]) num1++;
             if (b[i][j] == a[n - i + 1][n - j + 1]) num2++;
            if (b[i][j] == a[n - j + 1][i]) num3++;
            if (b[i][j] == a[i][n - j + 1]) num4++;
             if (b[i][j] == a[n - j + 1][n - i + 1]) num5++;
             if (b[i][j] == a[n - i + 1][j]) num6++;
             if (b[i][j] == a[j][i]) num7++;
            if (b[i][j] == a[i][j]) num8++;
        }
    }
    int minOp = 7;
    if (num1 == n * n) minOp = 1;
    else if (num2 == n * n) minOp = 2;
    else if (num3 == n * n) minOp = 3;
    else if (num4 == n * n) minOp = 4;
    else if (num5 == n * n || num6 == n * n || num7 == n * n) minOp = 5; // 情况5包括num5、num6和num7
    else if (num8 == n * n) minOp = 6;

    cout << minOp;
    return 0;
}
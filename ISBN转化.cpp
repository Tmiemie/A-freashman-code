#include<iostream>
using namespace std;
int a,b=1,c;
char d[14];
int main(){
    for (int i = 1; i <= 13; i++) { cin >> d[i]; }
    for (int i = 1; i <= 11; i++) {
        if (d[i] != '-') { c += (d[i] - '0') * b; b++; }
    }
    c %= 11;
    if (c == d[13] - '0')cout << "Right";
    else if (c == 10 && d[13] == 'X')cout << "Right";
    else {
        for (int i = 1; i <= 12; i++) {
            cout << d[i];
        }
        if (c != 10)
            cout << c;
        else cout << "X";
    }
    return 0;
}
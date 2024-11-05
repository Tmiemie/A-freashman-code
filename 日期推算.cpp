#include<iostream>
#include <string>
using namespace std;
string str;
int l, n, t;
int y, m, d;
bool year(int x)
{
	return ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
}
 void function ()
 {
	 switch (m)
	 {
	 case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		 t = 31; break;
	 case 4:case 6:case 9:case 11:
		 t = 30; break;
	 case 2:
		 if (year(y)) { t = 29; break; }
		 else { t = 28; break; }
	 case 13:
		 y++; m = 1; t = 31; break;
	 }
}


int main()
{
	    ios::sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
		cin >> str >> n;
		y = stoi(str.substr(0, 4));
		m = stoi(str.substr(4, 2));
		d = stoi(str.substr(6, 2));
	
		while (n != 0)
		{
			function();
			if (t <= n)
			{
				m++;
				n -= t;
			}
			else
			{
				if (d + n > t)m++;
				if (m == 13) { m = 1, y++; }
				d = (d + n) % t;
				if (d == 0)d = t;
				n = 0;
			}

		}

		if (y > 9999)
		{
			cout << "out of limitation!";
		}
		else 
		{
			if (y >= 1000)cout << y;
		     if (y<1000&&y >= 100)cout << 0 << y;
			 if (y >= 10&&y<100)cout << 00 << y;
			 if (y > 0&&y<10)cout << 000 << y;
			 if (y == 0)cout << 0000;
			if (m >= 10)cout << m;
			if (m < 10)cout << 0 << m;
			if (d >= 10)cout << d;
			if (d < 10)cout << 0 << d;
		}
		return 0;
}
#include<iostream>
#include<iomanip>
using namespace std;

class Time
{
public:
	Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
	void input(void)
	{
		cin >> hour >> minute >> second;
	}

	void jia(Time c)
	{
		Time d;
		d.second= second + c.second;
		d.minute= minute + c.minute;
		d.hour = hour+c.hour;
		while (d.second >= 60)
		{
			d.second -= 60;
			d.minute++;
		}
		while (d.minute >= 60)
		{
			d.minute -= 60;
			d.hour++;
		}
		while (d.hour >= 24)
		{
			d.hour -= 24;
		}

		cout << setfill('0') << setw(2) << d.hour;
		cout<<":"<< setfill('0') << setw(2) << d.minute;
		cout<<":"<< setfill('0') << setw(2) << d.second;

	}
	void jian(Time c)
	{
		Time d;
		d.second += second - c.second;
		if (d.second < 0)
		{
			d.second += 60;
			minute--;
		}
		d.minute += minute - c.minute;
		if (d.minute < 0)
		{
			d.minute += 60;
			hour--;
		}
		d.hour += hour - c.hour;
		if (d.hour < 0)
		{
			d.hour += 24;
		}

		cout << setfill('0') << setw(2) << d.hour;
		cout << ":" << setfill('0') << setw(2) << d.minute;
		cout << ":" << setfill('0') << setw(2) << d.second;
	}


private:
	int hour, minute, second;
};
int main()
{
	Time aa, bb;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	aa.input();
	bb.input();
	aa.jia(bb);
	cout << "\n";
	aa.jian(bb);
	return 0;
}
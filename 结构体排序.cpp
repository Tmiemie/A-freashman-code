#include<iostream>
#include<algorithm>
using namespace std;
struct student
{
	string name;
	int chine;
	int math;
	int engli;
	int score;
}people[1025];

int n, k;
bool cmp(student a, student b)
{
	if(a.score != b.score) return a.score > b.score; 
	else if (a.chine != b.chine)return a.chine > b.chine;
	else if (a.math != b.math)return a.math > b.math;
	else if (a.engli != b.engli)return a.engli > b.engli;
	else if (a.name != b.name)return a.name < b.name;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> people[i].name >> people[i].chine >> people[i].math >> people[i].engli;
		people[i].score = people[i].chine + people[i].math + people[i].engli;
	}
	cin >> k;
	sort(people , people + n , cmp);
		cout << people[k-1].name << " " << people[k-1].score;
		return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int N, T;
double V;

struct box
{
	double w;
	double v;
	double x;
}a[101];

bool cmp(box a, box b) { return a.x > b.x; }

int main()
{
	cin >> N >> T;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i].w >> a[i].v;
		a[i].x = a[i].v / a[i].w;
	}
	sort(a + 1, a + N + 1, cmp);
	for (int i = 1; i <= N; i++)
	{
		if (T > a[i].w) { T -= a[i].w; V += a[i].v; }
		else { V += (T * a[i].x); break; }
	}
	printf("%.2lf", V);
	return 0;
}
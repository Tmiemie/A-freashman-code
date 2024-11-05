#include<iostream>
#include<vector>
using namespace std;
int n, d, u, v, b[100005], num;
vector<int> a[100005];
void dfs(int now, int dis)
{
	b[now] = 1;
	if (dis == d) { return; }
	for (int i = 0; i < a[now].size(); i++)
	{
		if (b[a[now][i]] != 1)
		{
			dfs(a[now][i], dis + 1);
			num++;
		}
	}
}
int main()
{
	cin >> n >> d;
	for (int i = 1; i < n; i++) { cin >> u >> v; a[u].push_back(v); a[v].push_back(u); }
	dfs(1, 0);
	cout << num;
	return 0;
}
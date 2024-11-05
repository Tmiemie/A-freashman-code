#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int record1[100001],record2[100001],n,m;
vector <int> a[100001];

void dfs(int x)
{
	record1[x] = 1;
	cout << x << " ";
	for (int i = 0; i < a[x].size(); i++)
	{
		if (!record1[a[x][i]]) { dfs(a[x][i]); }
	}
}

void bfs(int x)
{
	queue <int> b;
	b.push(x); 
	record2[x] = 1;
	while (!b.empty())
	{
		int s = b.front(); b.pop();
		cout << s << " ";
		for (int i = 0; i < a[s].size(); i++)
		{
			if (!record2[a[s][i]]) 
			{
				record2[a[s][i]] = 1;
				b.push(a[s][i]);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		
	}
	for (int i = 1; i <= n; i++) sort(a[i].begin(), a[i].end());
		dfs(1);
		cout << endl;
		bfs(1);
	return 0;
}
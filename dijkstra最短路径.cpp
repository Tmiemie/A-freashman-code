#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> graph;
vector<int> dijkstra(int start, int n) {
    vector<int> dist(n, 1e9);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : graph[u]) {
            int v = edge.first; 
            int w = edge.second; 
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
    return dist;
}
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    vector<int> distances = dijkstra(s, n + 1);
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << distances[i];
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    int n, m;
    cin >> n >> m; 
    vector<pair<int,int>> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  
    }

    int src;
    cin >> src;  

    vector<int> dist(n+1, INF);
    vector<bool> vis(n+1, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if(!vis[adjNode] && dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << "Distance from " << src << " to " << i << " = " << dist[i] << endl;
    }

    return 0;
}
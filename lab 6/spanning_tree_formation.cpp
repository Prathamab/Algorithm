//spanning tree formation-->ensure that no cycle is present in my result 

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;
        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;}
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for(int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v;
    }
    DSU dsu(n);
    vector<Edge> result;

    for(int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if(dsu.findParent(u) != dsu.findParent(v)) {
            result.push_back(edges[i]);
            dsu.unionByRank(u, v);
        }
    }

    cout << "Edges in Spanning Tree:\n";
    for(auto e : result) {
        cout << e.u << " - " << e.v << endl;
    }
    return 0;
}


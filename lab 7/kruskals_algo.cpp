#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), cmp);

    DisjointSet ds(n);

    int mstWeight = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            ds.unite(e.u, e.v);
            mst.push_back(e);
            mstWeight += e.weight;
        }
    }

    cout << "\nEdges in MST:\n";
    for (auto &e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}
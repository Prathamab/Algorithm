#include <bits/stdc++.h>
using namespace std;

#define INF 999

void prims(int cost[][100], int n, int t[][2]) {
    int near[100];
    int u = 0, v = 0, min = INF;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[0][1] = v;

    near[u] = 0;
    near[v] = 0;

    for (int i = 1; i <= n; i++) {
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        } }

    for (int i = 1; i < n - 1; i++) {
        min = INF;
        int k = 0;

        for (int j = 1; j <= n; j++) {
            if (near[j] != 0 && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                k = j;
            } }
        t[i][0] = k;
        t[i][1] = near[k];
        near[k] = 0;

        for (int j = 1; j <= n; j++) {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int cost[100][100];

    cout << "Enter cost adjacency matrix (use 999 for no edge):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }  }
    int t[100][2];  

    prims(cost, n, t);

    cout << "\nEdges in Minimum Spanning Tree:\n";
    int totalCost = 0;

    for (int i = 0; i < n - 1; i++) {
        cout << t[i][0] << " - " << t[i][1] 
             << "  (Cost: " << cost[t[i][0]][t[i][1]] << ")" << endl;
        totalCost += cost[t[i][0]][t[i][1]];
    }

    cout << "\nTotal Minimum Cost = " << totalCost << endl;

    return 0;
}
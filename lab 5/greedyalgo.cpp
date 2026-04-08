#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;
};

bool compareProfit(Item a, Item b) {
    return a.profit > b.profit;
}

bool compareWeight(Item a, Item b) {
    return a.weight < b.weight;
}

bool compareRatio(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

int solve(vector<Item> items, int capacity) {
    int totalProfit = 0;
    int totalWeight = 0;

    cout << "Selected items:\n";

    for (int i = 0; i < items.size(); i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalProfit += items[i].profit;

            cout << "Profit: " << items[i].profit
                 << " Weight: " << items[i].weight << endl;
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
    return totalProfit;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter profit and weight:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
    }

    cout << "Enter max capacity: ";
    cin >> capacity;

    // Greedy by Profit
    cout << "\nGreedy by Profit\n";
    vector<Item> temp1 = items;
    sort(temp1.begin(), temp1.end(), compareProfit);
    int profit1 = solve(temp1, capacity);

    // Greedy by Weight
    cout << "\nGreedy by Weight\n";
    vector<Item> temp2 = items;
    sort(temp2.begin(), temp2.end(), compareWeight);
    int profit2 = solve(temp2, capacity);

    // Greedy by Profit/Weight Ratio
    cout << "\nGreedy by Ratio\n";
    vector<Item> temp3 = items;
    sort(temp3.begin(), temp3.end(), compareRatio);
    int profit3 = solve(temp3, capacity);

    // Find best
    int bestProfit = max({profit1, profit2, profit3});

    cout << "Best Profit Among 3 Methods: " << bestProfit << endl;

    if (bestProfit == profit1)
        cout << "Best method: Greedy by Profit\n";
    else if (bestProfit == profit2)
        cout << "Best method: Greedy by Weight\n";
    else
        cout << "Best method: Greedy by Ratio\n";

    return 0;
    
}

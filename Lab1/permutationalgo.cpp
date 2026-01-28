#include <iostream>
#include <ctime>
using namespace std;

void permute(char a[], int l, int r) {
    if (l == r) return;
    for (int i = l; i <= r; i++) {
        swap(a[l], a[i]);
        permute(a, l + 1, r);
        swap(a[l], a[i]);
    }
}

int main() {
    cout << "n\tAverageTime(seconds)\n";

    for (int n = 1; n <= 10; n++) {
        char arr[10];
        for (int i = 0; i < n; i++)
            arr[i] = 'A' + i;

        double totalTime = 0;

        for (int k = 0; k < 100; k++) {
            clock_t start = clock();
            permute(arr, 0, n - 1);
            clock_t end = clock();
            totalTime += double(end - start) / CLOCKS_PER_SEC;
        }

        cout << n << "\t" << totalTime / 100 << endl;
    }
    return 0;
}

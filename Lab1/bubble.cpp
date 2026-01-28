#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    srand(time(0));
    cout << "InputSize\tAverageTime(seconds)\n";

    for (int n = 1000; n <= 20000; n += 1000) {
        double totalTime = 0;

        for (int k = 0; k < 100; k++) {
            int *arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = rand();

            clock_t start = clock();
            bubbleSort(arr, n);
            clock_t end = clock();

            totalTime += double(end - start) / CLOCKS_PER_SEC;
        }

        cout << n << "\t\t" << totalTime / 100 << endl;
    }
    return 0;
}

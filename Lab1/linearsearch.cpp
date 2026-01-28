#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Linear Search Function
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    srand(time(0));

    cout << "InputSize\tAverageTime(seconds)\n";

    // Input sizes from 1000 to 20000
    for (int n = 1000; n <= 20000; n += 1000) {

        double totalTime = 0.0;

        // Repeat 100 times
        for (int r = 0; r < 100; r++) {

            int *arr = new int[n];

            // Fill array with random numbers
            for (int i = 0; i < n; i++)
                arr[i] = rand();

            int key = arr[n - 1];  // Worst-case search

            clock_t start = clock();
            linearSearch(arr, n, key);
            clock_t end = clock();

            totalTime += double(end - start) / CLOCKS_PER_SEC;
        }

        double averageTime = totalTime / 100.0;
        cout << n << "\t\t" << averageTime << endl;
    }

    return 0;
}

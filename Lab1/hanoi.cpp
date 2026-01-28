#include <iostream>
#include <ctime>
using namespace std;

void Toh(int n, char F, char U, char T) {
    if (n == 0) return;
    Toh(n - 1, F, T, U);
    Toh(n - 1, U, F, T);
}

int main() {
    cout << "Disks\tAverageTime(seconds)\n";

    for (int n = 1; n <= 20; n++) {   // exponential growth
        double totalTime = 0.0;

        for (int i = 0; i < 100; i++) {
            clock_t start = clock();
            Toh(n, 'F', 'U', 'T');
            clock_t end = clock();
            totalTime += double(end - start) / CLOCKS_PER_SEC;
        }

        cout << n << "\t" << totalTime / 100 << endl;
    }
    return 0;
}

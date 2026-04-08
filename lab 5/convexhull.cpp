#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

double orientation(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - 
           (B.y - A.y) * (C.x - A.x);
}

bool insideTriangle(const Point &A, const Point &B, 
                    const Point &C, const Point &P) {

    double o1 = orientation(A, B, P);
    double o2 = orientation(B, C, P);
    double o3 = orientation(C, A, P);
#
    bool hasPos = (o1 > 0) || (o2 > 0) || (o3 > 0);
    bool hasNeg = (o1 < 0) || (o2 < 0) || (o3 < 0);

    return !(hasPos && hasNeg);
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);

    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<bool> extreme(n, true);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            if (j == i) continue;

            for (int k = j + 1; k < n; k++) {
                if (k == i) continue;

                for (int l = k + 1; l < n; l++) {
                    if (l == i) continue;

                    if (insideTriangle(points[j], 
                                       points[k], 
                                       points[l], 
                                       points[i])) {
                        extreme[i] = false;
                        break;
                    }
                }
                if (!extreme[i]) break;
            }
            if (!extreme[i]) break;
        }
    }

    cout << "\nConvex Hull Points:\n";
    for (int i = 0; i < n; i++) {
        if (extreme[i]) {
            cout << points[i].x << " " 
                 << points[i].y << endl;
        }
    }

    return 0;
}

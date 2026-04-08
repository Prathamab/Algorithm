#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

vector<Point> hull;

double cross(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) -
           (B.y - A.y) * (C.x - A.x);
}

double distance(Point A, Point B, Point C) {
    return abs(cross(A, B, C));
}

void quickHull(vector<Point> &points, Point A, Point B, int side) {
    int index = -1;
    double maxDist = 0;

    for (int i = 0; i < points.size(); i++) {
        double val = cross(A, B, points[i]);
        if (side * val > 0 && abs(val) > maxDist) {
            index = i;
            maxDist = abs(val);
        }
    }

    if (index == -1) {
        hull.push_back(A);
        hull.push_back(B);
        return;
    }

    quickHull(points, points[index], A, -cross(points[index], A, B) > 0 ? 1 : -1);
    quickHull(points, points[index], B, -cross(points[index], B, A) > 0 ? 1 : -1);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    if (n < 3) {
        cout << "Convex hull not possible\n";
        return 0;
    }

    int min_x = 0, max_x = 0;

    for (int i = 1; i < n; i++) {
        if (points[i].x < points[min_x].x)
            min_x = i;
        if (points[i].x > points[max_x].x)
            max_x = i;
    }

    quickHull(points, points[min_x], points[max_x], 1);
    quickHull(points, points[min_x], points[max_x], -1);

    cout << "Convex Hull Points:\n";
    for (auto p : hull)
        cout << p.x << " " << p.y << endl;

    return 0;
}

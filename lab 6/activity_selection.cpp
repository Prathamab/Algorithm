#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool byFinish(Activity a, Activity b) {
    return a.finish < b.finish;
}

bool byStart(Activity a, Activity b) {
    return a.start < b.start;
}

bool byDuration(Activity a, Activity b) {
    return (a.finish - a.start) < (b.finish - b.start);
}

int activitySelection(vector<Activity> arr) {
    int n = arr.size();
    int count = 1;
    int lastFinish = arr[0].finish;

    for(int i = 1; i < n; i++) {
        if(arr[i].start >= lastFinish) {
            count++;
            lastFinish = arr[i].finish;
        }
    }
    return count;
}

int main() {
    int n;
    cout<<"Enter number of process: ";
    cin >> n;

    vector<Activity> arr(n);
    cout<<"Enter START and FINISH time of the processes: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }

    vector<Activity> finishSort = arr;
    sort(finishSort.begin(), finishSort.end(), byFinish);
    int finishCount = activitySelection(finishSort);

    vector<Activity> startSort = arr;
    sort(startSort.begin(), startSort.end(), byStart);
    int startCount = activitySelection(startSort);

    vector<Activity> durationSort = arr;
    sort(durationSort.begin(), durationSort.end(), byDuration);
    int durationCount = activitySelection(durationSort);

    cout << "By Finish Time:" << finishCount << endl;
    cout << "By Start Time: " << startCount << endl;
    cout << "By Duration: " << durationCount << endl;

    return 0;
}
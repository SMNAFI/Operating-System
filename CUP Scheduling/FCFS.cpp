#include<bits/stdc++.h>
    using namespace std;

int n, total_wt, total_tt;

struct Process {
    int pid, at, bt, wt, tt, ct;
};

bool cmp(Process a, Process b) {
    if(a.at == b.at) return a.pid < b.pid;

    return a.at < b.at;
}

void FCFS(Process p[]) {
    int current_time = p[0].at;
    for(int i = 0; i < n; i++) {
        if(p[i].at > current_time) current_time = p[i].at;  // if idle time

        p[i].ct = current_time + p[i].bt;
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;

        total_tt += p[i].tt;
        total_wt += p[i].wt;

        current_time = p[i].ct;
    }
}

void display(Process p[]) {
    // process array is already sorted based on arrival time
    sort(p, p+n, [](Process a, Process b) {
        return a.pid < b.pid;
    });

    cout << "\nProcess ID | " << "Arrival Time | " << "Burst time | "
        << "Completion Time | " << "Turnaround time | " << "Waiting time\n";

    for(int i = 0; i < n; i++)
        cout << "\t" << p[i].pid << " \t" << p[i].at << " \t\t" << p[i].bt
        << " \t\t" << p[i].ct << " \t\t" << p[i].tt << " \t\t" << p[i].wt << '\n';

    cout << "\nAverage waiting Time: " << (double)total_wt/n << '\n';
    cout << "Average Turnaround Time: " << (double)total_tt/n << '\n';
}

// 5
// 1 2 6 2 5 2 3 1 8 4 0 3 5 4 4

// 3
// 1 0 5 2 3 9 3 6 6

int main() {
    cout << "Enter the number of processes: ";
    cin >> n;
    Process p[n];

    cout << "Enter Process id, arrival time & burst time: ";
    for(int i = 0; i < n; i++) {
        cin >> p[i].pid >> p[i].at >> p[i].bt;
    }

    sort(p, p+n, cmp);

    FCFS(p);

    display(p);

    return 0;
}

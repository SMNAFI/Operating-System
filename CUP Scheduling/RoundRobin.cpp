#include <bits/stdc++.h>
    using namespace std;

int n, quantum;
queue<int> readyQueue;

struct Process {
    int pid, at, bt, wt, tt, ct, rt;
    bool inQueue;
};

bool cmp(Process a, Process b) {
    return a.at < b.at;
}

void newArrivals(Process p[], int current_time) {
    for(int i = 0; i < n; i++) {
        if(p[i].at <= current_time && p[i].rt > 0 && p[i].inQueue == false) {
            readyQueue.push(i);
            p[i].inQueue = true;
        }
    }
}

void displayQ(queue<int> q) {
    while(!q.empty()) {
        cout << "P" << q.front()+1 << " ";
        q.pop();
    }
    cout << '\n';
}

void roundRobin(Process p[]) {
    int current_time = p[0].at;

    while(!readyQueue.empty()) {
        cout << "Start time: " << current_time << "\n";
        displayQ(readyQueue);
        int index = readyQueue.front();
        readyQueue.pop();

        if(p[index].rt > quantum) {
            current_time += quantum;
            p[index].rt -= quantum;
        }
        else {
            current_time += p[index].rt;
            p[index].rt = 0;
            p[index].ct = current_time;
            p[index].tt = p[index].ct - p[index].at;
            p[index].wt = p[index].tt - p[index]. bt;
        }
        newArrivals(p, current_time);
        if(p[index].rt > 0) readyQueue.push(index);
        cout << "After: " << current_time << "\n";
        displayQ(readyQueue);
        cout << '\n';
    }
}

void displayR(Process p[]) {
    cout << "Process ID | " << "Arrival Time | " << "Burst time | "
        << "Completion Time | " << "Turnaround time | " << "Waiting time\n";

    for(int i = 0; i < n; i++)
        cout << "\t" << p[i].pid << " \t" << p[i].at << " \t\t" << p[i].bt
        << " \t\t" << p[i].ct << " \t\t" << p[i].tt << " \t\t" << p[i].wt << '\n';

}
// 5
// 1 0 5 2 1 3 3 2 1 4 3 2 5 4 3

// 4
// 1 0 5 2 1 4 3 2 2 4 3 1

int main() {
    cout << "Enter the number of processes: ";
    cin >> n;
    Process p[n];

    cout << "Enter Process id, arrival time & burst time: ";
    for(int i = 0; i < n; i++) {
        cin >> p[i].pid >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;
        p[i].inQueue = false;
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    sort(p, p+n, cmp);

    readyQueue.push(0);
    p[0].inQueue = true;

    roundRobin(p);

    displayR(p);

    return 0;
}

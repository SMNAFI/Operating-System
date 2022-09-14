#include <bits/stdc++.h>
    using namespace std;

struct Process {
    int id, at, bt, rt, wt, tt, priority;
};

bool comp(Process a, Process b) {
    if(a.priority == b.priority && a.at == b.at)
        return a.id < b.id;

    else if(a.priority == b.priority)
        return a.at < b.at;

    return a.priority > b.priority;  // highest value has highest priority
}

int main() {
    int n, completed, current_time = 0;

    cout << "Enter the number of processes: ";
    cin >> n;
    Process p[n];

    // 1 0 3 3
    // 2 1 6 4
    // 3 3 1 9
    // 4 2 2 7
    // 5 4 4 8

    // 1 0 4 2 2 1 3 3 3 2 1 4 4 3 5 5 5 4 2 5

    cout << "Enter Process id, arrival time, burst time & priority: ";
    for(int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].at >> p[i].bt >> p[i].priority;
        p[i].rt = p[i].bt;
    }

    while(completed != n) {
        vector<Process> v;
        for(int i = 0; i < n; i++) {
            // if a Process has arrived before or at current_time & has remmaing time
            if(current_time >= p[i].at && p[i].rt > 0) {
                v.push_back(p[i]);
            }
        }
        sort(v.begin(), v.end(), comp);

        // After selecting and sorting processes
        cout << "Current_time: " << current_time << '\n';
        for(int i = 0; i < v.size(); i++) {
            cout << "iD: " << v[i].id << " at: " << v[i].at << " bt: " << v[i].bt << " p: " << v[i].priority << '\n';
        }
        cout << '\n' << '\n';

        // if any Process have been found

        if(v.size()) {
            int index = v[0].id - 1;
            p[index].rt--;
            current_time++;

            if(p[index].rt == 0) {
                completed++;

                p[index].tt = current_time - p[index].at;
                p[index].wt = p[index].tt - p[index].bt;
            }
        }
        else current_time++;
    }

    double total_wt = 0, total_tat = 0;
    for(int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tt;
    }

    cout << "\nProcess | " << "Burst time | " << "Waiting time | " << "Turnaround time\n";
    for(int i = 0; i < n; i++) {
        cout << " " << p[i].id << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].tt<< '\n';
    }

    cout << "\nAverage waiting time: " << total_wt / (double)n << '\n';
    cout << "Average turn around time: " << total_tat / (double)n << '\n';
}

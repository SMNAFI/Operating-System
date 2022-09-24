#include<bits/stdc++.h>
    using namespace std;

int n, total_wt, total_tt;

struct Process {
    int pid, at, bt, wt, tt, ct, rt;
};

bool comp(Process a, Process b) {
    if(a.rt == b.rt && a.at == b.at)
        return a.pid < b.pid;
    if(a.rt == b.rt)
        return a.at < b.at;

    return a.rt < b.rt;
}

void SJF(Process p[]) {
    int completed = 0, current_time = 0;

    while(completed != n)
    {
        deque<Process> dq;
        for(int i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].rt != 0) {
                dq.push_back(p[i]);
            }
        }

        if(dq.size()) {
            sort(dq.begin(), dq.end(), comp);

            int index;
            for(int i = 0; i < n; i++) {
                if(dq[0].pid == p[i].pid) {
                    index = i;
                    break;
                }
            }

            p[index].rt--;

            if(p[index].rt == 0) {
                p[index].ct = current_time + 1;
                p[index].tt = p[index].ct - p[index].at;
                p[index].wt = p[index].tt - p[index].bt;

                total_wt += p[index].wt;
                total_tt += p[index].tt;

                completed++;
            }
        }
        current_time++;
    }
}

void display(Process p[]) {

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

int main() {
    cout << "Enter the number of processes: ";
    cin >> n;
    Process p[n];

    cout << "Enter Process id, arrival time & burst time: ";
    for(int i = 0; i < n; i++) {
        cin >> p[i].pid >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;
    }

    SJF(p);

    display(p);

    return 0;
}

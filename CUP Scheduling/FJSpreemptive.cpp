#include<bits/stdc++.h>
    using namespace std;

struct Process {
    int id;
    int bt;
    int art;
};

int  main() {
    // Process p[] = { { 1, 6, 2 }, { 2, 2, 5 }, { 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
    Process p[] = { { 1, 6, 0 }, { 2, 4, 1 }, { 3, 2, 2 }, { 4, 3, 3} };
    int n = sizeof(p) / sizeof(p[0]);
    int rt[n], wt[n], tat[n];

    for(int i = 0; i < n; i++) rt[i] = p[i].bt;

    int c = 0, t = 0, minm = INT_MAX, index = 0;
    bool flag = false;

    // waiting time calculation

    while (c != n) {
        for(int i = 0; i < n; i++) {
            if((p[i].art <= t) && (rt[i] < minm) && (rt[i] > 0)) {
                minm = rt[i];
                index = i;
                flag = true;
            }
        }

        if(flag == false) {
            t++;
            continue;
        }

        rt[index]--;
        minm--;


        if(rt[index] == 0) {        // if process is completed
            minm = INT_MAX;
            c++;
            flag = false;

            int completion_time = t + 1;
            wt[index] = completion_time - p[index].bt - p[index].art;
        }

        t++;
    }

    // Turn-around time

    for(int i = 0; i < n; i++) {
        tat[i] = p[i].bt + wt[i];
    }

    // Display output

    int total_wt = 0, total_tat = 0;

    cout << " Process ID" << " | " << "Burst time" << " | " << "Waiting time" << " | " << "Turn around time\n";
    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];

        cout << '\t' << p[i].id << "\t " << p[i].bt << "\t\t"
             << wt[i] << "\t\t" << tat[i] << '\n';
    }

    cout << "\n\nAverage waiting time: " << (double)total_wt / n << '\n';
    cout << "Average turn around time: " << (double)total_tat / n << '\n';

    return 0;
}

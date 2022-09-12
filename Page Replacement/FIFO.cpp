#include<bits/stdc++.h>
    using namespace std;

int pageFault(int pages[], int n, int frames) {
    int faultCount = 0;

    unordered_set<int> s;
    queue<int> q;

    for(int i = 0; i < n; i++) {
        int p = pages[i];
        
        // page miss
        if(s.count(p) == 0) {
            faultCount++;

            // page replace
            if(q.size() >= frames) {
                int victim = q.front();
                // cout << victim << '\n';
                q.pop();
                s.erase(victim);
            }

            // inserting required page
            q.push(p);
            s.insert(p);
        }
    }

    return faultCount;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);

    int frames = 4;
    int faultCount = pageFault(pages, n, frames);
    cout << "Page Hit: " << n - faultCount << endl;
    cout << "Page Fault: " << faultCount << endl;

    return 0;
}
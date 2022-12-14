#include<bits/stdc++.h>
    using namespace std;

int pageFault(int pages[], int n, int frames) {
    int faultCount = 0;

    unordered_map<int, int> pos;

    for(int i = 0; i < n; i++) {
        int p = pages[i];

        // page miss
        if(pos.find(p) == pos.end()) {
            faultCount++;

            // page replace if no empty frames
            if(pos.size() >= frames) {
                int victim, index = INT_MAX;
                for(auto it = pos.begin(); it != pos.end(); it++) {
                    if(index > it->second) {
                        victim = it->first;
                        index = it->second;
                    }
                }
                // cout << "Victim: " << victim << '\n';
                pos.erase(victim);
            }
        }

        // updating index of the page
        pos[p] = i+1;
    }

    return faultCount;
}

int main() {
    int pages[] = {1, 2, 1, 0, 3, 0, 4, 2, 4};
    int n = sizeof(pages)/sizeof(pages[0]);

    int frames = 3;
    int faultCount = pageFault(pages, n, frames);

    cout << "Page Hit: " << n - faultCount << endl;
    cout << "Page Fault: " << faultCount << endl;

    return 0;
}
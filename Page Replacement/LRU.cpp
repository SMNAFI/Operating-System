#include<bits/stdc++.h>
    using namespace std;

int pageFault(int pages[], int n, int frames) {
    int faultCount = 0;

    unordered_map<int, int> pos;

    for(int i = 0; i < n; i++) {
        int p = pages[i];

        if(pos.find(p) == pos.end()) {
            faultCount++;

            if(pos.size() >= frames) {
                int victim, index = INT_MAX;
                for(auto it = pos.begin(); it != pos.end(); it++) {
                    if(index > it->second) {
                        victim = it->first;
                        index = it->second;
                    }
                }
                // cout << victim << '\n';
                pos.erase(victim);
            }
        }

        pos[p] = i+1;
    }

    return faultCount;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);

    int frames = 4;

    cout << "Page Fault Count: " << pageFault(pages, n, frames) << endl;

    return 0;
}
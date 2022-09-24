#include<bits/stdc++.h>
    using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int pageFault(int pages[], int n, int frames) {
    int faultCount = 0;

    unordered_set<int> s;

    for(int i = 0; i < n; i++) {
        int p = pages[i];

        // page miss
        if(s.find(p) == s.end()) {
            faultCount++;

            // page replace
            if(s.size() >= frames) {

                // storing current pages
                vector<pair<int, int>> pos;
                for(auto it = s.begin(); it != s.end(); it++) {
                    pos.push_back({*it, INT_MAX});
                }

                // next recent needed index of the current pages
                for(int j = 0; j < frames; j++) {
                    for(int k = i + 1; k < n; k++) {
                        if(pos[j].first == pages[k] && pos[j].second == INT_MAX) {
                            pos[j].second = k;
                        }
                    }
                }

                // removing page that is no longer needed or isn't needed in near future
                sort(pos.begin(), pos.end(), cmp);
                // cout << "Victim: " << pos[0].first << '\n';
                s.erase(pos[0].first);
            }

            // inserting missing page
            s.insert(p);
        }
    }

    return faultCount;
}

int main() {
    int pages[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
    int n = sizeof(pages)/sizeof(pages[0]);

    int frames = 4;
    int faultCount = pageFault(pages, n, frames);

    cout << "Page Hit: " << n - faultCount << endl;
    cout << "Page Fault: " << faultCount << endl;

    return 0;
}

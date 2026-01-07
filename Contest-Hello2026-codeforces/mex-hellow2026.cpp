// GOT THIS ONE WRONG IN THE CONTEST (rem: check solution post contest)
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == k) {
        set<int> distinct(a.begin(), a.end());
        int mex = 0;
        while (distinct.count(mex)) mex++;
        cout << mex << "\n";
        return;
    }

    map<int, int> counts;
    set<int> missing;
    
    for(int i = 0; i <= n + 1; i++) {
        missing.insert(i);
    }
    
    for (int i = 0; i < k; ++i) {
        counts[a[i]]++;
        missing.erase(a[i]);
    }
    
    int max_window_mex = *missing.begin();
    
    for (int i = k; i < n; ++i) {
        int outgoing = a[i - k];
        counts[outgoing]--;
        if (counts[outgoing] == 0) {
            missing.insert(outgoing);
        }
        
        int incoming = a[i];
        counts[incoming]++;
        missing.erase(incoming);
        
        max_window_mex = max(max_window_mex, *missing.begin());
    }
    
    cout << min(k - 1, max_window_mex) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
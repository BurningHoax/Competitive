#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;
        
        long long L = k - 1;
        long long R = n - k;
        
        long long ans = 1;
        
        for (long long a = 0; a <= L; a++) {
            if (a == 0) {
                long long b = min(R, (m + 1) / 2);
                ans = max(ans, 1 + b);
            } else {
                if (2 * a - 1 > m) continue;
                
                long long b1 = m + 1 - 2 * a;
                if (b1 < 0) b1 = 0;
                b1 = min(b1, a);
                b1 = min(b1, R);
                
                long long b2 = (m + 1 - a) / 2;
                if (b2 < a) b2 = 0;
                b2 = min(b2, R);
                
                long long b = max(b1, b2);
                ans = max(ans, 1 + a + b);
            }
        }
        
        cout << min(n, ans) << "\n";
    }
    
    return 0;
}
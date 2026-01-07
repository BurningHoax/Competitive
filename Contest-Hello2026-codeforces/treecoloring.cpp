#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> children(n+1, 0);
        vector<bool> vis(n+1, false);
        vector<int> q = {1};
        vis[1] = true;
        
        for (int i = 0; i < q.size(); i++) {
            int u = q[i];
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    children[u]++;
                    q.push_back(v);
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, 1 + children[i]);
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
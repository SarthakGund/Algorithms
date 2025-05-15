#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

    for(int i=1; i<=n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        
        dist[a][b] = min(dist[a][b], wt);
        dist[b][a] = min(dist[b][a], wt);   
    }

    for (int k = 1; k <= n; k++)
    {
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == INF) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
     
}

int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
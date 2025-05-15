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

    vector<pair<int, pair<int, int>>> edges;
    vector<int> dist(n+1, INF);

    bool negcy = false;

    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        edges.push_back({a, {b, wt}});
    }

    auto bellman = [&](int src){
        dist[src] = 0;
        for (int i = 0; i < n-1; i++)
        {
            for(auto &it: edges){
                int u = it.first;
                int v = it.second.first;
                int wt = it.second.second;

                if(dist[u] != INF && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Nth relaxation for -ve cycle
        for(auto &it: edges){
            int u = it.first;
            int v = it.second.first;
            int wt = it.second.second;

            if(dist[u] != INF && dist[u] + wt < dist[v]) negcy = true;
        }
        
    };

    //print 
    
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
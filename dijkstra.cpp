#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cassert>
#include <functional>
#include <bitset>
#include <numeric>
#include <tuple>
#include <random>
#include <iomanip>
#include <fstream>
#include <iterator>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);
    vector<int> dist(n+1, INF);
        vector<bool> vis(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
    }

    auto dijkstra = [&](int src)->void{
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;

        s.push({0LL, src});
        dist[src] = 0;

        while (!s.empty())
        {
            auto node = s.top();
            s.pop();
            int dis = node.first;
            int u = node.second;

            if(dis > dist[u]) continue;

            for(auto &ch: adj[u]){
                int v = ch.first;
                int wt = ch.second;

                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    s.push({dist[v], v});
                }
            }
        }
        
    };
    
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
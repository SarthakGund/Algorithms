#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve(){
    int n, m
    ;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
    }

    auto prims = [&](){
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(n+1, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto &it : adj[node]) {
				int adjNode = it.first;
				int edW = it.second;
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
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
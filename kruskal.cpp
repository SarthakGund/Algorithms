#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MOD = 1e9 + 7;

class DisjointSet{
    private:
    vector<int> rank, size, parent;

    public:
    int components, maxsize;
    DisjointSet(int n){
        components = n;
        maxsize = 1;
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUpar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_v = findUpar(v);
        int ulp_u = findUpar(u);

        if(ulp_v == ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = parent[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_v] < size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges; // wt, u, v
    DisjointSet dsu(n);

    for(int i = 0; i < m; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        edges.push_back({wt, {a, b}});
    }

    sort(edges.begin(), edges.end());
    int cost = 0;

    for(auto &edge: edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(dsu.findUpar(u) == dsu.findUpar(v)) continue;
        dsu.unionBySize(u, v); // or dsu.unionByRank(u, v);
        cost += wt;
        cout << u << " " << v << endl;
    }

    cout << cost << endl;
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
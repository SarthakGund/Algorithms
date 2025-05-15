#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(auto &it: v) cin >> it;
    int g_min = INF, g_max = (-1ll * INF);


    auto minmax = [&](auto &&minmax, int high, int low)->pair<int, int>{
        if((high - low <= 1) && (high - low >= 0)){
            return {min(v[high], v[low]), max(v[high], v[low])};
        }

        int mid = (low + high) / 2;
        pair<int, int> left = minmax(minmax, low, mid);
        pair<int, int> right = minmax(minmax, mid+1, high);
        int mini = min(left.first, right.first);
        int maxi = max(left.second, right.second);

        return {mini, maxi};
    };

    auto ans = minmax(minmax, 0, n-1);

    cout << ans.first << " " << ans.second << endl;

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
#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"
 
const int INF = 1e18;
const int MOD = 1e9 + 7;
 
void solve(){
    int n, x;
    cin >> n >> x;

    // x-> capacity    h->weight    s->profit
 
    vector<int> h(n);
    vector<int> s(n);
 
    vector<int> tp(x+1, 0);
 
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
 
    /*
        dp[i][j] = max(dp[i-1][j], s[x] + dp[i-1][j-h[x]]);
        depends on last row i.e. i-1 
    */
 
 
    for (int i = 0; i <n ; i++)
    {
        vector<int> temp(x+1);
        for (int j = x; j >= 0; j--)
        {
            if(j==0) temp[j] = 0;
            else if(j>=h[i]) temp[j] = max(tp[j], s[i] + tp[j-h[i]]);
            else temp[j] = tp[j];
        }
        tp = temp;
        
    }
    
 
    // cout << dp[n][x] << endl;   .
    cout << tp[x] << endl;
 
}
 
int32_t main() {
    fast_io;
 
        solve();
    
    return 0;
}
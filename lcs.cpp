#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve(){
    string s, t;
    int n, m;
    cin>>s>>t;
    n = s.size();
    m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    vector<int>a;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(s[i-1]==t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;

                if(dp[i][j]>a.size()){
                    a.push_back(j-1);
                }
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ans = "";

    int i=n, j=m;

    while (i>0 && j>0)      
    {
        if(dp[i][j]==dp[i-1][j]) i--;
        else if(dp[i][j]== dp[i][j-1]) j--;
        else
        {
            ans+=t[j-1];
            i--;
            j--;
        } 
    }
    
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
 
}

int32_t main() {
    fast_io;

        solve();
    
    return 0;
}
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

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        if(amount == 0) return dp[amount];

        for(int i=0; i<coins.size(); i++){
            if(coins[i] <= amount)dp[coins[i]] = 1;
        }

        for(int i=1; i<=amount; i++){
            for(int j = 0; j<coins.size(); j++){
                if(dp[i] == -1 && i - coins[j] >= 0 && dp[i-coins[j]]!=-1)dp[i] = dp[i - coins[j]] + 1;
                else if(i - coins[j] >= 0 && dp[i - coins[j]] != -1) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        return dp[amount];
    }

void solve(){
    int n, a;
    cin >> n >> a;
    vector<int> coins(n);
    for(auto &it: coins) cin >> it;

    cout << coinChange(coins, a) << endl;
    
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
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll N;
        cin >> N;
        string S;
        cin >> S;
        ll X[N];
        rep(i,N)cin >> X[i];
        ll Y[N-1];
        rep(i,N-1)cin >> Y[i];

        ll dp[2][N]; // 0 is rainy; 1 is sunny;
        if(S[N-1] == 'R'){
            dp[0][N-1] = 0;
            dp[1][N-1] = -X[N-1]; // to become sunny u gotta lose some point
        }else{
            dp[1][N-1] = 0;
            dp[0][N-1] = -X[N-1];
        }

        for(ll i = N-2; i >= 0; i--){
            if(S[i] == 'R'){
                dp[0][i] = max(dp[0][i+1],dp[1][i+1]+Y[i]);
                dp[1][i] = max(dp[0][i+1],dp[1][i+1])-X[i];
            }else{//its sunny;
                dp[0][i] = max(dp[0][i+1],dp[1][i+1]+Y[i]) - X[i];
                dp[1][i] = max(dp[0][i+1],dp[1][i+1]);
            }
        }
        cout << max(dp[0][0],dp[1][0]) << endl;
    }
}
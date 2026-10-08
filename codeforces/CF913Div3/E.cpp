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
    ll t;
    cin >> t;//10^4
    rep(_,t){ // operation must be around 10^4
        ll n;
        cin >> n;
        if(n==0){
            cout << 1 << endl;
            continue;
        }
        // dp of cost n;
        ll ndigSum = 0;
        ll ndigCnt = 0;
        ll cpyn = n;
        vector<ll> digs;
        while(cpyn > 0){
            digs.push_back(cpyn%10);
            ndigCnt++;
            ndigSum += cpyn%10;
            cpyn/=10;
        }
        ll score[10] = {1,3,6,10,15,21,28,36,45,55};
        ll dp[ndigCnt][ndigSum+1]; // 7 * 63 = 500
        //cout << ndigCnt << " " << ndigSum << " " << digs[0]<< " " << digs.size()  << " ;" << endl;
        rep(i,ndigCnt)rep(j,ndigSum+1)dp[i][j] = 0;
        dp[0][digs[0]]=score[digs[0]]; // for the first digit there is only one way to fill.

        repp(i,1,ndigCnt){
            rep(j,ndigSum+1){
                rep(k,digs[i]+1){
                    if((j-k)<0)continue;
                    dp[i][j] += dp[i-1][j-k]*score[k];
                }
            }
        }
        /*
        cout <<"digCnt: ndigSum = " << ndigCnt << " " << ndigSum << endl;
        rep(i,ndigCnt){
            rep(j,ndigSum+1)cout << dp[i][j] << " ";
            cout << endl;
        }*/
        ll ans = dp[ndigCnt-1][ndigSum];
        cout << ans << endl;
    }
}
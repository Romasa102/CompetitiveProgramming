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
double N;
vector<vector<vector<double>>> dp;
double expt(ll on,ll tw,ll th){
    if(dp[on][tw][th]!=-1)return dp[on][tw][th];
    double totalN = on+tw+th;
    double rtrn = 0;
    if(on>0){
        double next = 0;
        if(dp[on-1][tw][th]!=-1){
            next = dp[on-1][tw][th];
        }else{
            next = expt((on-1),tw,th);
        }
        rtrn += (on/totalN)*(next + (N/totalN));
    }
    if(tw>0){
        double next = 0;
        if(dp[on+1][tw-1][th]!=-1){
            next = dp[on+1][tw-1][th];
        }else{
            next = expt(on+1,tw-1,th);
        }
        rtrn += (tw/totalN)*(next + (N/totalN));
    }
    if(th>0){
        double next = 0;
        if(dp[on][tw+1][th-1]!=-1){
            next = dp[on][tw+1][th-1];
        }else{
            next = expt(on,tw+1,th-1);
        }
        rtrn += (th/totalN)*(next + (N/totalN));
    }
    return dp[on][tw][th] = rtrn;
}
int main(){
    cin>>N;
    vector<ll> a(3,0);
    rep(i,N){
        ll temp;
        cin>>temp;
        if(temp==3)a[2]++;
        if(temp==2)a[1]++;
        if(temp==1)a[0]++;
    }
    dp.resize(N+1,vector<vector<double>>(N+1,vector<double>(N+1,-1)));
    dp[0][0][0]=0;
    double ans = expt(a[0],a[1],a[2]);

    cout << setprecision(15);
    cout << ans << endl;
}
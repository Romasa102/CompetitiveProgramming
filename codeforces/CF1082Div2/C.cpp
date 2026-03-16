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
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        rep(i,n)cin >> a[i];
        ll kill = 0;
        vector<pair<ll,P>> dp(n,{0,{0,0}});
        repp(i,1,n){
            auto prev = dp[i-1];
            ll oldN = dp[i-1].first;
            ll oldB = dp[i-1].second.first;
            ll oldE = dp[i-1].second.second; 

            if(a[i]==(a[i-1]+1) && oldN == 0){
                dp[i]={1,{a[i],a[i]+1}};
            }
            else if(oldN!=0 && oldB <= a[i] && a[i]<=oldE){
                dp[i]={oldN+1,{oldB,a[i]+1}};
            }else{
                kill+=oldN;
            }
        }
        kill += dp[n-1].first;
        cout << n-kill << endl;
    }
}
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
ll segTS = 1;
vector<ll> segT;
int main(){
    ll N;
    cin >> N;
    while(segTS<N){
        segTS*=2;
    }
    segT.resize(segTS*2,0);
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    map<ll,ll> dp;
    dp[A[0]]=1;
    repp(i,1,N){
        if(dp.find(A[i]-1)!=dp.end()){
            dp[A[i]]=dp[A[i]-1]+1;
        }else{
            dp[A[i]]=1;
        }
    }
    ll ans = 0;
    for(auto i : dp){
        ans = max(ans, i.second);
    }
    cout << ans << endl;
}
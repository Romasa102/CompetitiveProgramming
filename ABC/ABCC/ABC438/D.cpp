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
    ll N;
    cin >> N;
    ll A[N],B[N],C[N];
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> B[i];
    rep(i,N)cin >> C[i];
    ll ans = 0;
    ll BSum [N+1];
    BSum[0] = 0;
    ll CSum [N+1];
    CSum[N] = 0;
    repp(i,1,N+1)BSum[i] = BSum[i-1] + B[i-1];
    for(ll i = N-1;i>=0;i--)CSum[i] = CSum[i+1] + C[i];
    deque<P> BCSum(N);
    rep(i,N){
        BCSum[i] = {BSum[i] + CSum[i],i};
    }
    sort(BCSum.begin(),BCSum.end(),greater<P>());
    ll ASum = 0;
    map<ll,bool> visited;
    ll BCurSum = 0;
    rep(i,N){
        ASum+=A[i];
        BCurSum += B[i];
        visited[i] = true;
        if(!BCSum.empty()){
            ans = max(ASum+BCSum[0].first-BCurSum,ans);
            while(!BCSum.empty()&&visited.find(BCSum[0].second) != visited.end())BCSum.pop_front();
        }   
    }
    cout << ans << endl;
}
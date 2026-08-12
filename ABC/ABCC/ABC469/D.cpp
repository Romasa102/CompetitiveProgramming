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
    ll N,M;
    cin >> N >> M;
    ll A[M],B[M];
    vector<ll> deg(N,0);
    map<P,ll> match;
    rep(i,M){
        cin >> A[i] >> B[i];A[i]--;B[i]--;
        deg[A[i]]++;deg[B[i]]++;
        match[{min(A[i],B[i]),max(A[i],B[i])}]++;
    }
    vector<P> degind(N);
    rep(i,N){
        degind[i].first = deg[i];
        degind[i].second = i;
    }
    sort(degind.begin(),degind.end(),greater<P>());
    ll ans = 0;
    rep(i,N){
        ll cur = 0;
        while(cur < N && (deg[i] + degind[cur].first) >= M){
            ll curval = degind[cur].first;
            ll curind = degind[cur].second;
            cur++;
            if(curind == i)continue;
            if((deg[i] + curval - match[{min(i,curind),max(i,curind)}]) >= M){
                //cout << i << " " << curind << endl;
                ans++;
            }
        }
    }
    cout << ans/2 << endl;
}
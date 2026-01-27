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
ll segTS = 1LL<<28;
vector<P> segT(segTS*2,{0,0});
void update(ll pos){
    ll k = pos+segTS;
    segT[k].first+=pos;
    segT[k].second++;
    while(k>1){
        k/=2;
        segT[k]={segT[k*2].first+segT[k*2+1].first,
                segT[k*2].second+segT[k*2+1].second};
    }
}
P getSum(ll l, ll r,ll st = 0, ll en = segTS-1,ll node = 1){
    if(l<=st&&en<=r)return segT[node];
    if(en<l||r<st)return {0,0};
    P leftS = getSum(l,r,st,(st+en)/2,node*2);
    P rightS = getSum(l,r,(st+en)/2+1,en,node*2+1);
    return {leftS.first+rightS.first,leftS.second+rightS.second};
}
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    update(A[N-1]);
    ll ans = 0;
    for(ll i = N-2;i>=0;i--){
        P cur = getSum(A[i],segTS-1);
        ans+=cur.first-cur.second*A[i];
        update(A[i]);
    }
    cout << ans << endl;
}
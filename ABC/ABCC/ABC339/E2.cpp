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
ll segTS = 1LL<<20;
vector<ll> segT(segTS*2,0);
void update(ll pos,ll x){
    ll k = pos+segTS;
    segT[k]=x;
    while(k>1){
        k/=2;
        segT[k]=max(segT[k*2],segT[k*2+1]);
    }
}
ll getMax(ll l,ll r,ll st = 0,ll en = segTS-1, ll node = 1){
    if(l<=st&&en<=r)return segT[node];
    if(en<l||r<st)return 0;
    return max(getMax(l,r,st,(st+en)/2,node*2),getMax(l,r,(st+en)/2+1,en,node*2+1));
}
int main(){
    ll N,D;
    cin >> N >> D;
    ll A[N];
    rep(i,N)cin >> A[i];
    for(ll i = N-1;i >=0; i--){
        ll maxF =getMax(max(0LL,A[i]-D),min(segTS-1,A[i]+D));
        
        update(A[i],maxF+1);
    }
    cout << segT[1] << endl;
}
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
vector<ll> segT;
ll segTS = 1;
ll INF = 1LL<<50;
void update(ll pos,ll x){
    ll k = pos+segTS;
    segT[k]=x;
    while(k>1){
        k/=2;
        segT[k]=min(segT[k*2],segT[k*2+1]);
    }
}
ll getM(ll l,ll r,ll st=0,ll en=segTS-1,ll node=1){
    if(l<=st && en <= r)return segT[node];
    if(r<st||en<l)return INF;
    return(min(getM(l,r,st,(st+en)/2,node*2),getM(l,r,(st+en)/2+1,en,node*2+1)));
}
int main(){
    ll N,L,R;
    cin >> N >> L >> R;
    while(segTS<N)segTS*=2;
    segT.resize(segTS*2,INF);
    ll X[N];
    rep(i,N)cin >> X[i];
    update(0,0);
    repp(i,1,N){
        ll rchm = lower_bound(X,X+N,X[i]-R)-X;
        ll rchM = upper_bound(X,X+N,X[i]-L)-X;
        if(rchm==rchM)continue;
        //cout << i << "min:" << rchm << " Max:" << rchM << "minVL" << getM(rchm,rchM-1) << endl;
        ll next = getM(rchm,rchM-1)+1;
        update(i,next);
    }
    /*rep(i,N){
        cout << segT[segTS+i] << " ";
    }cout << endl;*/
    cout << segT[segTS+N-1] << endl;
}
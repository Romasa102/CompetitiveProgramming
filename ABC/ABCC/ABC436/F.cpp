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
vector<ll> rmq; //range minimum query
vector<ll> RMQ; //range max query
void update(ll pos, ll x){
    ll k = segTS+pos;
    rmq[k]=x;
    RMQ[k]=x;
    while(k>1){
        k/=2;
        rmq[k] = min(rmq[k*2],rmq[k*2+1]);
        RMQ[k] = max(RMQ[k*2],RMQ[k*2+1]);
    }
}
ll getMin(ll l,ll r,ll st = 0,ll en = segTS-1,ll node = 1){
    if(l<=st&&en<=r)return rmq[node];
    if(en<l||r<st)return 1LL<<40;
    return min(getMin(l,r,st,(st+en)/2,node*2),getMin(l,r,(st+en)/2+1,en,node*2+1));
}

ll getMax(ll l,ll r,ll st = 0,ll en = segTS-1,ll node = 1){
    if(l<=st&&en<=r)return RMQ[node];
    if(en<l||r<st)return 0;
    return max(getMax(l,r,st,(st+en)/2,node*2),getMax(l,r,(st+en)/2+1,en,node*2+1));
}
int main(){
    ll N;
    cin >> N;
    while(segTS<N)segTS*=2;
    ll B[N];
    rmq.resize(segTS*2,1LL<<40);
    RMQ.resize(segTS*2,0);
    rep(i,N){
        cin >> B[i];
        update(B[i]-1,i);
    }
    ll cnt = 0;
    rep(i,N){
        ll m = getMin(0,i);
        ll M = getMax(0,i);
        cnt+=(((m+1)*(N-M)-1)*(N-i));
        cout << (((m+1)*(N-M)-1)*(N-i)) << endl;
        cout << cnt << endl;
    }
    //cout << "cnt; " << (N*(N+1)/2) << endl;
    cout << ((N*(N+1)/2)*(N))-cnt<< endl;
}
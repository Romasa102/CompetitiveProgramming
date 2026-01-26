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
ll segTS=1LL<<20;
vector<P> segT;
void update(ll pos,bool add){
    ll k = pos+segTS;
    if(add){
        segT[k].second++;
        segT[k].first+=pos;
    }else{
        segT[k].second--;
        segT[k].first-=pos;
    }
    while(k>1){
        k/=2;
        segT[k].first=(segT[k*2].first+segT[k*2+1].first);
        segT[k].second=(segT[k*2].second+segT[k*2+1].second);
    }
}
P getSum(ll l,ll r,ll st = 0, ll en = segTS-1,ll node = 1){
    if(l<=st && en <= r)return segT[node];
    if(en<l || r<st)return {0,0};
    P leftVal = getSum(l, r, st, (st+en)/2, node*2);
    P rightVal = getSum(l, r, (st+en)/2+1, en, node*2+1);
    return {leftVal.first + rightVal.first, leftVal.second + rightVal.second};
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    segT.resize(segTS*2,{0,0});
    ll A[N];
    rep(i,N){
        cin >> A[i];
        update(A[i],true);
    }
    rep(_,Q){
        ll t;
        cin >> t;
        if(t==1){
            ll x,y;
            cin >> x >> y;
            update(A[x-1],false);
            update(y,true);
            A[x-1]=y;
        }else{
            ll l,r;
            cin >> l >> r;
            ll ans = 0;
            if(l>=r){
                ans+=l*N;
            }else{
                P cur = getSum(l,r-1);
                P smallerTL = getSum(0,l-1);
                ans+=(smallerTL.second)*l;
                ans+=cur.first;
                ans+=r*(N-cur.second-smallerTL.second);
            }
            cout << ans << endl;
        }
    }
}
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

void initi(ll x,ll y){
    x+=(segTS-1);
    segT[x]=y;
    ll k=x;
    while(k>1){
        k/=2;
        segT[k]=segT[k*2]^segT[k*2+1];
    }
}
void update(ll x,ll y){
    x+=(segTS-1);
    segT[x]^=y;
    ll k=x;
    while(k>1){
        k/=2;
        segT[k]=segT[k*2]^segT[k*2+1];
    }
}
ll xorSearch(ll l,ll r, ll st = 1, ll en = segTS, ll node = 1){
    if(l <= st && en <= r)return segT[node];
    if(r < st || l > en)return 0;
    return xorSearch(l,r,st,(st+en)/2,node*2)^xorSearch(l,r,(st+en)/2+1,en,node*2+1);
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    ll A[N];
    while(segTS<N)segTS*=2;
    segT.resize(segTS*2,0);
    rep(i,N){
        cin >> A[i];
        initi(i+1,A[i]);
    }
    //rep(i,segTS*2)cout << segT[i] << " ";
    
    rep(_,Q){
        ll t,x,y;
        cin >> t >> x >> y;
        if(t==1){
            update(x,y);
            //repp(i,segTS,segTS+N)cout << segT[i] << " ";
        }else{
            cout << xorSearch(x,y)<< endl;
        }
    }
}
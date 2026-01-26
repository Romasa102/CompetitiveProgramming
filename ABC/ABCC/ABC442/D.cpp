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
void update(ll pos, ll x){
    ll k = segTS+pos;
    segT[k]=x;
    while(k>1){
        k/=2;
        segT[k]=segT[k*2]+segT[k*2+1];
    }
}
ll sumQ(ll l,ll r,ll st = 0,ll en = segTS-1,ll node = 1){
    //cout << "sumQ" << l << " " << r << ":" << st << " " << en << endl;
    if(l<=st && en<=r)return segT[node];
    if(en<l || r<st)return 0;
    return sumQ(l,r,st,(st+en)/2,node*2)+sumQ(l,r,((st+en)/2)+1,en,node*2+1);
}

int main(){
    ll N,Q;
    cin >> N >> Q;
    while(segTS<N)segTS*=2;
    segT.resize(segTS*2,0);
    ll A[N];
    rep(i,N){
        cin >> A[i];
        update(i,A[i]);
    }
    rep(_,Q){
        ll task;
        cin >> task;
        if(task == 1){
            ll x;
            cin >> x;
            x--;
            ll temp = segT[x+segTS];
            ll temp2 = segT[x+segTS+1];
            update(x,temp2);
            update(x+1,temp);
        }else{
            ll l,r;
            cin >> l >> r;
            l--;r--;
            cout << sumQ(l,r) << endl;
        }
    }
}
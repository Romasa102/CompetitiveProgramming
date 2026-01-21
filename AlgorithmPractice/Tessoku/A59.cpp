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
ll N,Q;
ll segSize = 1;
vector<ll> segT;
void update(ll pos,ll x){
    segT[pos]=x;
    ll k = pos;
    while(k > 1){
        k/=2;
        segT[k] = segT[k*2]+segT[k*2+1];
    }
}
ll sumSearch(ll l,ll r,ll st = 1,ll en = segSize, ll node = 1){
    if(l <= st && en <= r)return segT[node];
    if(en < l || r < st)return 0;
    return (sumSearch(l,r,st,(st+en)/2,node * 2) + sumSearch(l,r,(st+en)/2+1,en,node*2+1));
}
int main(){
    cin >> N >> Q;
    while(segSize <= N)segSize*=2;
    segT.resize(2*segSize+1,0);
    rep(_,Q){
        ll task = 0;
        cin >> task;
        if(task == 1){
            ll pos,x;
            cin >> pos >> x;
            update(pos + segSize-1,x);

        }else{
            ll left,right;
            cin >> left >> right;
            cout << sumSearch(left,right-1) << endl;
        }
    }
}
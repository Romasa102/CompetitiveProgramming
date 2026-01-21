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
vector<ll> segTree;
ll N,Q;
ll segSize = 1;
void update(ll pos,ll x){
    segTree[pos] = x;
    ll k = pos;
    while(k>1){
        k/=2;
        segTree[k] = max(segTree[k*2], segTree[k*2+1]);
    }
}
//current node, left most node in the coverage, right mode node in the coverage
//left side we have to serach. right side we have to search.
ll maxSearch(ll l,ll r, ll node=1LL, ll st=1LL, ll en=segSize){
    if(l <= st && en <= r)return segTree[node];
    if(st>r || en<l)return 0;    
    ll ans = max(maxSearch(l,r,node*2,st,(st+en)/2),maxSearch(l,r,node*2+1,(st+en)/2+1,en));
    return ans;
}
int main(){
    cin >> N >> Q;
    while (segSize < N) segSize *= 2;
    segTree.resize(segSize*2,0);
    rep(_,Q){
        ll task;
        cin >> task;
        if(task == 1){
            ll pos,x;
            cin >> pos >> x;
            update(segSize-1+pos,x);
        }else{
            ll left,right;
            cin >> left >> right;
            cout << maxSearch(left,right-1) << endl;
        }
    }
}
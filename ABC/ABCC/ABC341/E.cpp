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
vector<bool> segT;
void update(ll x){
    if(x<0||x>segTS)return;
    ll k = x += segTS;
    segT[k] = !segT[k];
    while(k>1){
        k/=2;
        segT[k]=(segT[k*2]&&segT[k*2+1]);
    }
}
ll isAlt(ll l,ll r,ll st = 0,ll en = segTS-1, ll node = 1){
    if(l<=st && en <= r)return segT[node];
    if(r<st || en<l)return 1;
    return (isAlt(l,r,st,(st+en)/2,node*2) && isAlt(l,r,(st+en)/2+1,en,node*2+1));
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    while(segTS<(N-1))segTS*=2;
    segT.resize(segTS*2,0);
    string S;cin>>S;
    rep(i,N-1){
        if(S[i]!=S[i+1])update(i);
    }
    while(Q--){
        ll task;cin >> task;
        ll l,r;cin >> l >> r;
        if(task ==1){
            update(l-2);
            update(r-1);
        }else{
      //      cout << l-1 << r-2  << ":" << isAlt(l-1,r-2) << endl;
            if(isAlt(l-1,r-2)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
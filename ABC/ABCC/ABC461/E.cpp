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

ll segTsize = 1;

void add(vector<ll> &segT, ll x){
    ll cur = x+segTsize;
    segT[cur]++;
    while(cur > 1){
        cur /= 2;
        segT[cur] = segT[cur*2] + segT[cur * 2 +1];
    }
}

void sub(vector<ll> &segT, ll x){
    ll cur = x+segTsize;

    if(segT[cur] != 0)segT[cur]--;
    while(cur > 1){
        cur /= 2;
        segT[cur] = segT[cur*2] + segT[cur * 2 +1];
    }
}

ll getSum(vector<ll> &segT, ll l,ll r, ll ind = 1, ll b =  0, ll e = segTsize-1){
    if(e < l || r < b)return 0;
    if(l <= b && e <= r)return segT[ind];
    return getSum(segT, l, r, ind * 2, b , (b+e)/2) + getSum(segT, l, r, ind * 2 + 1, (b + e)/2 + 1 , e);
}

int main(){
    cin >> N >> Q;
    while(segTsize < Q)segTsize *= 2;
    vector<ll> segTW (2 * segTsize + 1, 0);
    vector<ll> segTB (2 * segTsize + 1, 0);
    
    vector<ll> lastTimeR(N,0);
    vector<ll> lastTimeC(N,0);

    ll ans = 0;
    
    rep(i,N)add(segTW,0);

    repp(i,1,Q+1){

        ll x; cin >> x;
        ll v; cin >> v;
        v--;
        
        if(x == 1){ // black
            ll original = lastTimeR[v]; //what time this table was last updated.
            sub(segTB,original);
            ll originalCoverage = getSum(segTW, original, segTsize-1);

            //cout << "white row since : "  << getSum(segTW,original,segTsize-1) << endl;
            ans += originalCoverage;
            //ans += N;
            add(segTB,i);
            lastTimeR[v] = i;
        }else{ // white
            ll original = lastTimeC[v]; //what time this table was last updated.
            sub(segTW,original);
            ll originalCoverage = getSum(segTB, original, segTsize-1);
            //cout << "subject to delete " << originalCoverage << endl;
            ans -= originalCoverage;
            add(segTW,i);
            lastTimeC[v] = i;
        }
        cout << ans << endl;
    }
    /*
    for(ll i = Q-1; i >= 0; i--){
        if(op[i].first == 1){ // black 
            if(filledR.find(op[i].second) == filledR.end()){
                ans += leftCol.size();
                filledR.insert(op[i].second);
            }
        }else{ //white
            leftCol.erase(op[i].second);
        }
    }
    */
}
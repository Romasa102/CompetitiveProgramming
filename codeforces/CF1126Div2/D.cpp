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

bool is_between(ll val, ll low, ll high) {
    return val >= low && val <= high;
}
int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll> a;
        vector<ll> L(n),R(n);
        vector<P> LR;
        vector<ll> startPos;
        rep(i,n){
            cin >> L[i] >> R[i];
            LR.push_back({L[i],R[i]});
            startPos.push_back(L[i]);
            startPos.push_back(R[i]-m+1);
            a.push_back(L[i]);
            a.push_back(R[i]);
        }
        vector<ll> xs = a;                       // copy of values to compress
        sort(xs.begin(),xs.end());
        sort(LR.begin(),LR.end());
        sort(startPos.begin(),startPos.end());
        xs.erase(unique(xs.begin(),xs.end()), xs.end());
        auto id = [&](int x) { return int(lower_bound(xs.begin(),xs.end(), x) - xs.begin()); };
        
        ll cur = 0;
        ll curS = 0;
        ll ans = -1;
        ll dest = cur+m-1;
        bool haedDecreasing = false;
        bool tailIncreasing = false;
        P target = {cur,0};

        auto lri = upper_bound(LR.begin(), LR.end(), target);
        if (lri != LR.begin()) {
            --lri;
            if (lri->first <= cur && cur <= lri->second) haedDecreasing = true;
        }
        target = {dest,0};
        lri = upper_bound(LR.begin(),LR.end(),target);
        
        if (lri != LR.begin()) {
            --lri;
        }
        for(auto it = LR.begin(); it != lri; it++){
            if((*it).second <= dest){
                curS += (*it).second - (*it).first + 1;
            }else{
                curS += (dest - (*it).first);
                tailIncreasing = true;
            }
        }
        ll state = 0; //if increase : 1, neutral : 0, decrease : -1;
        if(haedDecreasing && !tailIncreasing){
            state = -1;
        }else if(!haedDecreasing && tailIncreasing){
            state = 1;
        }
        ll lb = curS + state * (startPos[1]-startPos[0]);
        if(is_between(k,min(curS,lb),max(curS,lb))){
            ans = startPos[cur] + abs(k - curS);
        }
        curS = lb;
        rep(i,startPos.size()){
            if(startPos[i]==0)continue;
            cur = startPos[i];
            dest = cur+m;
            
            target = {cur,0};
            lri = upper_bound(LR.begin(),LR.end(),target);
            if (lri != LR.begin()) {
                --lri;
            }
            if((*lri).first <= cur && cur <= (*lri).second)haedDecreasing=true;
            target = {dest,0};
            lri = upper_bound(LR.begin(),LR.end(),target);
            if (lri != LR.begin()) {
                --lri;
            }
            if((*lri).first <= dest && dest <= (*lri).second)tailIncreasing=true;
            ll state = 0; //if increase : 1, neutral : 0, decrease : -1;
            if(haedDecreasing && !tailIncreasing){
                state = -1;
            }else if(!haedDecreasing && tailIncreasing){
                state = 1;
            }
            ll lb = curS + state * (startPos[1]-startPos[0]);
            if(is_between(k,min(curS,lb),max(curS,lb))){
                ans = startPos[cur] + abs(k - curS);
            }
            curS = lb;
        }
        cout << ans << endl;
    }
}
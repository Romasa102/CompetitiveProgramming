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
        set<ll> startPos;
        rep(i,n){
            cin >> L[i] >> R[i];
            L[i]--;R[i]--;
            LR.push_back({L[i],R[i]});
            startPos.insert(L[i]);
            startPos.insert(R[i]+1);
            startPos.insert(max(0LL,R[i]-m+1));
            startPos.insert(max(0LL,L[i]-m));
            a.push_back(L[i]);
            a.push_back(R[i]);
        }
        startPos.insert(0);
        vector<ll> xs = a;                       // copy of values to compress
        sort(xs.begin(),xs.end());
        sort(LR.begin(),LR.end());
        xs.erase(unique(xs.begin(),xs.end()), xs.end());
        auto id = [&](int x) { return int(lower_bound(xs.begin(),xs.end(), x) - xs.begin()); };
        
        ll curS = 0;
        ll ans = -1;
        ll dest = m-1;
        bool haedDecreasing = false;
        bool tailIncreasing = false;
        P target = {0,1LL<<60};

        auto lri = upper_bound(LR.begin(), LR.end(), target);
        if (lri != LR.begin()) {
            --lri;
            if (lri->first <= 0 && 0 <= lri->second) haedDecreasing = true;
        }
        target = {dest,1LL<<60};
        lri = upper_bound(LR.begin(),LR.end(),target);
        for(auto it = LR.begin(); it != (lri); it++){
            if((*it).second <= dest){
                curS += (*it).second - (*it).first + 1;
            }else{
                curS += (dest - (*it).first+ 1);
                tailIncreasing = true;
            }
        }

        P tg = {m,1LL<<60};
        auto q = upper_bound(LR.begin(),LR.end(),tg);
        if (q != LR.begin()) {
            --q;
            if (q->first <= m && m <= q->second) tailIncreasing = true;
        }


        //cout << "lri is " << (*lri).first << endl;
        for(auto it = LR.begin(); it != (lri); it++){
            if((*it).second <= dest){
                curS += (*it).second - (*it).first + 1;
            }else{
                curS += (dest - (*it).first+ 1);
                tailIncreasing = true;
            }
            //cout << "curS initialization at : " << curS << endl;
        }
        ll state = 0; //if increase : 1, neutral : 0, decrease : -1;
        if(haedDecreasing && !tailIncreasing){
            state = -1;
        }else if(!haedDecreasing && tailIncreasing){
            state = 1;
        }
        ll lb = curS + state * (*(++startPos.begin())-*(startPos.begin()));
        if(is_between(k,min(curS,lb),max(curS,lb))){
            ans =* (startPos.begin()) + abs(k - curS);
        }
        curS = lb;
        for(auto it = startPos.begin(); it != startPos.end(); it++){

            haedDecreasing = false;
            tailIncreasing = false;
            auto i = (*it);
            if(i==0)continue;
            dest = i+m;
            
            target = {i,1LL<<60};
            lri = upper_bound(LR.begin(),LR.end(),target);
            if (lri != LR.begin()) {
                --lri;
            }
            if((*lri).first <= i && i <= (*lri).second)haedDecreasing=true;
            target = {dest,1LL<<60};
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
            auto nextIt = std::next(it);
            if (nextIt == startPos.end()) break;
            ll lb = curS + state * (*nextIt - i);

            //cout << "currently at " << i << "curS is : " << curS << " where its state is " << state << " and the reach is : " << lb << endl;
            if(is_between(k,min(curS,lb),max(curS,lb))){
                ans = i + abs(k - curS);
                //cout << "Passed at pos : " << i << "; with ans: " << ans << endl; 
            }
            curS = lb;
        }
        cout << (ans == -1 ? -1 : ans + 1) << endl;
    }
}
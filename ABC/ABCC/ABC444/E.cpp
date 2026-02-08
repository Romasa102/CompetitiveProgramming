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
int main(){
    ll N,D;cin >> N >> D;
    ll A[N];rep(i,N)cin >> A[i];
    ll ans=0;
    ll L = 0;
    set<P> cur;
    rep(R,N){
        P srch = {A[R],0};
        if(cur.empty()){
            ans+=(R-L+1);
            cur.insert({A[R],R});
            continue;
        }
        auto val1 = (lower_bound(cur.begin(),cur.end(),srch));
        if(val1==cur.end())val1=--(cur.end());
        auto val2 = val1;
        if(val1!=cur.begin())val2=(--lower_bound(cur.begin(),cur.end(),srch)); 
        while(!cur.empty()&& (abs((*val1).first-A[R])<D || abs((*val2).first-A[R])<D)){
            if(abs((*val1).first-A[R])<D){
                L=max(L,(*val1).second+1);
                cur.erase(val1);
            }
            if(val1!=val2 && abs((*val2).first-A[R])<D){
                L=max(L,(*val2).second+1);
                cur.erase(val2);
            }
            val1 = (lower_bound(cur.begin(),cur.end(),srch));
            if(val1==cur.end())val1=--(cur.end());
            val2=cur.begin();
            if(val1!=cur.begin()){
                val2 = (--lower_bound(cur.begin(),cur.end(),srch));
            }
        }
        cur.insert({A[R],R});
        //cout << L << " " << R << endl;
        ans+=(R-L+1);
    }
    cout << ans << endl;
}
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
    ll Q;
    cin >> Q;
    string S , T;
    cin >> S >> T;
    vector<P> range;
    rep(i, S.size() ) {
        if(S[i] == T[0]){
            bool match =true;
            rep(j,T.size()){
                if(i+j >= S.size()){
                    match = false;
                    break;
                }
                if(S[i+j] != T[j]){
                    match = false;
                }
            }
            if(match){
                range.push_back({i,i+T.size()-1});
            }
        }
    }
    rep(i,Q){
        ll L,R;
        cin >> L >> R;
        L--;R--;
        P rg = {L,0LL};
        if(!range.empty() && (*lower_bound(range.begin(),range.end(),rg)).second <= R && (*lower_bound(range.begin(),range.end(),rg)).second != 0){
            cout << "Yes" << endl;
        }else{
            cout <<"No" << endl;
        }
    }
}
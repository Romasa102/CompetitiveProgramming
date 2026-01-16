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
    ll N,K;
    cin >> N >> K;
    string S[N];
    rep(i,N)cin >> S[i];
    ll ans = 0;
    for(ll bit = 0; bit < (1<<N); ++bit){
        map<char,ll> mp;

        set<char> as;
        rep(i,N){
            if(bit & (1<<i)){
                rep(j,S[i].size()){
                    mp[S[i][j]]+=1;
                }
            }
        }
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it->second == K){
                as.insert(it->first);
            }
        }
        ans = max(ans,(ll) as.size());
    }
    cout << ans << endl;
}
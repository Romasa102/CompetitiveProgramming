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
    ll t;
    cin >> t;
    rep(_,t){
        ll a,b,x;
        cin >> a >> b >> x;
        vector<ll> adiv;
        vector<ll> bdiv;
        adiv.push_back(a);
        bdiv.push_back(b);
        while(a!=0){
            a/=x;
            adiv.push_back(a);
        }
        while(b!=0){
            b/=x;
            bdiv.push_back(b);
        }
        reverse(bdiv.begin(),bdiv.end());
        ll ans = 1LL<<40;
        rep(i,adiv.size()){
            ll ind = lower_bound(bdiv.begin(),bdiv.end(),adiv[i]) - bdiv.begin();
            if(ind == bdiv.size())ind--;
            ans = min(ans,(ll) (i+(bdiv.size()-ind-1)+abs(bdiv[ind]-adiv[i])));
            if(ind!=0){
                ans = min(ans,(ll) (i+(bdiv.size()-ind)+abs(bdiv[ind-1]-adiv[i])));
            }
        }
        cout << ans << endl;
    }
}
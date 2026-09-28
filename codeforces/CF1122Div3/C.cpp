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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> cumSZ(n+2,0);
        vector<ll> cumSO(n+2,0);
        rep(i,n){
            if(s[i]=='1'){
                cumSO[i+1] = cumSO[i]+1;
            }else{
                cumSO[i+1] = cumSO[i];
            }
            if(s[n-i-1] == '0'){
                cumSZ[n-i] = cumSZ[n-i+1]+1;
            }else{
                cumSZ[n-i]=cumSZ[n-i+1];
            }
        }
        /*
        rep(i,n+2){
            cout << cumSZ[i] << " ";
        }cout << endl;

        rep(i,n+2){
            cout << cumSO[i] << " ";
        }cout << endl;
        */
        ll ans = 1LL<<40;
        if(s[0]=='1'){
            ans = cumSZ[1];
        }else{
            rep(i,n+1){
                ans= min(ans,cumSZ[i+1]+cumSO[i]);
            }
        }
        cout << ans << endl;
    }
}
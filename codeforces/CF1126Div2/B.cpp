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
    ll t;cin >> t;
    rep(_,t){
        ll n,k;
        cin >> n >> k;
        ll a[n];
        map<ll,ll> mp;
        rep(i,n){
            cin >> a[i];
            mp[a[i]]++;
        }
        bool lose = true;
        rep(i,n){
            if(mp.find(i)==mp.end())break;
            if(mp[i]==k*2-1){
                lose = false;
                break;
            }
            if(mp[i] < k*2-1){
                lose = true;
                break;
            }
        }
        if(lose){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
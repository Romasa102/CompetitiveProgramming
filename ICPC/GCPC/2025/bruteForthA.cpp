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
    ll l,r;
    cin >> l >> r;
    deque<ll> left;
    deque<ll> right;
    ll cur = 1;
    rep(i,l){
        left.push_front(cur);
        cur++;
    }
    rep(i,r){
        right.push_back(cur);
        cur++;
    }
    set<P> ans;
    rep(i,(l+r)*2+1){
        ll a = left.front();
        ll b = right.front();
        if(a>b){
            ans.insert({b,a});   
        }else{
            ans.insert({a,b});
        }
        if(i%2==0){
            left.pop_front();
            right.push_back(a);
        }else{
            right.pop_front();
            left.push_back(b);
        }
    }
    cout << ans.size() << endl;
}
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
        ll n,k;
        cin >> n >> k;
        string str;
        cin >> str;
        vector<ll> s(n);
        rep(i,n){
            if(str[i]=='0'){
                s[i]=0;
            }else{
                s[i]=1;
            }
        }
        rep(i,n-k){
            if(s[i] == 1){
                s[i] = 0;
                if(s[i+k] == 0){
                    s[i+k]=1;
                }else{
                    s[i+k]=0;
                }
            }
        }
        bool ans = 0;
        rep(i,n){
            ans = (ans||s[i]);
        }
        if(!ans){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
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
        ll wh = n/2; // 0
        ll blk = n/2; // 1
        if(n%2!=0)blk++;
        if(k > wh+blk-2){
            cout << -1 << endl;
            continue;
        }
        ll dec = (wh+blk-2) - k;
        if(dec % 2 == 0){
            rep(i,dec/2){
                cout << "01";
                wh--;blk--;
            }

        }else{
            cout << 1;
            blk--;
            rep(i,(dec+1)/2-1){
                cout << "01";
                wh--;blk--;
            }
        }
        rep(i,wh){
            cout << "0";
        }
        rep(i,blk){
            cout << 1;
        }
        cout << endl;
    }
}
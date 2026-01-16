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
        ll s,k,t;
        cin >> s >> k >> t;
        ll lastFlip = t/k;
        ll timeElapsedSinceLastFlip = t % k;
        if(s >= k){
            if(lastFlip%2 == 0){
                cout << s-timeElapsedSinceLastFlip << endl;
            }else{
                cout << k - timeElapsedSinceLastFlip << endl;
            }
        }else{
            if(timeElapsedSinceLastFlip >= s){
                cout << 0 << endl;
            }else{
                if(lastFlip%2 == 0){
                    cout << s-timeElapsedSinceLastFlip << endl;
                }else{
                    cout << s - timeElapsedSinceLastFlip << endl;
                }
            }
        }
    }
}
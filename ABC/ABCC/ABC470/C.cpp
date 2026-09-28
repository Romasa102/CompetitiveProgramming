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
    vector<ll> bits(20,0); //if the number is odd itll be added.
    ll N,Q;
    cin >> N >> Q;
    vector<ll> num(N,0);
    set<ll> nonZ;
    
    rep(_,Q){
        ll task;
        cin >> task;
        if(task == 1){
            ll x;
            cin >> x;
            x--;
            rep(i,20){
                if(num[x] & (1<<i)){
                    bits[i]--;
                }
            }
            num[x]++;
            rep(i,20){
                if(num[x] & (1<<i)){
                    bits[i]++;
                }
            }
            nonZ.insert(x);
        }else if(task == 2){
            for (auto it = nonZ.begin(); it != nonZ.end(); ) {
                ll x = *it;

                rep(j, 20) {
                    if (num[x] & (1LL << j)) {
                        bits[j]--;
                    }
                }

                num[x]--;

                rep(j, 20) {
                    if (num[x] & (1LL << j)) {
                        bits[j]++;
                    }
                }

                if (num[x] == 0) {
                    it = nonZ.erase(it);
                } else {
                    ++it;
                }
            }
        }
        ll ans = 0;
        rep(i,20){
            if(bits[i] % 2 != 0){
                ans += (1 << i);
            }
        }
        cout << ans << endl;
    }
}
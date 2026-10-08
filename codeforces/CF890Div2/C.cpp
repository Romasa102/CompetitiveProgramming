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
        ll n,k;cin >> n >> k;
        ll a[n];rep(i,n)cin >> a[i];
        ll left = 0;
        ll right = 1000000000;
        while (right - left > 1)
        {
            ll mid = (left + right)/2;
            //cout << left << " " << right << " mid " << mid << endl;
            bool condition = false;
            rep(i,n){
                ll cost = k;
                ll ended = false;
                repp(j,i,n){
                    if(a[j]>=(mid-(j-i))){
                        ended = true;
                        break;
                    }else{
                        cost -= mid-(j-i)-a[j];
                        if(cost < 0)break;
                    }
                }
                //cout<< "start: " << i << " cost : " << cost << endl;
                if(cost >= 0 && ended){
                    condition = true;
                }
            }
            if(condition){
                left = mid;
            }else{
                right = mid;
            }
        }
        cout << left << endl;
    }
}
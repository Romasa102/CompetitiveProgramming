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
        ll a[n],b[n],c[n];

        vector<P> sums;
        rep(i,n){
            cin >> a[i] >> b[i] >> c[i];
            sums.push_back({a[i]+b[i]+c[i],i});
        }
        sort(sums.begin(),sums.end());
        ll left = -(1LL<<61);
        ll right = 1LL<<61; //[)
        while(right - left > 1){
            bool condition = true;
            ll mid = (left + right)/2;
            ll cost = k;
            rep(i,sums.size()){
                if(sums[i].first >= mid)break;
                ll ind = sums[i].second;
                bool work = (a[ind]-b[ind]>0) || (a[ind]-c[ind]>0) || (b[ind]-c[ind] > 0);
                if(work){
                    cost -= (mid - sums[i].first);
                }else{
                    ll costToMakeO = 1LL<<61;
                    if(a[ind] - b[ind] < 0){ // can make c small. So u need b > c || a > c
                        costToMakeO = min(costToMakeO,c[ind] - a[ind] + 1);
                        costToMakeO = min(costToMakeO,c[ind] - b[ind] + 1);
                    }
                    if(a[ind]-c[ind] < 0){ // can make b small so u need  a > b
                        costToMakeO = min(costToMakeO,b[ind] - a[ind] + 1);
                    }
                    cost -= 2 * costToMakeO;
                    cost -= (mid - sums[i].first);
                }
                if(cost < 0)condition = false;
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
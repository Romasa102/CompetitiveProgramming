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
    ll n,s;
    cin >> n >> s;
    double t[n];
    rep(i,n)cin >> t[i];
    double left = 0.0;
    double right = 2000000000.0;
    while(right - left > 0.000001){
        double mid = (left + right)/2;
        vector<ll> cnt(3,0);
        bool condition = true;
        rep(i,n){
            if((t[i] / 0.3) <= mid){
                cnt[2]++;
            }else if((t[i]/0.6) <= mid){
                cnt[1]++;
            }else if(t[i] <= mid){
                cnt[0]++;
            }else{
                condition = false;
                break;
            }
        }
        ll gapNeed = 0;
        rep(i,3){
            gapNeed += (2-i)*cnt[i];
        }
        if(gapNeed > 2 * (s-n) + 2){
            condition = false;
        }
       //cout << "gap need is " << gapNeed << endl;
        if(condition){
            right = mid;
        }else{
            left = mid;
        }
    }
    cout << fixed << setprecision(10)<< right << endl;
}
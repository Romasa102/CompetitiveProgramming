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
    ll N;
    cin >> N;
    vector<P> HS(N);
    rep(i,N){
        cin >> HS[i].first >> HS[i].second;
    }
    //binary template
    ll left = 0;
    ll right = 1e18;
    while(right - left > 1){
        ll mid = (left + right) / 2;
        vector<ll> Time(N,0);
        bool possible = true;
        rep(i,N){
            if(mid >= HS[i].first){
                Time[i] = (mid - HS[i].first) / HS[i].second;
            }
            else{
                possible = false;
            }
        }
        sort(Time.begin(),Time.end());
        rep(i,N){
            if(Time[i] < i){
                possible = false;
            }
        }
        if(possible)right = mid; //この高さで可能なら、それより低い高さでも可能（最小値を求めるから）
        else left = mid; //この高さで不可能なら、それより高さを上げる
    }
    cout << right << endl;
}
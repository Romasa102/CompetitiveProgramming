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
    ll N, K;
    cin >> N >> K;
    vector<P> RL(N);
    rep(i,N)cin >> RL[i].second >> RL[i].first;
    sort(RL.begin(),RL.end());
    vector<P> points;
    rep(i,N){
        points.push_back({RL[i].first,i});
        points.push_back({RL[i].second,i});
    }
    sort(points.begin(),points.end());
    vector<set<ll>> interferance(N);
    ll left =-1;
    ll right = 2000000000;
    while(right - left > 1){
        ll mid = (left + right) / 2;
        bool condition;
        vector<ll> picked;
        picked.push_back(0);
        ll cur = RL[0].first + mid;
        ll n = 1;
        while(n!=N){
            if(RL[n].second > cur){
                cur = RL[n].first + mid;
                picked.push_back(n);
            }
            n++;
        }
        if(picked.size() >= K){
            condition = true;
        }else{
            condition = false;
        }
        if(condition){
            left = mid;
        }else{
            right = mid;
        }
    }
    if(left == -1){
        cout << -1 << endl;
        return 0;
    }
    cout << left + 1<< endl;
}
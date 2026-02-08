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
    ll N;cin >> N;
    ll X[N],R[N];rep(i,N)cin >> X[i] >>  R[i];
    map<ll,set<ll>> mp;
    set<ll> ans;
    vector<ll> moved(N,false);
    rep(i,N){
        mp[X[i]+R[i]].insert(i);
        mp[X[i]-R[i]].insert(i);
    }
    priority_queue<P> q;
    rep(i,N){
        if(mp[X[i]+R[i]].size()==1){
            ans.insert(X[i]+R[i]);
            moved[i]=true;
            q.push({mp[X[i]-R[i]].size()-1,X[i]-R[i]});
            continue;
        }else if(mp[X[i]-R[i]].size()==1){
            ans.insert(X[i]-R[i]);
            moved[i]=true;
            q.push({i,X[i]-R[i]});
            continue;
        }
    }
    while(!q.empty()){
        P cur = q.top();
        ll ind = cur.second;
        for (auto it = mp[ind].begin(); it != mp[ind].end();) {
            if (moved[*it]) {
                it = mp[ind].erase(it); 
            } else {
                ++it; 
            }
        }
        
    }
}
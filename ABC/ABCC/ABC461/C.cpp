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
    ll N,K,M;
    cin >> N >> K >> M;
    P VC[N];
    rep(i,N){
        cin >> VC[i].second >> VC[i].first;
    }
    sort(VC,VC+N,greater<P>());
    vector<ll> ans;
    set<ll> firstT;
    stack<ll> secT;
    rep(i,K){
        if(firstT.find(VC[i].second)==firstT.end()){
            firstT.insert(VC[i].second);
            ans.push_back(VC[i].first);
        }else{
            secT.push(VC[i].first);
        }
    }
    ll cur = K;
    while(ans.size()<M){
        if(firstT.find(VC[cur].second)==firstT.end()){
            secT.pop();
            firstT.insert(VC[cur].second);
            ans.push_back(VC[cur].first);
        }
        cur++;
    }
    ll fans = 0;
    rep(i,ans.size()){
        fans+=ans[i];
    }
    while(!secT.empty()){
        fans+=secT.top();
        secT.pop();
    }
    cout << fans << endl;
}
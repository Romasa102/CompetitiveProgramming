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
    ll N,D;
    cin >> N >> D;
    ll X[N];
    rep(i,N)cin >> X[i];

    vector<P> num;
    rep(i,N){
        num.push_back({X[i],i});
    }
    sort(num.begin(),num.end());
    
    vector<ll> ans;
    if(num[1].first - num[0].first >= D){
        ans.push_back(num[0].second);
    }
    repp(i,1,N-1){
        if(num[i].first - num[i-1].first >= D && num[i+1].first - num[i].first >= D){
            ans.push_back(num[i].second);
        }
    }

    if(num[N-1].first - num[N-2].first >= D){
        ans.push_back(num[N-1].second);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    rep(i,ans.size()){
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}
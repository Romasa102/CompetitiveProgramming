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
    ll A[N];
    rep(i,N)cin >> A[i];
    vector<P> fiveN;
    map<ll,vector<ll>> sevenM;
    map<ll,vector<ll>> threeM;
    map<ll,P> divided;
    rep(i,N){
        if(A[i]%7 == 0){
            sevenM[A[i]/7].push_back(i);
            divided[A[i]/7]={i,7};
        }
        if(A[i]%5 == 0){
            fiveN.push_back({A[i]/5,i});
            divided[A[i]/5]={i,5};
        }
        if(A[i]%3 == 0){
            threeM[A[i]/3].push_back(i);
            divided[A[i]/3]={i,3};
        }
    }
    ll ans = 0;
    rep(i,fiveN.size()){
        ll pivot = fiveN[i].second;
        ll div = fiveN[i].first;
        ans += ((upper_bound(sevenM[div].begin(),sevenM[div].end(),pivot)-sevenM[div].begin()) * 
                (upper_bound(threeM[div].begin(),threeM[div].end(),pivot)-threeM[div].begin()));
        ans += ((sevenM[div].size()-(lower_bound(sevenM[div].begin(),sevenM[div].end(),pivot)-sevenM[div].begin())) * 
                (threeM[div].size()-(lower_bound(threeM[div].begin(),threeM[div].end(),pivot)-threeM[div].begin())));
    }   
    cout << ans << endl;       
}

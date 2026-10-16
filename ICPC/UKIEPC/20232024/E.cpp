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
double intersect(P a, P b){
    return ((double)(b.second - a.second))/((double)(a.first - b.first));
}
int main(){
    ll n;
    cin >> n;
    ll h[n];
    rep(i,n)cin >> h[i];
    deque<pair<double,P>> line; // beginpoitn,  gradient, intercept
    vector<ll> dp;
    dp[0]=0;
    rep(i,n){
        
        while(
            !line.empty() &&
            intersect(line.back().second,{-2*i,dp[i] + (i+1)*(i+1)})
                 < line.back().first
        ){
            line.pop_back();
        }
        if(line.empty()){
            line.push_back({
                0.0,
                {-2*i,dp[i] + (i+1)*(i+1)}}
            );
        }else{
            line.push_back({
                max(0.0,intersect(line.back().second,{-2*i,dp[i] + (i+1)*(i+1)})),
                {-2*i,dp[i] + (i+1)*(i+1)}}
            );
        }
    }

}
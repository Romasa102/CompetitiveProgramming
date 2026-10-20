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
double intersect(ll gradO, ll interceptO, ll gradT, ll interceptT){
    return ((double)(interceptT - interceptO) / (double)(gradO - gradT));
}
int main(){
    ll N,M;cin >> N >> M;
    ll B[N];rep(i,N)cin >> B[i];
    ll C[M];rep(i,M)cin >> C[i];
    sort(B,B+N);

    vector<P> lines;//gradient, interception
    rep(i,N){
        lines.push_back({(i+1),B[N-1-i] * (i+1)});
    }
    vector<pair<double,P>> intersection;
    intersection.push_back({0,lines[0]});
    repp(i,1,lines.size()){
        //cout << "lines with index " << i << " has grad " << lines[i].first << " intercept of " << lines[i].second << endl;
        while
            (!intersection.empty() &&intersect(intersection.back().second.first,intersection.back().second.second,
                lines[i].first,lines[i].second) < intersection.back().first){
            intersection.pop_back();
        }
        if(intersection.empty()){
            intersection.push_back({0,lines[i]});
        }else{
            intersection.push_back({
                max(0.0,
    intersect(intersection.back().second.first,intersection.back().second.second,lines[i].first,lines[i].second))
                    ,lines[i]});
        }
    }

    rep(i,M){
        pair<double,P> target = {(double)C[i],{0LL,0LL}};
        auto it = lower_bound(intersection.begin(),intersection.end(),target);
        if(it!=intersection.begin()){
            it--;
        }
        //cout << it-intersection.begin() << " " << (*it).second.first  << " " << (*it).second.second << endl;
        cout << (*it).second.first * C[i] + (*it).second.second << " ";
    }cout << endl;
}
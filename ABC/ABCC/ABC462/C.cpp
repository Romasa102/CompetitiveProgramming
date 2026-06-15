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
    P XY[N];
    rep(i,N)cin >> XY[i].first >> XY[i].second;
    sort(XY,XY+N);
    vector<bool> itsok(N,true);
    ll minY = 1LL<<50;
    rep(i,N){
        if(XY[i].second > minY){
            itsok[i] = false;
        }else{
            minY = XY[i].second;
        }
    }
    ll count = 0;
    rep(i,N)if(itsok[i])count++;
    cout << count << endl;
}
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
bool compare(P f,P s){//{x,y}
    if(f.second<0&&s.second>0)return true;
    if(f.second>0&&s.second<0)return false;
    return ((f.first * s.second - s.first * f.second)>0);
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    P point[N];
    rep(i,N)cin>>point[i].first>>point[i].second;
    sort(point,point+N,compare);
    vector<ll> totalSum(N);
    
}
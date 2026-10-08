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
    ll N,K;
    cin >> N >> K;
    ll A[N];
    rep(i,N)cin >> A[i];
    vector<ll> na;
    repp(i,1,N){
        if(A[i] < A[i-1]){
            na.push_back(i);
        }
    }
    sort(na.begin(),na.end());
    ll fstN = na[0];
    ll lstN = na[na.size()-1];
    ll numN = lstN - fstN + 1;
    if(numN > K){
        cout << "No" << endl;
        return 0;
    }
    ll minN = 1LL<<30;
    ll maxN = 0;
    repp(i,fstN,lstN+1){
        minN = min(minN,A[])
    }
}
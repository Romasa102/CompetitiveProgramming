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
    map<ll,vector<ll>> ally;
    ll N,M;
    cin >> N >> M;
    ll A[M],B[M];
    rep(i,M){
        cin >> A[i] >> B[i];
        ally[A[i]].push_back(B[i]);
        ally[B[i]].push_back(A[i]);
    }
    repp(i,1,N+1){

        ll as = (N-ally[i].size());
        if(as<=3){
            cout << 0 << " ";
            continue;
        }else{
            cout << ((as-3)*(as-1)*(as-2)/(6LL)) << " ";
        }
    }
}
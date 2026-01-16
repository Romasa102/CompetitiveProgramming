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
    stack<P> q;
    q.push({A[0],1});
    repp(i,1,N){
        if((!q.empty()) && q.top().first == A[i]){
            q.top().second++;
            if(q.top().second == 4)q.pop();
        }else{
            q.push({A[i],1});
        }
    }
    ll ans = 0;
    while(!q.empty()){
        ans += q.top().second;
        q.pop();
    }
    cout << ans << endl;
}
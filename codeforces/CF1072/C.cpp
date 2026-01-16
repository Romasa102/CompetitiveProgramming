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
    ll t;
    cin >> t;
    rep(_,t){
        ll n,k;
        cin >> n >> k;
        queue<P> q;
        q.push({n,0});
        ll ans = 1LL<<50;
        set<ll> visited;
        while(!q.empty()){
            P cur = q.front();
            q.pop();
            if(cur.first == k){
                ans = min(ans,cur.second);
                break;
            }
            if(cur.first < k)continue;
            if(cur.first == 1)continue;
            if(cur.first%2==0){
                if(visited.find(cur.first/2) == visited.end()){
                    visited.insert(cur.first/2);
                    q.push({cur.first/2,cur.second+1});
                }
            }else{
                if(visited.find(cur.first/2) == visited.end()){
                    visited.insert(cur.first/2);
                    q.push({cur.first/2,cur.second+1});
                }
                if(visited.find(cur.first/2+1) == visited.end()){
                    visited.insert(cur.first/2+1);
                    q.push({cur.first/2+1,cur.second+1});
                }
            }
        }
        if(ans == 1LL<<50){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
}
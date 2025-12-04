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
vector<ll> parent;
ll find(ll o){
    if(o == parent[o])return o;
    return parent[o] = find(parent[o]);
}
void unite(ll a,ll b){
    parent[find(a)] = parent[find(b)];
}
int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll N;
        cin >> N;
        parent.resize(N);
        rep(i,N)parent[i]=i;
        ll p[N];
        rep(i,N)cin >> p[i];
        set<P> curMin = {{p[0],0}};
        ll ans = 0;
        repp(i,1,N){
            for(auto cur : curMin){
                if(p[i] > cur.first){
                    unite(i,cur.second);
                    if(cur != *(curMin.begin())&& curMin.size()!=1){
                        curMin.erase(cur);
                    }
                }else{
                    curMin.insert({p[i],i});
                    break;
                }
            }
        }
        set<P, greater<P>> curMax = {{p[N-1], N-1}};
        repp(i,2,N+1){
            for(auto cur : curMax){
                if(p[N-i] < cur.first){
                    unite(N-i,cur.second);
                    if(cur != *(curMax.begin())&& curMax.size()!=1){
                        curMax.erase(cur);
                    }
                }else{
                    curMax.insert({p[N-i],N-i});
                    break;
                }
            }
            
        }
        ll work = true;
        rep(i,N-1){
            if(parent[i]!=parent[i+1]){
                work = false;
            }
        }
        if(work){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
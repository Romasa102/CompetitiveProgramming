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
    ll N,Q;cin >> N >> Q;
    vector<bool> tile(N,false);
    vector<ll> lastTimeTile(N,0);
    vector<ll> lastTimeRelease(N,0);
    vector<pair<ll,char>> col;
    col.push_back({0,'a'});
    ll lastPaint = 0;
    vector<char> ans(N,'a');
    rep(i,Q){
        ll task;
        cin >> task;
        if(task == 1){
            ll X;cin >> X;X--;
            if(tile[X]){
                tile[X] = false;
                lastTimeRelease[X]=i+1;
            }else{
                tile[X] = true;
                if(lastPaint > lastTimeRelease[X]){
                    ans[X] = col[col.size()-1].second;
                }
            }
        }else{
            char c;
            cin >> c;
            col.push_back({i+1,c});
            lastPaint = i+1;
        }
    }
    rep(i,N){
        if(!tile[i] &&lastPaint > lastTimeRelease[i]){
            ans[i] = col[col.size()-1].second;
        }
        cout << ans[i];
    }cout << endl;
}
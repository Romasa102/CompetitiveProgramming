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
    ll H,W,Q;
    cin >> H >> W >> Q;
    ll R[Q],C[Q];
    char X[Q];
    vector<vector<ll>> grid(H,vector<ll>(W,0));
    rep(i,Q){ cin >> R[i] >> C[i];R[i]--;C[i]--;cin >> X[i]; };
    for(ll i = Q; i>0; i--){
        for(ll x = R[i-1]; x>= 0; x--){
            if(grid[x][W-1] != 0){break;}
            for(ll y = C[i-1];y >= 0; y--){
                if(grid[x][y]!=0){break; }
                grid[x][y]=i;
            }
        }
    }
    rep(i,H){
        rep(j,W){
            if(grid[i][j]==0){
                cout << "A";
            }else{
                cout << X[grid[i][j]-1];
            }
        }cout << "\n";
    }
}
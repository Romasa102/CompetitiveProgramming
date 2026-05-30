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
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H)cin >> S[i];
    queue<P> Q;
    queue<P> WQ;
    vector<vector<ll>> ans(H,vector<ll>(W));
    vector<vector<ll>> ansW(H,vector<ll>(W));
    rep(i,H){
        rep(j,W){
            ans[i][j]=-1;
            ansW[i][j]=-1;
            if(S[i][j]=='#'){
                Q.push({i,j});
                ans[i][j]=0;
            }else{
                WQ.push({i,j});
                ansW[i][j]=0;
            }
        }
    }
    ll xs[8] = {0,0 ,1,1, 1,-1,-1,-1};
    ll ys[8] = {1,-1,0,1,-1, 0, 1,-1};
    while(!Q.empty()){
        P cur = Q.front();
        Q.pop();
        rep(i,8){
            ll x = cur.first;
            ll y =cur.second;
            if(x+xs[i] < 0 || x+xs[i] >= H || y+ys[i] < 0 || y+ys[i] >= W)continue;
            if(ans[x+xs[i]][y+ys[i]]==-1){
                ans[x+xs[i]][y+ys[i]] = ans[x][y]+1;
                Q.push({x+xs[i],y+ys[i]});
            }
        }
    }
    while(!WQ.empty()){
        P cur = WQ.front();
        WQ.pop();
        rep(i,8){
            ll x = cur.first;
            ll y =cur.second;
            if(x+xs[i] < 0 || x+xs[i] >= H || y+ys[i] < 0 || y+ys[i] >= W)continue;
            if(ansW[x+xs[i]][y+ys[i]]==-1){
                ansW[x+xs[i]][y+ys[i]] = ansW[x][y]+1;
                WQ.push({x+xs[i],y+ys[i]});
            }
        }
    }
    ll piv = ans[0][0];
    bool allSame = true;
    rep(i,H){
        rep(j,W){
            if(ans[i][j]!=piv)allSame = false;
        }
    }
    if(allSame){
        rep(i,H){
            rep(j,W){
                cout << '.';
            }
            cout << endl;
        }
        return 0;
    }
    rep(i,H){
        rep(j,W){
            if((ans[i][j]%2==0 && S[i][j] == '.') || (ansW[i][j]%2==1 && S[i][j] == '#')){
                cout << '#';
            }else{
                cout << '.';
            }
        }cout << endl;
    }
}
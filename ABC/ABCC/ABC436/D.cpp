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
    map<char,deque<P>> mp;
    string S[H];
    rep(i,H)cin >> S[i];
    bool visited[H][W];
    vector<vector<pair<int, int>>> ls(26);
    vector<bool> seen(26,false);
    rep(i,H){
        rep(j,W){
            if(S[i][j]!='.' && S[i][j]!='#')ls[S[i][j]-'a'].push_back({i,j});
        }
    }
    rep(i,H)rep(j,W)visited[i][j]=false;
    queue<pair<P,ll>> q;
    q.push({{0,0},0});
    ll xs[4] = {1,0,-1,0};
    ll ys[4] = {0,1,0,-1};
    ll ans = -1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        ll x = cur.first.first;
        ll y = cur.first.second;
        ll dis = cur.second;
        if(x==H-1 && y == W-1){
            ans = dis;
            break;
        }
        rep(i,4){
            if(x+xs[i]<0 || x+xs[i]>=H || y+ys[i]<0 || y+ys[i]>=W)continue;
            if(S[x+xs[i]][y+ys[i]]=='#'||visited[x+xs[i]][y+ys[i]])continue;
            visited[x+xs[i]][y+ys[i]]=true;
            q.push({{x+xs[i],y+ys[i]},dis+1});
        }
        if(S[x][y]!='.'){
            if(seen[S[x][y]-'a'])continue;
            seen[S[x][y]-'a']=true;
            for(auto cur : ls[S[x][y]-'a']){
                if(!visited[cur.first][cur.second]){
                    visited[cur.first][cur.second]=true;
                    q.push({{cur.first,cur.second},dis+1});
                }
            }
        }
    }
    cout << ans << endl;
}
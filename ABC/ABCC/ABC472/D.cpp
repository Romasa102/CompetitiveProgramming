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
    ll H,W,K;
    cin >> H >> W >> K;
    string S[H];
    rep(i,H)cin >> S[i];
    vector<bool> bombX(H,false);
    vector<bool> bombY(W,false);
    
    rep(i,H){
        rep(j,W){
            if(S[i][j] == '#'){
                bombX[i] = true;
                bombY[j] = true;
            }
        }
    }
    queue<P> safe;

    vector<vector<ll>> visited(H,vector<ll>(W,-1));
    rep(i,H){
        rep(j,W){
            if(!bombX[i] && !bombY[j]){
                safe.push({i,j});
                visited[i][j] = 0;
            }
        }
    }
    ll dx[4] = {0,1,0,-1};
    ll dy[4] = {1,0,-1,0};
    while(!safe.empty()){
        P cur = safe.front();
        safe.pop();
        ll cx = cur.first;
        ll cy = cur.second;
        rep(i,4){
            ll newX = cx + dx[i];
            ll newY = cy + dy[i];
            if(newX<0||newX>=H||newY<0||newY>=W)continue;
            if(visited[newX][newY]==-1 && S[newX][newY] != '#'){
                visited[newX][newY] = visited[cx][cy]+1;
                safe.push({newX,newY});
            }
        }
    }
    ll ans = 0;
    rep(i,H){
        rep(j,W){
            if(visited[i][j] <= K && visited[i][j] != -1){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
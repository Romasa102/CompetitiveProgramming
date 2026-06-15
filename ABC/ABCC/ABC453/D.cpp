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
enum class Direction {
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3
};
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H){
        cin >> S[i];
    }
    queue<pair<P,Direction>> Q; //direction that is moving before enter
    P beginP;
    P endP;
    bool visited[H][W][4];
    pair<P,Direction> parents[H][W][4];
    rep(i,H){
        rep(j,W){
            if(S[i][j] == 'S'){
                beginP = {i,j};
            }
            if(S[i][j] == 'G'){
                endP = {i,j};
            }
            rep(k,4){
                visited[i][j][k]=false;
            }
        }
    }
    ll xs[4] = {-1,0,1,0};
    ll ys[4] = {0,-1,0,1};
    Direction dirs[4] = {Direction::UP, Direction::LEFT, Direction::DOWN,Direction::RIGHT};
    Q.push({beginP,Direction::UP});
    visited[beginP.first][beginP.second][0]=true;
    visited[beginP.first][beginP.second][1]=true;
    visited[beginP.first][beginP.second][2]=true;
    visited[beginP.first][beginP.second][3]=true;
    parents[beginP.first][beginP.second][0] = {{-1,-1},Direction::UP};
    parents[beginP.first][beginP.second][1] = {{-1,-1},Direction::UP};
    parents[beginP.first][beginP.second][2] = {{-1,-1},Direction::UP};
    parents[beginP.first][beginP.second][3] = {{-1,-1},Direction::UP};
    auto PairOverFlow = [&](ll x, ll y) -> bool {
        return x >= H || x < 0 || y < 0 || y >= W;
    };
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        ll x = cur.first.first;
        ll y = cur.first.second;
        Direction dir = cur.second;
        if(
            S[x][y] == '.' ||
            S[x][y]  == 'S'
        ){
            rep(i,4){
                ll nx = x+xs[i];
                ll ny = y+ys[i];
                Direction ndir = dirs[i];

                if(PairOverFlow(nx,ny))continue;
                if(S[nx][ny]=='#')continue;
                if(visited[nx][ny][(int)ndir])continue;

                if(S[nx][ny] == '.' || S[nx][ny]  == 'S'){
                    rep(i,4){
                        visited[nx][ny][i]=true;
                    }
                }else{
                    visited[nx][ny][(int)ndir]=true;
                }
                parents[nx][ny][(int)ndir] = {{x,y},dir};
                Q.push({{nx,ny},ndir});
            }
        }else if(
            S[x][y] == 'o' // must be same dir
        ){
            ll nx = x+xs[(int)dir];
            ll ny = y+ys[(int)dir];
            Direction ndir = dir;

            if(PairOverFlow(nx,ny))continue;
            if(S[nx][ny]=='#')continue;
            if(visited[nx][ny][(int)ndir])continue;

            if(S[nx][ny] == '.' || S[nx][ny]  == 'S'){
                rep(i,4){
                    visited[nx][ny][i]=true;
                }
            }else{
                visited[nx][ny][(int)ndir]=true;
            }
            parents[nx][ny][(int)ndir] = {{x,y},dir};
            Q.push({{nx,ny},ndir});
        }else if(
            S[x][y] == 'x' // must be diff dir
        ){
            rep(i,4){
                if(i == (int)dir)continue;
                ll nx = x+xs[i];
                ll ny = y+ys[i];
                Direction ndir = dirs[i];

                if(PairOverFlow(nx,ny))continue;
                if(S[nx][ny]=='#')continue;
                if(visited[nx][ny][(int)ndir])continue;

                if(S[nx][ny] == '.' || S[nx][ny]  == 'S'){
                    rep(i,4){
                        visited[nx][ny][i]=true;
                    }
                }else{
                    visited[nx][ny][(int)ndir]=true;
                }
                parents[nx][ny][(int)ndir] = {{x,y},dir};
                Q.push({{nx,ny},ndir});
            }
        }else if(S[x][y] == 'G') {
            cout << "Yes" << endl;
            vector<Direction> path;
            
            P curP = {x, y};
            Direction curDir = dir;
            
            while(curP != (P){-1LL, -1LL}) {
                auto [parentP, parentDir] = parents[curP.first][curP.second][(int)curDir];
                path.push_back(curDir);
                curDir = parentDir;
                curP = parentP;
            }
            path.pop_back();

            reverse(path.begin(), path.end());
            for(auto d : path) {
                if(d == Direction::UP)         cout << "U";
                else if(d == Direction::LEFT)  cout << "L";
                else if(d == Direction::DOWN)  cout << "D";
                else if(d == Direction::RIGHT) cout << "R";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
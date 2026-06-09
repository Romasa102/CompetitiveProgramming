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
    UP,
    LEFT,
    DOWN,
    RIGHT
};
map<pair<P,Direction>,bool> visited;
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
    rep(i,H){
        rep(j,W){
            if(S[i][j] == 'S'){
                beginP = {i,j};
            }
            if(S[i][j] == 'G'){
                endP = {i,j};
            }
        }
    }
    Q.push({beginP,Direction::UP});
    while(!Q.empty()){
        auto cur = Q.front();
        if(
            S[cur.first.first][cur.first.second] == '.' ||
            S[cur.first.first][cur.first.second] == 'S' ||
            S[cur.first.first][cur.first.second] == 'G' ||
        ){
            
        }
    }
}
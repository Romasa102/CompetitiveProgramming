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
    while(t--){
        ll N,C;
        cin >> N >> C;
        string S[N];
        rep(i,N)cin >> S[i];
        vector<queue<ll>> destroyable(N);
        rep(i,N){
            for(ll j = N-1;j>=0;j--){
                if(S[i][j]=='#'){
                    destroyable[j].push(i);
                }
            }
        }
        P init = {N-1,C-1};
        queue<P> q;
        q.push(init);
        vector<bool> ans(N,false);

        vector<vector<bool>> visited(N,vector<bool>(N,false));
        
        while(!q.empty()){
            P cur = q.front();q.pop();
            ll x = cur.first;ll y=cur.second;
            if(x==0){
                ans[y]=true;
                continue;
            }
            ll dys[] = {-1, 0, 1};
            for(ll dy : dys) {
                ll nx = x - 1;
                ll ny = y + dy;
                if(ny >= 0 && ny < N) {
                    bool is_wall = (S[nx][ny] == '#');
                    if (!is_wall ||(!destroyable[ny].empty()&&destroyable[ny].front()==(nx))) {
                        q.push({nx, ny});
                        destroyable[ny].pop();
                    }
                }
            }
        }
        rep(i,N){
            rep(j,N)cout << visited[i][j];
            cout << endl;
        }
        rep(i,N)cout << ans[i];
        cout << endl;
    }
}
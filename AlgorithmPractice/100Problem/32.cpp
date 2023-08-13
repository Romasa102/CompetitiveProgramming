#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll w,h;
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0)break;
        ll wall[2 * w - 1][2 * h - 1];
        rep(i,2*h-1){
            rep(j,2 * w -1){
                wall[j][i] = -1;
            }
        }
        rep(i,2 * h - 1){
            if(i%2 == 0){
                rep(j,w-1){
                    cin >> wall[j*2+1][i];
                }
            }else{
                rep(j,w){
                    cin >> wall[2 * j][i];
                }
            }
        }
        queue<P> Q;
        Q.push({0,0});
        ll dis[w][h];
        rep(i,h){
            rep(j,w){
                dis[i][j] = -1;
            }
        }
        dis[0][0] = 0;
        while(Q.size()){
            ll x = Q.front().first;
            ll y = Q.front().second;
            if(x+1 < w-1 && wall[x+1][y] == 0 && dis[(x+2)/2][y/2] == -1){
                dis[(x+2)/2][y/2] = dis[x/2][y/2] + 1;
                Q.push({x+2,y});
            }else if(y+1 < h-1 && wall[x][y+1] == 0 && dis[x/2][(y+2)/2] == -1){
                dis[x/2][(y+2)/2] = dis[x/2][y/2] + 1;
                Q.push({x,y+2});
            }else if(x-1 > 0 && wall[x-1][y] == 0 && dis[(x-2)/2][y/2] == -1){
                dis[(x-2)/2][y/2] = dis[x/2][y/2] + 1;
                Q.push({x-2,y});
            }else if(y-1>0 && wall[x][y-1] == 0 && dis[x/2][(y-2)/2] == -1){
                dis[x/2][(y-2)/2] = dis[x/2][y/2] + 1;
                Q.push({x,y-2});
            }
            Q.pop();
        }
        if(dis[w-1][h-1] == -1){
            cout << 0 << endl;
            continue;
        }
        cout << dis[w-1][h-1] << endl;
    }

}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll W,H;
    cin >> W >> H;
    ll dxE[6] = {1,-1,0,0,1,1};
    ll dyE[6] = {0,0,-1,1,-1,1};

    ll dxO[6] = {1,-1,0,0,-1,-1};
    ll dyO[6] = {0,0,-1,1,-1,1};
    ll maps[W][H];
    rep(i,H){
        rep(j,W){
            cin >> maps[j][i];
        }
    }
    ll ans = 0;
    bool searched[W][H];
    rep(i,H){
        rep(j,W){
            searched[j][i] = false;
        }
    }
    rep(i,H){
        rep(j,W){
            if(searched[j][i])continue;
            if(maps[j][i] == 0){
                queue<P> CQ;
                CQ.push({j,i});
                vector<P> Group;
                bool TouchSide = false;
                while(CQ.size()){
                    ll x = CQ.front().first;
                    ll y = CQ.front().second;
                    if(searched[x][y]){
                        CQ.pop();
                        continue;
                    }
                    if(x == 0 || x == W-1 || y == 0 || y == H-1){
                        TouchSide = true;
                    }
                    Group.push_back(CQ.front());
                    searched[x][y] = true;
                    rep(m,6){
                        if(y%2 == 1 && maps[x+dxO[m]][y+dyO[m]] == 0 && x + dxO[m] < W && x + dxO[m] >= 0 && y + dyO[m] < H && y + dyO[m] >= 0){
                            if(!searched[x+dxO[m]][y+dyO[m]]){
                                CQ.push({x+dxO[m],y+dyO[m]});
                            }
                        }
                        else if(y%2 == 0&& maps[x+dxE[m]][y+dyE[m]] == 0&& x + dxE[m] < W && x + dxE[m] >= 0 && y + dyE[m] < H && y + dyE[m] >= 0){
                            if(!searched[x+dxE[m]][y+dyE[m]]){
                                CQ.push({x+dxE[m],y+dyE[m]});
                            }
                        }
                    }
                }
                if(!TouchSide){
                    rep(i,Group.size()){
                        maps[Group[i].first][Group[i].second] = 1;
                    }
                }
            }
        }
    }
    rep(i,H){
        rep(j,W){
            searched[j][i] = false;
        }
    }
    rep(i,H){
        rep(j,W){
            if(searched[j][i])continue;
            if(maps[j][i] == 1){
                queue<P> Q;
                Q.push({j,i});
                while(Q.size()){
                    ll x = Q.front().first;
                    ll y = Q.front().second;
                    if(searched[x][y]){
                        Q.pop();
                        continue;
                    }
                    ll surroundingC = 0;
                    searched[x][y] = true;
                    rep(m,6){
                        if(y%2 == 1 && maps[x+dxO[m]][y+dyO[m]] == 1 && x + dxO[m] < W && x + dxO[m] >= 0 && y + dyO[m] < H && y + dyO[m] >= 0){
                            surroundingC++;
                            if(!searched[x+dxO[m]][y+dyO[m]]){
                                Q.push({x+dxO[m],y+dyO[m]});
                            }
                        }
                        else if(y%2 == 0&& maps[x+dxE[m]][y+dyE[m]] == 1&& x + dxE[m] < W && x + dxE[m] >= 0 && y + dyE[m] < H && y + dyE[m] >= 0){
                            surroundingC++;
                            if(!searched[x+dxE[m]][y+dyE[m]]){
                                Q.push({x+dxE[m],y+dyE[m]});
                            }
                        }
                    }
                    ans+=(6-surroundingC);
                    Q.pop();
                }
            }
        }
    }
    cout << ans << endl;
}
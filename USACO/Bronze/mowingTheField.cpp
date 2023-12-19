#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("mowing.in","r",stdin);
    ll N;
    cin >> N;
    char D[N];
    ll dist[N];
    ll Fsize = N*10+100;
    vector<vector<ll>> farm(Fsize*2,vector<ll>(Fsize*2,-1));
    ll curT = 0;
    P curP = {Fsize,Fsize};
    ll ans = 1LL<<60;
    farm[curP.first][curP.second]=curT;
    rep(i,N){
        cin >> D[i] >> dist[i];
        rep(j,dist[i]){
            curT++;
            if(D[i] == 'N'){//up
                curP.second++;
            }else if(D[i] == 'E'){//right
                curP.first++;
            }else if(D[i] == 'S'){//down
                curP.second--;
            }else if(D[i] == 'W'){//left
                curP.first--;
            }
            if(farm[curP.first][curP.second]==-1){
                farm[curP.first][curP.second] = curT;
            }else{
                ans = min(ans,curT - farm[curP.first][curP.second]);
                farm[curP.first][curP.second] = curT;
            }
        }
    }
    freopen("mowing.out","w",stdout);
    if(ans == 1LL<<60){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
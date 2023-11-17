#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
P axis[4]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H){
        cin >> S[i];
    }
    queue<P> num;
    bool found[H][W];
    ll dis[H][W];
    rep(i,H){
        rep(j,W){
            found[i][j]=false;
            dis[i][j]=1LL<<32;
        }
    }
    num.push({0,0});
    dis[0][0]=0;
    while(!num.empty()){
        P cur = num.front();
        num.pop();
        if(found[cur.first][cur.second])continue;
        found[cur.first][cur.second]=true;
        rep(i,4){
            if(cur.first+axis[i].first<0||cur.first+axis[i].first>=H)continue;
            if(cur.second+axis[i].second<0||cur.second+axis[i].second>=W)continue;
            if(S[cur.first+axis[i].first][cur.second+axis[i].second]!=S[cur.first][cur.second]){
                if(found[cur.first+axis[i].first][cur.second+axis[i].second])continue;
                dis[cur.first+axis[i].first][cur.second+axis[i].second]=dis[cur.first][cur.second]+1;
                num.push({cur.first+axis[i].first,cur.second+axis[i].second});
            }
        }
    }
    if(dis[H-1][W-1]==1LL<<32){
        cout << -1 << endl;
    }else{
        cout << dis[H-1][W-1] << endl;
    }
}
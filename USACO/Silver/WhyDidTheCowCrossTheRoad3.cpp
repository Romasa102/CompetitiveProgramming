#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
int main(){
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);
    ll N,K,R;cin>>N>>K>>R;
    P STRT[R],ENDP[R];
    rep(i,R){
        cin >> STRT[i].first >> STRT[i].second >> ENDP[i].first >> ENDP[i].second;
        STRT[i].first--;STRT[i].second--;ENDP[i].first--;ENDP[i].second--;
    }
    P cows[K];
    map<P,bool> cowExst;
    rep(i,K){
        cin >> cows[i].first >> cows[i].second;
        cows[i].first--;cows[i].second--;
        cowExst[{cows[i].first*2,cows[i].second*2}]=true;
    }
    queue<P> Q;
    vector<vector<bool>> visited(N*2,vector<bool>(N*2,false));
    vector<ll> grp;
    rep(i,R){
        if(STRT[i].first==ENDP[i].first){
            ll t = (STRT[i].second*2+ENDP[i].second*2)/2;
            visited[STRT[i].first*2][t] = true;
            visited[STRT[i].first*2+1][t] = true;
            if(STRT[i].first*2 > 0)
                visited[STRT[i].first*2-1][t] = true;
        }
        if(STRT[i].second==ENDP[i].second){
            ll t = (STRT[i].first*2+ENDP[i].first*2)/2;
            visited[t][STRT[i].second*2] = true;
            visited[t][STRT[i].second*2+1] = true;
            if(STRT[i].second*2 > 0)
                visited[t][STRT[i].second*2-1] = true;
        }
    }
    ll cowCnt;
    while(true){
        bool found = false;
        rep(i,N){
            rep(j,N){
                if(!visited[2*i][2*j]){
                    Q.push({2*i,2*j});
                    found = true;
                    break;
                }
            }if(found)break;
        }if(!found)break;
        cowCnt = 0;
        while(!Q.empty()){
            P cur = Q.front();Q.pop();
            if(visited[cur.first][cur.second])continue;
            visited[cur.first][cur.second]=true;
            if(cowExst.find({cur.first,cur.second})!=cowExst.end()){
                cowCnt++;
                cowExst.erase({cur.first,cur.second});
            }
            rep(i,4){
                if(cur.first+dx[i]<0||cur.first+dx[i]>=2*N||cur.second+dy[i]<0||cur.second+dy[i]>=2*N)continue;
                if(visited[cur.first+dx[i]][cur.second+dy[i]])continue;
                Q.push({cur.first+dx[i],cur.second+dy[i]});
            }
        }
        if(cowCnt!=0){
            grp.push_back(cowCnt);
        }
    }
    ll ans = 0;
    if(grp.size()==0){
        cout << 0 << endl;return 0;
    }
    rep(i,grp.size()-1){
        repp(j,i+1,grp.size()){
           // cout << i << j << grp[i] << grp[j] << endl;
            ans += grp[i]*grp[j];
        }
    }
    cout << ans << endl;
}
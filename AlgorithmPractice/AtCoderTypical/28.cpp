#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll memo[1100][1100];
    ll memo2[1100][1100];
    ll overlap[1100][1100];
    rep(i,1100)rep(j,1100){
            memo[i][j]=0;
            memo2[i][j]=0;
            overlap[i][j]=0;
        }
    rep(i,N){
        ll lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        lx--;ly--;rx--;ry--;
        memo[lx][ly]++;
        memo[rx][ly]--;
        memo[rx][ry]++;
        memo[lx][ry]--;
    }
    ll cur = 0;
    rep(j,1100){
        cur=0;
        rep(i,1100){
            cur += memo[i][j];
            memo2[i][j]=cur;
        }
    }
    rep(i,10){
        rep(j,10){
            cout << memo2[i][j] << " ";
        }cout<<endl;
    }
    map<ll,ll> ans;
    rep(i,1100){
        cur=0;
        rep(j,1100){
            cur += memo2[i][j];
            ans[cur]++;
            overlap[i][j]=cur;
        }
    }
    repp(i,1,N+1){
        if(ans.find(i)!=ans.end()){
            cout << ans[i] << endl;
        }else{
            cout << 0 << endl;

        }
    }
}
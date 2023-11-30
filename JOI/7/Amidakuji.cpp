#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,m,h,k;
    cin >> n >> m >> h >> k;
    ll line[n][h];
    rep(i,n)rep(j,h)line[i][j]=false;
    ll score[n];
    rep(i,n)cin >> score[i];
    queue<P> Que;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--;
        Que.push({a,b});
        line[a][b]=true;
    }
    ll dpFromT[n][h];
    ll dpFromB[n][h];
    vector<ll> num;
    rep(i,n)num.push_back(i);
    rep(j,n)dpFromT[0][j]=num[j];
    repp(i,1,h){
        rep(j,n){
            if(line[i][j]){
                swap(num[j],num[j+1]);
            }
        }
        rep(j,n){
            dpFromT[i][j]=num[j];
        }
    }
    num.clear();
    rep(i,n)num.push_back(i);
    rep(j,n)dpFromT[0][j]=num[j];
    for(ll i = h-1;i > 0;i--){
        rep(j,n){
            if(line[i][j]){
                swap(num[j],num[j+1]);
            }
        }
        rep(j,n){
            dpFromB[i][j]=num[j];
        }
    }
    rep(i,m){
        P cur = Que.front();
        Que.pop();

    }
}
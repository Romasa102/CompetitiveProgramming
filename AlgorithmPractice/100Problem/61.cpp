#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll a[M];
    ll b[M];
    ll t[M];
    rep(i,M){
        cin >> a[i] >> b[i] >> t[i];
    }
    ll length[N][N];
    rep(i,N){
        rep(j,N){
            length[i][j] = 1LL<<60;
        }
    }
    rep(i,N){
        length[i][i] = 0;
    }
    rep(i,M){
        length[a[i]-1][b[i]-1] = t[i];
        length[b[i]-1][a[i]-1] = t[i];
    }
    rep(k,N){
        rep(i,N){
            rep(j,N){
                if(length[i][j] > length[i][k] + length[k][j]){
                    length[i][j] = length[i][k] + length[k][j];
                }
            }
        }
    }
    ll MAXLength[N];
    rep(i,N){
        MAXLength[i] = 0;
    }
    rep(i,N){
        rep(j,N){
            MAXLength[i] = max(MAXLength[i],length[i][j]);
        }
    }
    ll smallest = 1LL<<60;
    rep(i,N){
        smallest = min(MAXLength[i],smallest);
    }
    cout << smallest << endl;
}
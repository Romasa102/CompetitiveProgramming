#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M,N,K;
    cin >> M >> N >> K;
    string Planet[M];
    rep(i,M){
        cin >> Planet[i];
    }
    ll Jungle[M+1][N+1];
    ll Ocean[M+1][N+1];
    ll Ice[M+1][N+1];
    rep(i,M+1){
        rep(j,N+1){
            Jungle[i][j] = 0;
            Ocean[i][j] = 0;
            Ice[i][j] = 0;
        }
    }
    rep(i,M){
        rep(j,N){
            Jungle[i+1][j+1] = Jungle[i+1][j] + Jungle[i][j+1] - Jungle[i][j];
            Ocean[i+1][j+1] = Ocean[i+1][j] + Ocean[i][j+1] - Ocean[i][j];
            Ice[i+1][j+1] = Ice[i+1][j] + Ice[i][j+1] - Ice[i][j];
            if(Planet[i][j] == 'J'){
                Jungle[i+1][j+1]++;
            }else if(Planet[i][j] == 'O'){
                Ocean[i+1][j+1]++;
            }else if(Planet[i][j] == 'I'){
                Ice[i+1][j+1]++;
            }
        }
    }
    rep(i,K){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << Jungle[c][d] - Jungle[a-1][d] - Jungle[c][b-1] + Jungle[a-1][b-1] << " ";
        cout << Ocean[c][d] - Ocean[a-1][d] - Ocean[c][b-1] + Ocean[a-1][b-1] << " ";
        cout << Ice[c][d] - Ice[a-1][d] - Ice[c][b-1] + Ice[a-1][b-1]  << endl;
    }
}
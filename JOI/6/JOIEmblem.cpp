#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M,N;
    cin >> M >> N;
    string A[M];
    rep(i,M) cin >> A[i];
    string Emblem[2];
    cin >> Emblem[0] >> Emblem[1];
    ll ans = 0;
    ll memo[M][N][3];
    rep(i,M)rep(j,N)rep(k,3)memo[i][j][k] = 0;
    ll maxA = 0;
    rep(i,M-1)rep(j,N-1){
            ll cnt = 0;
            ll a,b;
            a=0;
            b=0;
            rep(k,2)rep(l,2){
                    if(A[i+k][j+l] == Emblem[k][l]) {
                        cnt++;
                    }else{
                        a = k;
                        b = l;
                    }
                }
            if(cnt == 3) {
                if(Emblem[a][b] == 'J') memo[a+i][b+j][0]++;
                if(Emblem[a][b] == 'O') memo[a+i][b+j][1]++;
                if(Emblem[a][b] == 'I') memo[a+i][b+j][2]++;
                maxA=max({maxA,memo[a+i][b+j][0],memo[a+i][b+j][1],memo[a+i][b+j][2]});
                cout << a << b << endl;
                continue;
            }
            if(cnt == 4) {
                ans++;
                continue;
            }
        }
    cout << ans + maxA << endl;
}
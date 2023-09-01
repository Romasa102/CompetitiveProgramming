#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S[N];
    string T[N];
    rep(i,N){
        cin >> S[i];
    }
    rep(i,N){
        cin >> T[i];
    }
    char Change[N][N];
    char ChangeB[N][N];
    rep(i,N){
        rep(j,N){
            Change[i][j] = S[i][j];
        }
    }
    ll ans = 1000000000;
    rep(k,4){
        ll Diff = min(k,4-k);
        rep(i,N){
            rep(j,N){
                ChangeB[i][j] = Change[i][j];
                if(Change[i][j] != T[i][j]){
                    Diff++;
                }
            }
        }
        ans = min(Diff,ans);
        rep(i,N){
            rep(j,N){
                Change[i][j] = ChangeB[N-j-1][i];
            }
        }
    }
    cout << ans << endl;
}
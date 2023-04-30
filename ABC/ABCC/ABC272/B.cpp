#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll k;
    bool YES[N][N];
    rep(i,N){
        rep(j,N){
            YES[i][j] = false;
        }
    }
    rep(i,M){
        cin >> k;
        ll A[k];
        rep(j,k){
            cin >> A[j];
        }
        rep(j,k){
            for(int m = j+1; m<k;m++){
                YES[A[j]-1][A[m]-1] = true;
            }
        }
    }
    rep(j,N){
        for(int m = j+1; m < N;m++){
            if(YES[j][m] != true){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
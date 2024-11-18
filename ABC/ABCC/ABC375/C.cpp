#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string A[N];
    rep(i,N)cin >> A[i];
    string B[N];
    rep(i,N)B[i] = A[i];
    rep(i,N){
        rep(j,N){
            ll iden = min({i,j,N-i-1,N-j-1});
            if(iden%4 == 0){
                B[i][j]=A[N-j-1][i];
            }else if(iden%4 == 1){
                B[i][j]=A[N-i-1][N-j-1];
            }else if(iden%4 == 2){
                B[i][j]=A[j][N-i-1];
            }
        }
    }
    rep(i,N){
        cout << B[i] << endl;
    }
}
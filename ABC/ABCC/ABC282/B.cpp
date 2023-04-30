#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    bool A[N][M];
    rep(i,N){
        rep(j,M){
            char O;
            cin >> O;
            if(O == 'o'){
                A[i][j] = true;
            }else if(O == 'x'){
                A[i][j] = false;
            }
        }
    }
    bool failed = false;
    ll count = 0;
    rep(i,N){
        rep(j,N){
            failed = false;
            rep(k,M){
                if(i == j){
                    failed = true;
                }
                if(!A[i][k]&&!A[j][k]){
                    failed = true;
                }
            }
            if(failed == false){
                count ++;
            }
        }
    }
    cout << count/2 << endl;
}
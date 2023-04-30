#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    int N,M;
    cin >> N >> M;
    ll A[N][M];
    bool ans = true;
    rep(i,N){
        rep(j,M){
            cin >> A[i][j]; 
        }
    }
    rep(i,N - 1){
        rep(j,M){
            if(A[i + 1][j] - A[i][j] != 7){
                ans = false;
            }
        }
    }
    rep(j,M - 1){
        if(A[0][j + 1] - A[0][j] != 1){
            ans = false;
        }
    }
    rep(j,M - 1){
        if(A[0][j] % 7 == 0){
            ans = false;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
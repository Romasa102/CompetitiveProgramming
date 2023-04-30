#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    char A[N][N];
    rep(i,N){
        rep(j,N){
            cin >> A[i][j];
        }
    }
    rep(i,N){
        rep(j,N){
            if(A[i][j] == 'W'){
                if(A[j][i] != 'L'){
                    cout << "incorrect" << endl;
                    return 0;
                }
            }else if(A[i][j] == 'L'){
                if(A[j][i] != 'W'){
                    
                    cout << "incorrect" << endl;
                    return 0;
                }
            }else if(A[i][j] == 'D'){
                if(A[j][i] != 'D'){
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "correct" << endl;
}
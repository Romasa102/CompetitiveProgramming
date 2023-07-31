#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    int A[N][N];
    string B[N];
    rep(i,N){
        cin >> B[i];
        rep(j,N){
            A[i][j] = B[i][j] - '0';
        }
    }
    rep(i,N){
        rep(j,N){
            if(i == 0){
                if(j == 0){
                    cout << A[i+1][j];
                    continue;
                }
                cout << A[i][j-1];
                continue;
            }
            if(j == 0){
                if(i == N-1){
                    cout << A[i][j+1];
                    continue;
                }
                cout << A[i+1][j];
                continue;
            }
            if(i == N-1){
                if(j == N-1){
                    cout << A[i-1][j];
                    continue;
                }
                cout << A[i][j+1];
                continue;
            }
            if(j == N-1){
                if(i == 0){
                    cout << A[i][j-1];
                    continue;
                }
                cout << A[i-1][j];
                continue;
            }
            cout << A[i][j];
        }
        cout << endl;
    }
}
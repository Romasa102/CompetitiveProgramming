#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N][N];
    rep(i,N){
        rep(j,N){
            cin >> A[i][j];
        }
    }
    bool root[N][N];
    rep(i,N){
        rep(j,N){
            root[i][j] = true;
        }
    }
    rep(k,N){
        rep(i,N){
            rep(j,N){
                if(i == j)continue;
                if(i == k)continue;
                if(j == k)continue;
                if(A[i][j] == A[i][k] + A[k][j]){
                    root[i][j] = false;
                }
            }
        }
    }
    ll length[N][N];
    ll ans = 0;
    rep(i,N){
        rep(j,N){
            if(root[i][j]){
                length[i][j] = A[i][j];
                ans += length[i][j];
            }else{
                length[i][j] = 1LL << 60;
            }
        }
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
    rep(i,N){
        rep(j,N){
            if(length[i][j] != A[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout<< ans/2 << endl;
}
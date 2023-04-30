#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll A[N];
    ll B[N];
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }
    bool dpA[N];
    bool dpB[N];
    rep(i,N){
        dpA[i] = false;
        dpB[i] = false;
    }
    dpA[0] = true;
    dpB[0] = true;
    rep(i,N - 1){
        if(dpA[i] == true){
            if(abs(A[i + 1] - A[i]) <= K){
                dpA[i+1] = true;
            }
            if(abs(B[i + 1] - A[i]) <= K){
                dpB[i+1] = true;
            }
        }
        if(dpB[i] == true){
            if(abs(B[i + 1] - B[i]) <= K){
                dpB[i+1] = true;
            }
            if(abs(A[i + 1] - B[i]) <= K){
                dpA[i+1] = true;
            }
        }
        if(dpA[i + 1] == false && dpB[i + 1] == false){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
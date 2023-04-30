#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,K,Q;
    cin >> N >> K >> Q;
    ll A[K];
    ll L[Q];
    bool B[N];
    rep(i,N){
        B[i] = false;
    }
    rep(i,K){
        cin >> A[i];
        B[A[i] - 1] = true;
    }
    int h;
    rep(i,Q){
        cin >> h;
        if(h != N && B[A[h-1]-1] == true && B[A[h-1]] == false){
            B[A[h-1]-1] = false;
            B[A[h-1]] = true;
        } 
    }
    rep(i,N){
        if(B[i] == true){
            cout << i + 1 << endl;
        }
    }
}
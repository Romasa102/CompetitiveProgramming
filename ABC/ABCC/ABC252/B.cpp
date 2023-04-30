#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll A[N];
    ll B[K];
    ll max = 0;
    rep(i,N){
        cin >> A[i];
        if(A[i]>max){
            max = A[i];
        }
    }rep(i,K){
        cin >> B[i];
    }
    rep(i,N){
        if(A[i] == max){
            rep(j,K){
                if(i+1 == B[j]){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
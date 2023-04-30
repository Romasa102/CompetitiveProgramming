#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll X,A,D,N,K;
    cin >> X >> A >> D >> N;
    if(D!=0){
        K = (X-A)/D;
    }
    if(abs(X-A-D*K) > abs(X-A-D*(K+1))){
        if(abs(X-A-D*(K+1)) > abs(X-A-D*(K-1))){
            K = K-1;
        }else{
            K=K+1;
        }
    }else{
        if(abs(X-A-D*K)>abs(X-A-D*(K-1))){
            K = K-1;
        }
    }
    if(K<0){
        K = 0;
    }
    K = A + (D*K);
    if(D >= 0){
        if(K > A+D*(N-1)){
            K = A+D*(N-1);
        }
        if(K < A){
            K=A;
        }
    }else{
        if(K > A){
            K=A;
        }
        if(K < A+D*(N-1)){
            K = A+D*(N-1);
        }
    }
    cout << abs(K-X) << endl;
}
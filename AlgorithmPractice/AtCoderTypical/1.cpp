#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,L,K;
    cin >> N >> L >> K;
    ll A[N+2];
    A[0] = 0;
    repp(i,1,N+1)cin >> A[i];
    A[N+1] = L;
    ll B[N+1];
    rep(i,N+1){
        B[i] = A[i+1]-A[i];
    }
    ll left = 0;
    ll right = L;
    while(right - left > 1){
        ll x = (right+left)/2;
        ll current = 0;
        ll count = 0;
        rep(i,N+1){
            current+=B[i];
            if(current>=x){
                count++;
                current=0;
            }
        }
        if(count >= K+1){
            left = x;
        }else{
            right = x;
        }
    }
    cout << left << endl;
}878 932 449
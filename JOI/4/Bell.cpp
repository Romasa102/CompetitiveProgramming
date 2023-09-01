#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    ll A[N];
    ll B[M];
    rep(i,N)cin >> A[i];
    rep(i,M)cin >> B[i];
    rep(i,M){
        if(lower_bound(A,A+N,B[i]) != )
    }
}
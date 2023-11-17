#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll K,N;//K,N<3001
    cin >> K >> N;
    ll A[N];//<10^9
    priority_queue<P> num;
    rep(i,N){
        cin >> A[i];
        num.push({A[i],i});
    }

}
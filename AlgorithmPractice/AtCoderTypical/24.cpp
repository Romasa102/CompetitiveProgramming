#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll A[N];
    ll B[N];
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> B[i];
    ll ans = 0;
    rep(i,N){
        ans += abs(A[i]-B[i]);
    }
    if(ans>K){
        cout << "No" << endl;
    }else{
        if((K-ans)%2==0){
            cout << "Yes" << endl;
            return 0;
        }
        cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,X;
    cin >> N;
    ll A[N];
    ll sum = 0;
    rep(i, N){
        cin >> A[i];
        sum += A[i];
    }cin >> X;
    ll ans;
    ans += (X/sum)*N;
    X%=sum;
    rep(i,N){
        X -= A[i];
        ans++;
        if(X < 0){
            break;
        }
    }
    cout << ans << endl;
}
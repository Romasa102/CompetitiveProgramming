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
    rep(i,N){
        cin >> A[i];
        if(A[i]%K == 0){
            cout << A[i]/K << " ";
        }cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    ll ans = 0;
    rep(i,N){
        if(A[i] == 1){
            ans++;
        }
    }
    ll minAns = ans;
    rep(i,N){
        if(A[i] == 0){
            ans++;
        }else{
            ans--;
            minAns = min(ans,minAns);
        }
    }
    cout << minAns << endl;
}
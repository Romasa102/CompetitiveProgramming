#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll X[N];
    ll Y[N];
    ll CumS[N+1];
    CumS[0] = 0;
    rep(i,N){
        cin >> X[i] >> Y[i];
        if((CumS[i]-CumS[i-X[i]]) > Y[i]){
            CumS[i+1] = CumS[i]+1'
        }else{
            CumS[i+1] = CumS[i];
        }
    }
    cout << CumS[N] << endl;
}
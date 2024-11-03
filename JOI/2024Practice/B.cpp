#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A = 0,B = 0;
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        if(a>b){
            A++;
        }else if(b>a){
            B++;
        }
    }
    cout << A   << " " << B << endl;
}
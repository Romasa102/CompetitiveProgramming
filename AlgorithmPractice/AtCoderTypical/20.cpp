#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll d = 1;
    rep(i,b){
        d*=c;
    }
    if(a<d){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
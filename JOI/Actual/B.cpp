#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll a,b,c;
    cin >> a >>b >> c;
    if(a+b==c || a+c==b || b+c==a){
        cout << 1 << endl;
        return 0;
    }
    cout << 0 << endl;
}
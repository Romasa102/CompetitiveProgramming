#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n;
    cin >> n;
    ll fibonach[n+1];
    fibonach[0] = 1;
    fibonach[1] = 1;
    if(n < 2){
        cout << 1 << endl;
        return 0;
    }
    rep(i,2,n+1){
        fibonach[i] = fibonach[i-1] + fibonach[i-2];
    }
    cout << fibonach[n] << endl;
}
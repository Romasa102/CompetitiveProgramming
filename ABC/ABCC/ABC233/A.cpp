#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,X;
    cin>> X >> N;
    ll ans;
    ans = N - X;
    if(ans < 0){
        cout << 0 << endl;
    }else if(ans % 10 == 0){
        cout << ans / 10 << endl;
    }else{
        cout << (ans/10) + 1 << endl;
    }
}
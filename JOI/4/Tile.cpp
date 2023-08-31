#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll K;
    cin >> K;
    ll m;
    cin >> m;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        if(K%2 == 0){
            if(a > K/2){
                a = K-a+1;
            }
            if(b > K/2){
                b = K-b+1;
            }
        }else{
            if(a > (K+1)/2){
                a = K+1-a;
            }
            if(b > (K+1)/2){
                b = K+1-b;
            }
        }
        ll pri = min(a,b);
        if(pri%3 == 0){
            cout << 3 << endl;
        }else if(pri%3 == 1){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }

}
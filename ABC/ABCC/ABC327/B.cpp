#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll B;
    cin >> B;
    repp(i,1,17){
        ll num = 1;
        repp(j,1,i+1){
            num*=i;
        }
        if(B==num){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
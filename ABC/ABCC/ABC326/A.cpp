#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll X,Y;
    cin >> X >> Y;
    if(X<Y){
        if((Y-X)<=2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        if((X-Y)<=3){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
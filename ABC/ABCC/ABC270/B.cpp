#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll X,Y,Z;
    cin >> X >> Y >> Z;
    if(Y > 0){
        if(Y < X){
            if(Y < Z){
                cout << "-1" << endl;
                return 0;
            }else if(0<Z){
                cout << X << endl;
                return 0;
            }else if(Z<0){
                cout << X-Z+abs(Z) << endl;
                return 0;
            }
        }else{
            cout << abs(X) << endl;
        }
    }else{
        if(Y > X){
            if(Z<Y){
                cout << "-1" << endl;
            }else if(0<Z){
                cout << Z+Z-X << endl;
            }else if(0>Z){
                cout << abs(X);
            }
        }else{
            cout << abs(X);
        }
    }
}
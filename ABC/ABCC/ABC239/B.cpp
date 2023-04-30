#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll X;
    cin >> X;
    if(X < 0){
        if(X%10 == 0){
            cout << X/10 << endl;
            return 0;
        }
        cout << X/10 - 1 << endl;
        return 0;
    }
    cout << X/10 << endl;
    return 0;
}
#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll a,b;
    cin >> a >> b;
    if(abs(a - b) == 1 || abs(a - b) == 9){
        cout << "Yes" << endl;
        return 0;
    }cout << "No" << endl;
}
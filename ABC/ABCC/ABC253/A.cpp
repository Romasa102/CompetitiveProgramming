#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    if(a <= b && b <= c){
        cout << "Yes" << endl;
        return 0;
    }else if(c <= b && b <= a){
        cout << "Yes" << endl;
        return 0;
    }else{
        cout << "No" << endl;
    }
}
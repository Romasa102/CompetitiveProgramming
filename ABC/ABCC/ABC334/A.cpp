#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll B,G;
    cin >> B >> G;
    if(B>G){
        cout << "Bat" << endl;
    }else{
        cout << "Glove" << endl;
    }
}
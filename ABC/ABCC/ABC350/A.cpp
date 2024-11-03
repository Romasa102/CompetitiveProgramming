#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    ll n = 0;
    rep(i,6){
        if(i>2){
            n += (S[i]-'0')*pow(10,6-i-1);
        }
    }
    if(n < 350){
        if(n!=316 && n!= 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
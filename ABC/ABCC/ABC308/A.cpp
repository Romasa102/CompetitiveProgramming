#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll S[8];
    rep(i,8){
        cin >> S[i];
        if(S[i] < 100){
            cout << "No" << endl;
            return 0;
        }
        if(675 < S[i]){
            cout << "No" << endl;
            return 0;
        }
        if(S[i]%25 != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,7){
        if(S[i] > S[i+1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
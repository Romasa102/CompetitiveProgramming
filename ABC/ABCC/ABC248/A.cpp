#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    bool ended = false;
    rep(i,10){
        ended = false;
        rep(j,9){
            if(i == S[j] - '0'){
                ended = true;
            }
        }
        if(ended == false){
            cout << i << endl;
        }
    }
}
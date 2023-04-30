#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S,T;
    cin >> S >> T;
    string A = "abcdefghijklmnopqrstuvwxyz";
    rep(i,27){
        rep(j,S.length()){
            if(S[j] != 'z'){
                S[j] += 1;
            }else if(S[j] == 'z'){
                S[j] -= 25;
            }
        }
        if(S == T){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
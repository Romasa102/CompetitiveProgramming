#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S,T;
    cin >> S >> T;
    int M;
    if(S.length() > T.length()){
        cout << "No" << endl;
        return 0;
    }
    rep(i,S.length()){
        if(S[i]!=T[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
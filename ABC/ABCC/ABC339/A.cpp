#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    for(ll i =  S.size(); i >=0; i--){
        if(S[i] == '.'){
            cout << S.substr(i+1,S.size()-i-1) << endl;
            return 0;
        }
    }
}

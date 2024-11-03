#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    if(S[0]  > 'Z'){
        cout << "No" << endl;
        return 0;
    }
    repp(i,1,S.size()){
        if('a'> S[i] ){
            cout << "No" << endl;
            return 0 ;
        }
    }
    cout << "Yes" << endl;
}
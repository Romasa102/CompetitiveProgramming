#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    rep(i,N-1){
        if(S[i]=='a'&&S[i+1]=='b'){
            cout << "Yes" << endl;
            return 0;
        }
        if(S[i]=='b'&&S[i+1]=='a'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
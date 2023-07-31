#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    bool a,b,c;
    a = false;
    b = false;
    c = false;
    rep(i,N){
        if(S[i] == 'A') a = true;
        if(S[i] == 'B') b = true;
        if(S[i] == 'C') c = true;
        if(a&&b&&c){
            cout << i+1 << endl;
            return 0;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    repp(i,2,S.size()){
        if(S[i-2] == 'A' && S[i-1] == 'B' && S[i] == 'C'){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
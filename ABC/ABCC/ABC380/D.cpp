#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;

char toUpper(char c) {
    return ('a' <= c && c <= 'z') ? ('A' + c - 'a') : c;
}

char toLower(char c) {
    return ('A' <= c && c <= 'Z') ? ('a' + c - 'A') : c;
}
int main(){
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    ll K[Q];
    rep(i,Q)cin >> K[i];
    rep(i,Q){
        ll num = (K[i]-1)/S.size();
        ll attempt = 0;
        while (num != 0) {
            ll hightwo = 1LL << (63 - __builtin_clzll(num));
            num -= hightwo;
            attempt++;
        }
        if(attempt%2 == 1){//flip
            if ('a' <= S[(K[i]-1) % S.size()] && S[(K[i]-1) % S.size()] <= 'z') {
                cout << (char)toUpper(S[(K[i]-1) % S.size()]) << " ";
            } else {
                cout << (char)toLower(S[(K[i]-1) % S.size()]) << " ";
            }
        }else{//noramal
            cout << S[(K[i]-1)%S.size()] << " ";
        }
    }
    cout << endl;
}
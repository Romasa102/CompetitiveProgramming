#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    string S,T;
    cin >> T >> S;
    string Top = S.substr(0,T.size());
    string End = S.substr(S.size()-T.size()-1,T.size());
    if(Top == T&&End == T){
        cout << 0 << endl;
        return 0;
    }
    if(Top == T && End != T){
        cout << 1 << endl;
        return 0;
    }
    if(Top != T && End == T){
        cout << 2 << endl;
        return 0;
    }
    if(Top != T && End != T){
        cout << 3 << endl;
        return 0;
    }
}
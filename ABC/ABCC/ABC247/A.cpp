#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    char c[4];
    rep(i,4){
        c[i] == S[i];
    }
    cout << "0";
    rep(i,3){
        cout << c[i+1];
    }cout << endl;
}
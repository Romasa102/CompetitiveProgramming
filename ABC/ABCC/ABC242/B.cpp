#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    vector<char> c(S.size());
    rep(i,S.size()){
        c[i] = S[i];
    }
    sort(c.begin(),c.end());
    rep(i,S.size()){
        cout << c[i];
    }cout << endl;
}
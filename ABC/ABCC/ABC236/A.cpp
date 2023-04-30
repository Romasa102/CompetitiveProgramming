#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    int a,b;
    cin >> S;
    cin >> a >> b;
    string c,d;
    c = S[a - 1];
    d = S[b - 1];
    S.replace(a - 1,1,d);
    S.replace(b - 1,1,c);
    cout << S << endl;
}
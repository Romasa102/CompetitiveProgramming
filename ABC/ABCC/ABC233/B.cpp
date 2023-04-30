#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    int L,R;
    cin >> L >> R;
    string A;
    cin >> A;
    string K = A.substr(L -1,(R - L + 1));
    A.erase(L - 1,R - L + 1);
    reverse(K.begin(),K.end());
    string ans = A.insert(L - 1,K);
    cout  << ans << endl;
}
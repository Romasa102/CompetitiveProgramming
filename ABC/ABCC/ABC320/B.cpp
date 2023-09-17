#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    ll ans = 0;
    rep(i,S.size()-1){
        repp(j,i,S.size()){
            string a = S.substr(i,j-i+1);
            string b = a;
            reverse(a.begin(),a.end());
            if(a==b){
                ans = max(ans,j-i+1);
            }
        }
    }cout << ans << endl;
}
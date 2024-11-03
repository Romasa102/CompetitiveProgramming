#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    vector<ll> count(30,0);
    rep(i,S.size()){
        count[S[i]-'a']++;
    }
    ll maxC = 0;
    rep(i,30){
        maxC = max(maxC,count[i]);
    }
    char ans = 'a';
    rep(i,30){
        if(maxC == count[i]){
            ans += i;
            cout << ans << endl;
            return 0;
        }
    }
}
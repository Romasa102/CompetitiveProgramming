#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string s;
    cin >> s;
    ll ans = 0;
    rep(i,s.size()){
        if(s[i]=='o'){
            ans++;
        }
    }
    if(ans%2==0){
        cout << "even" << endl;
    }else{
        cout << "odd" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n;
        cin >> n; 
        string s;
        cin >> s;
        map<char,bool> down;
        ll ans = 0;
        rep(i,n/2+1){
            while(down.find(s[i]) != down.end()){
                s[i]--;
            }
            while(down.find(s[n-1-i]) != down.end()){
                s[n-1-i]--;
            }
            if(s[i] != s[n-1-i]){
                char lar = max(s[i],s[n-1-i]);
                char sm = min(s[i],s[n-1-i]);
                while(lar != sm){
                    if(down.find(lar) != down.end()){
                        lar--;
                    }else{
                        ans++;
                        down[lar]=true;
                        lar--;
                    }
                }
            }
        }
        cout << ans << endl;

    }
}
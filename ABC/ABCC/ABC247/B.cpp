#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string s[N];
    string t[N];
    string a[N];
    rep(i,N){
        cin >> s[i] >> t[i];
    }
    bool still = true;
    ll r;
    rep(i,N){
        rep(j,N){
            if(i!=j){
            if(s[i]==s[j]||s[i]==t[i]){
                still = false;
            }

            }
        }
        if(still  = false){
            rep(j,N){
                if(i!=j){
                if(s[i]==s[j]||s[i]==t[i]){
                    cout << "No" << endl;
                    return 0;
                }
                
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
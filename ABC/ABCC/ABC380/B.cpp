#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    ll cur = 0;
    vector<ll> ans;
    rep(i,S.size()){
        if(S[i] == '|'){
            if(cur != i){
                ans.push_back(i-cur-1);
                cur =i;
            }
        }
    }
    rep(i,ans.size()){
        cout << ans[i] << " ";
    }cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    string ans;
    bool start = false;
    rep(i,S.size()){
        if(S[i] == '|'){
            if(!start){
                start = true;
            }else{
                start = false;
            }
        }
        if(!start && S[i] != '|'){

            ans += S[i];
        }
    }
    cout << ans << endl;
}
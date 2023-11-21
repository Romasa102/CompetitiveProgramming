#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll con =  0;
    ll ans =0 ;
    rep(i,N){
        if(S[i]=='>'){
            con++;
            ans += con;
        }else{
            con=0;
        }
    }
    cout << ans << endl;
}
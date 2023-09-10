#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define revrep(i,n) for(ll i = (n-1); i >= (0); --i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H){
        cin >> S[i];
    } //J(i,j) O(i,l) I(k,j)
    vector<P> J;
    map<ll,ll> O;
    map<ll,ll> I;
    ll ans = 0;
    revrep(i,H){
        revrep(j,W){
            if(S[i][j] == 'J'){
                ans += O[i] * I[j];
            }else if(S[i][j] == 'O'){
                O[i]++;
            }else{
                I[j]++;
            }
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,k;
    cin >> n >> k;
    ll Num[k];
    map<ll,bool> have;
    bool white = false;
    rep(i,k){
        cin >> Num[i];
        if(Num[i] == 0){
            white = true;
            continue;
        }
        have[Num[i]] = true;
    }
    sort(Num,Num+k);
    ll ans = 0;
    ll cont = 1;
    ll beforeCon = 0;
    if(!white) {
        rep(i,k - 1) {
            if (Num[i]+1 == Num[i + 1]) {
                cont++;
            }else{
                cont = 1;
            }
            ans = max(ans,cont);
        }
        cout << ans << endl;
    }else{
        repp(i,1,k-1){
            if(Num[i]+1 == Num[i+1]){
                cont++;
            }else{
                if(Num[i]+2 == Num[i+1]){
                    beforeCon = cont+1;
                    cont = 1;
                }else{
                    beforeCon = 0;
                    cont = 1;
                }
            }
            ans = max(ans,beforeCon+cont);
        }
        cout << ans << endl;
    }
}
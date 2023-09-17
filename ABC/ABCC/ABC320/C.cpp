#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M;
    cin >> M;
    string S[3];
    rep(i,3){
        cin >> S[i];
    }
    ll ans =1LL<<45;
    rep(i,M){
        ll current = i;
        ll goal = S[0][i];
        rep(j,M){
            if(S[1][j] == goal){
                ll current1 = 0;
                if(i==j) {
                     current1 = max(current, j + M);
                }else{
                    current1 = max(current, j);
                }
                rep(k,M){
                    if(S[2][k] == goal){
                        ll current2 = 0;
                        if(k==j&&k==i){
                            current2 = max({current,current1, k + 2 * M});
                        }else if(k==j||k==i){
                            current2 = max({current,current1, k + M});
                        }else{
                            current2 = max({current,current1, k});
                        }
                        ans = min(ans,current2);
                    }
                }
            }
        }
    }
    if(ans == 1LL<<45){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
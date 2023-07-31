#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll price[N];
    vector<vector<ll>> F(N);
    ll C[N];
    rep(i,N){
        cin >> price[i];
        cin >> C[i];
        rep(j,C[i]){
            ll cash;
            cin >> cash;
            F[i].push_back(cash);
        }
    }  
    bool ans = false;
    bool meet = false;
    rep(i,N){
        rep(j,N){
            if(i!=j){
                meet = true;
                if(price[i]>price[j]){
                    meet = false;
                }
                rep(k,C[j]){
                    bool have = false;
                    rep(l,C[i]){
                        if(F[j][k] == F[i][l]){
                            have = true;
                        }
                    }
                    if(have == false){
                        meet = false;
                    }
                }
                bool allhave = true;
                rep(l,C[i]){
                    bool have2 = false;
                    rep(k,C[j]){
                        if(F[j][k] == F[i][l]){
                            have2 = true;
                        }
                    }
                    if(!have2){
                        allhave = false;
                    }
                }
                if(price[i]==price[j]){
                    if(allhave){    
                        meet = false;
                    }
                }
                if(meet == true){
                    ans = true;
                    break;
                }
            }
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
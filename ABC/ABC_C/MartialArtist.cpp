#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<bool,ll>;
vector<vector<ll>> O;
vector<bool> T;
void DFS(ll U){
    T[U - 1] = true;
    ll Y = 0;
    Y += O[U - 1][0];
    if(O[U - 1].size() == 1){
        return;
    }
    rep(i,O[U - 1].size() - 1){
        if(!T[O[U - 1][i + 1] - 1] == true){
            DFS(O[U - 1][i + 1]);
        }
    }
}
int main(){
    ll N;
    cin >> N;
    O.resize(N + 10);
    T.resize(N + 10);
    rep(i,N){
        ll s = 0;
        O[i].resize(10);
        cin >> O[i][0] >> s;
        O[i].resize(s + 1);
        if(s != 0){
            rep(j,s){
                cin >> O[i][j+1];
            }
        }
    }DFS(N);
    ll ans = 0;
    rep(i,N){
        if(T[i]){
            ans += O[i][0];
        }
    }
    cout << ans << endl;
}
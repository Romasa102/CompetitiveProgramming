#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
vector<vector<ll>> M;
ll ans = 0;
ll N,X;
void find(int now,ll product){
    if(now == N){
        if(product == X){
            ans++;
        }
        return;
    }else{
        rep(i,M[now].size()){
            if(product * M[now][i] <= X){
                find(now + 1,product * M[now][i]);
            }
        }
    }
}
int main(){
    cin >> N >> X;
    M.resize(N + 100);
    rep(i,N){
        ll O;
        cin >> O;
        M[i].resize(O);
        rep(j,O){
            cin >> M[i][j];
        }
    }
    find(0,1);
    cout << ans << endl;
}
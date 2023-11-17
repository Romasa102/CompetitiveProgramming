#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A[9][9];
    rep(i,9)rep(j,9)cin >> A[i][j];
    rep(i,9){
        set<ll> numR;
        rep(j,9)numR.insert(A[i][j]);
        if(numR.size()!=9){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,9){
        set<ll> numR;
        rep(j,9)numR.insert(A[j][i]);
        if(numR.size()!=9){
            cout << "No" << endl;
            return 0;
        }
    }
    set<ll> m[3][3];
    rep(i,9)rep(j,9)m[i/3][j/3].insert(A[i][j]);
    rep(i,3)rep(j,3){
        if(m[i][j].size()!=9){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
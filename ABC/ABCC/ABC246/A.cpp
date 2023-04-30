#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    int g[3][3];
    rep(i,3){
        rep(j,2){
            cin >> g[i][j];
        }
    }
    if(g[0][0] == g[1][0]){
        cout << g[2][0];
    }else if(g[0][0] == g[2][0]){
        cout << g[1][0];
    }else if(g[1][0] == g[2][0]){
        cout << g[0][0];
    }
    cout << " ";
    if(g[0][1] == g[1][1]){
        cout << g[2][1];
    }else if(g[0][1] == g[2][1]){
        cout << g[1][1];
    }else if(g[1][1] == g[2][1]){
        cout << g[0][1];
    }cout << endl;
}
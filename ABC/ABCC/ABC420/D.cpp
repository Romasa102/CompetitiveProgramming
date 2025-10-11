#include <bits/stdc++.h>
#include <queue>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string A[H];
    rep(i,H){
        cin >> A[i];
    }
    vector<vecetor<vecetor<bool>>> visited(2,vector<bool>(H,vecetor<bool>(W)));
    queue<pair<ll,P>> Q;
    P startPos;
    rep(i,H){
        rep(j,W){
            if(A[i][j] == 'S'){
                startPos = {i,j};
                Q.push({0,startPos});
            }
        }
    }
    while(!Q.empty()){

    }
}

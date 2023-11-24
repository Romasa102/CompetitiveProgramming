#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll N,M;
string S,T;
ll curL = 0;
ll dfsP(ll x){//dfs prefix
    if(x<curL)return x;
    repp(i,1,M+1){
        ll counter = 0;
        bool work = true;
        if(x-i<0)break;
        for(ll j = x-i;j<x;j++){
            if(S[j]!='#'&&S[j]!=T[counter]){
                work = false;
            }
            counter++;
        }
        if(work){
            for(ll j = x-i;j<x;j++){
                S[j]='#';
            }
            return dfsP(x-i);
        }
    }
    return x;
}
ll dfsS(ll x){//dfs suffix
    repp(i,1,M+1){
        ll counter = M-i;
        bool work = true;
        if(x+i>N)continue;
        for(ll j = x;j<x+i;j++){
            if(S[j]!='#'&&S[j]!=T[counter]){
                work = false;
            }
            counter++;
        }
        if(work){
            for(ll j = x;j<x+i;j++){
                S[j]='#';
            }
            return dfsS(x+i);
        }
    }
    return x;
}
int main(){
    cin >> N >> M >> S >> T;
    rep(i,N){
        bool work = true;
        rep(j,M){
            if(i+j>=N){
                work=false;
                break;
            }
            if(S[i+j]!=T[j]){
                work = false;
            }
        }
        if(!work)continue;
        rep(j,M){
            S[i+j]='#';
        }
        if(dfsP(i)>curL){
            cout << "No" << endl;
            return 0;
        }
        curL = dfsS(i+M)-1;
        i=curL;
    }
    bool ans = true;
    rep(i,N){
        if(S[i]!='#')ans = false;
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
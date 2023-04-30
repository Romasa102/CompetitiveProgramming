#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M,X,T,D;
    cin >> N >> M >> X >> T >> D;
    ll sizA = 0;
    sizA = T - X*D;
    if(M >= X){
        cout << T << endl;
    }else{
        cout << M*D + sizA << endl;
    }
}
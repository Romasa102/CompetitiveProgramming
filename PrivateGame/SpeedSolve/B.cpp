#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    //N,s M,c;
    if(N >= M/2){
        cout << M/2 << endl;
        return 0;
    }else{
        ll total = 2*N+M;
        cout << total/4 << endl;
        return 0;
    }
}
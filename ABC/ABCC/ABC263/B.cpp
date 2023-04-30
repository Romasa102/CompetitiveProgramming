#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll P[N];
    rep(i,N){
        cin >> P[i];
    }
    ll anc = 1;
    ll NumNow =P[N-2];
    while(true){
        if(NumNow == 1){
            break;
        }
        NumNow = P[NumNow-2];
        anc++;
    }
    cout << anc << endl;
}
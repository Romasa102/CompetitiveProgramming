#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    ll cumS[S.size()+1];
    cumS[0]=0;
    repp(i,1,N){
        if(S[i-1]==S[i]){
            cumS[i]=cumS[i-1]+1;
        }else{
            cumS[i]=cumS[i-1];
        }
    }
    rep(i,Q){
        ll l,r;
        cin >> l >> r;
        cout << cumS[r-1]-cumS[l-1] << endl;
    }
}
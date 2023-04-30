#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll A,B,C,D,E,F,X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    ll Alen = 0;
    Alen += (X/(A+C))*A*B +min((X%(A+C)),A)*B;
    ll Blen = 0;
    Blen += (X/(D+F))*D*E +min((X%(D+F)),D)*E;
    if(Alen > Blen){
        cout << "Takahashi" << endl;
    }else if(Alen < Blen){
        cout << "Aoki" << endl;
    }else{
        cout << "Draw" << endl;
    }
}
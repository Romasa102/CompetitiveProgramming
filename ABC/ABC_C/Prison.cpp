#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    bool P[N];
    ll Ba = 0;
    ll Sb = 100000000000;
    rep(i,M){
        ll A,B;
        cin >> A >> B;
        if(A > Ba){
            Ba = A;
        }
        if(B < Sb){
            Sb = B;
        }
    }
    if(Sb - Ba >= 0){
        cout << Sb - Ba + 1 << endl; 
    }else{
        cout << 0 << endl;
    }
}
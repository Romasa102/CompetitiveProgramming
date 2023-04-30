#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    bool C1,C = true;
    rep(i,N){    
        C = !C1;
        rep(j,A){
            C = C1;
            rep(k,N){
                rep(l,B){
                    if(C){
                        cout << "#";
                    }else{
                        cout << ".";
                    }
                }
                C = !C;
            }
            cout << endl;
        }
        C1 = !C1;
    }
}
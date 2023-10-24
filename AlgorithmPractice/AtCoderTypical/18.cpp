#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    ll L,X,Y;
    cin >> T >> L >> X >> Y;
    ll Q;
    ll E[Q];
    cin >> Q;
    rep(i,Q){
        cin>>E[i];
        E[i]%=T;
        double x=0;
        double y=0;
        if(E[i]<(double)T/4){
            (double)L/2
        }else if(E[i]<(double)T/2){

        }else if(E[i]<(double)T*3/4){

        }else{

        }
    }
}
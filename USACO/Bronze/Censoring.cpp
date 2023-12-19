#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("censor.in","r",stdin);
    string S,T;
    cin >> S >> T;
    rep(i,S.size()){
        bool work = true;
        rep(j,T.size()){
            if(i+j>S.size()){
                work = false;
                break;
            }
            if(S[i+j]!=T[j]){
                work = false;
                break;
            }
        }
        if(work){
            S.erase(i,T.size());
            if(i-T.size()>=0){
                i= i-T.size();
            }else{
                i=0;
            }
        }
    }
    freopen("censor.out","w",stdout);
    cout <<S << endl;
}
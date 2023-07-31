#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,D;
    cin >> N >> D;
    string S[N];
    rep(i,N){
        cin >> S[i];
    }
    ll Counter = 0;
    ll Ans = 0;
    rep(i,D){
        bool allOk = true;
        rep(j,N){
            if(S[j][i] == 'x'){
                allOk = false;
                break;   
            }
        }
        if(allOk == false){
            Counter = 0;
        }else{
            Counter++;
            Ans = max(Ans,Counter);
        }
    }
    cout << Ans << endl;
}
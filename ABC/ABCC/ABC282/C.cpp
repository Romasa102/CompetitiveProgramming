#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    cin >> S;
    ll count = 0;
    rep(i,N){
        if(S[i] == '"'){
            count++;
        }
        if(S[i] == ','){
            if(count%2 == 0){
                S.replace(i,1,".");
            }
        }
    }
    cout << S << endl;
}
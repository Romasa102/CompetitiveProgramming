#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll maxCon[27];
    rep(i,27)maxCon[i]=0;
    char cur = S[0];
    ll len = 1;
    repp(i,1,N+1){
        if(i==N){
            maxCon[cur-'a']=max(maxCon[cur-'a'],len);
            break;
        }
        if(S[i] ==cur){
            len++;
        }else{
            maxCon[cur-'a']=max(maxCon[cur-'a'],len);
            len=1;
            cur = S[i];
        }
    }
    ll ans =0;
    rep(i,27){
        ans += maxCon[i];
    }
    cout << ans << endl;
}
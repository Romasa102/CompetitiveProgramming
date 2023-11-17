#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    char ans[N+1];
    repp(i,0,N+1){
        ans[i]='-';
        repp(j,1,10){
            if(N%j==0&&i%(N/j)==0){
                ans[i]=j+'0';
                break;
            }
        }
    }
    rep(i,N+1)cout << ans[i];
    cout << endl;
}
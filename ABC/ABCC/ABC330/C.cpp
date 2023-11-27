#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll D;
    cin >> D;
    vector<ll> NUMS;
    rep(X,1414222){
        NUMS.push_back(X*X);
    }
    ll ans =1LL<<60;
    rep(X,1414220){
        ll needTF = D-(X*X);
        if(needTF<=0){
            ans = min(ans,abs(X*X-D));
            continue;
        }
        ll num = sqrt(*lower_bound(NUMS.begin(),NUMS.end(),needTF));
        ll num1 = sqrt(*(lower_bound(NUMS.begin(),NUMS.end(),needTF)+1));
        ll num2 =0;
        if(num==1){
            num2 = 1;
        }else{
            num2 = sqrt(*(lower_bound(NUMS.begin(),NUMS.end(),needTF)-1));
        }
        ans = min({ans,abs(X*X+num*num-D),abs(X*X+num1*num1-D),abs(X*X+num2*num2-D)});
    }
    cout << ans << endl;
}
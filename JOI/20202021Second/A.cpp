#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,A;
    cin >> N >> A;
    string S;
    cin >> S;
    queue<ll> up;
    queue<ll> down;
    ll lastUp = N-A+1;
    ll lastD = A;
    repp(i,A,N){
        if(S[i] == '#'){
            up.push(i-A+1);
        }
    }
    for(int i = A-1;i>=0;i--){
        if(S[i]=='#'){
            down.push(A-i-1);
        }
    }
    ll ans = 0;
    while(!up.empty()||!down.empty()){
        ll a = lastUp;
        if(!up.empty()){
            a = up.front();
            up.pop();
        }
        ans += a;
        if(up.empty()&&down.empty()){
            break;
        }
        ans += a;
        ll b = lastD;
        if(!down.empty()){
            b = down.front();
            down.pop();
        }
        ans+=b;
        if(up.empty()&&down.empty()){
            break;
        }
        ans += b;
    }
    cout << ans << endl;
}
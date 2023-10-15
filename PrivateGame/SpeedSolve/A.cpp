#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    ll A[N];
    ll M;
    map<ll,bool> B;
    cin >> N;
    rep(i,N)cin >> A[i];
    cin >> M;
    rep(i,M) {
        ll num;
        cin >> num;
        B[num] = true;
    }
    ll X;
    cin >> X;
    ll dp[X+10];
    rep(i,X+1){
        dp[i] = 0;
    }
    dp[0] = 1;
    rep(i,X+1){
        rep(j,N){
            if(dp[i] == 1 && i+A[j] <= X){
                if(B.find(i+A[j]) == B.end()){
                    dp[i+A[j]] = 1;
                }
            }
        }
    }
    if(dp[X] == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    stack<ll> bracket;
    bool dp[N];
    rep(i,N){
        if(S[i] == '('){
            bracket.push(i);
        }
        if(S[i] == ')'){
            if(bracket.size()<=0){
                continue;
            }
            rep(i,i-bracket.top()){
                
            }
            bracket.pop();
        }
    }
}
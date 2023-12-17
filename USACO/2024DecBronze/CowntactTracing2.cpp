#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    string S;cin >> S;
    ll ans = 0;
    ll initial=0;
    while(S[initial]=='1'){
        initial++;
    }
    ll final = N-1;
    if(initial!=N){
        while(S[final]=='1'){
            final--;
        }
    }
    ll mini = 1LL<<60;
    if(initial!=0){
        mini = min(mini,initial-1);
    }
    if(final!=N-1){
        mini = min(mini,N-final-1-1);
    }
    vector<ll> len;
    ll cur = 0;
    rep(i,N){
        if(i<initial){
            continue;
        }
        if(i>final){
            continue;
        }
        if(S[i]=='1'){
            cur++;
        }else{
            if(cur==0)continue;
            if(cur%2==1){
                mini = min(mini,(cur-1)/2);
            }else{
                mini = min(mini,cur/2-1);
            }
            len.push_back(cur);
            cur=0;
        }
    }
    sort(len.begin(),len.end());
    rep(i,len.size()){
        if(len[i]==mini*2+1){
            ans++;
        }else{
            ans += (len[i]+mini*2)/(mini*2+1);
        }
    }
    if(initial!=0){
        ans += (initial+mini*2)/(mini*2+1);
    }
    if(final!=N-1){
        ans += (N-final-1+mini*2)/(mini*2+1);
    }
    cout <<  ans << endl;
}
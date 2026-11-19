#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
int main(){
    ll N,K;
    cin >> N >> K;
    ll P[N];
    rep(i,N){
        cin >> P[i];
    }
    ll dp[N];
    dp[0] = 1;
    repp(i,1,N){
        if(P[i-1] <= P[i]){
            dp[i] = dp[i-1]+1;
        }else{
            dp[i] = 1;
        }
        if(dp[i] >= K){
            rep(j,N){
                cout << P[j] << " ";
            }cout << endl;
            return 0;
        }
    }
    ll ans = 0;
    ll Spos = N-K;
    for(int i = N-1; i >= 0; i--){
        ans ++;
        if(ans >= K){
            ll cash = i;
            ll smallest = 1LL<<32;
            rep(j,K){
                smallest = min(smallest,P[i+j]);
            }
            if(cash == 0){
                Spos = 0;
                break;
            }
            if(dp[cash-1]==1&&dp[cash]==1){
                Spos = cash;
                break;
            }
            if(P[cash]>smallest){
                Spos=cash;
            }
            cash--;
            if(P[cash]>smallest){
                Spos=cash;
            }
            while (cash > 0 && dp[cash] != 1) {
                cash--;
            }
            if(P[cash]<=smallest){
                Spos=cash;
            }else{
                Spos = N-K;
            }
            break;
        }
    }
    vector<ll> sortT;
    rep(i,N){
        if(Spos <= i && Spos + K - 1 >= i){
            sortT.push_back(P[i]);
        }
    }
    sort(sortT.begin(),sortT.end());
    rep(i,N){
        if(Spos <= i && Spos + K - 1 >= i){
            cout << sortT[i-Spos] << " ";
            continue;
        }
        cout << P[i] << " ";
    }cout << endl;
}
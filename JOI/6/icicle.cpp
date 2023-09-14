#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,L;
    cin >> N >> L;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    ll wait[N];
    rep(i,N)wait[i] = 0;
    if(wait[0] < wait[1]){
        wait[0] = 1;
    }
    if(wait[N-1] < wait[N-2]){
        wait[N-1] = 1;
    }
    vector<ll> DESTROY;
    repp(i,1,N-1){
        if(A[i] < A[i-1]){
            wait[i]++;
        }
        if(A[i] < A[i+1]){
            wait[i]++;
        }
        if(wait[i] == 0){
            DESTROY.push_back(i);
        }
    }
    ll Btime[N];
    rep(i,N){
        Btime[i] = L - A[i];
    }
    ll waitT[N];
    ll ans = 0;
    vector<ll> DESTROYT;
    rep(i,DESTROY.size()){
        if(wait[DESTROY[i]-1] !=0){
            wait[DESTROY[i]-1]--;
            waitT[DESTROY[i]-1] = max(Btime[DESTROY[i]],waitT[DESTROY[i]-1]);
            if(wait[DESTROY[i]-1] == 0){
                Btime[DESTROY[i]-1] += waitT[DESTROY[i]-1];
                ans = max(ans,Btime[DESTROY[i]-1]);
                DESTROYT.push_back(DESTROY[i]-1);
            }
        }
        if(wait[DESTROY[i]+1] != 0){
            wait[DESTROY[i]+1]--;
            waitT[DESTROY[i]+1] = max(Btime[DESTROY[i]],waitT[DESTROY[i]+1]);
            if(wait[DESTROY[i]+1] == 0){
                Btime[DESTROY[i]+1] += waitT[DESTROY[i]+1];
                ans = max(ans,Btime[DESTROY[i]+1]);
                DESTROYT.push_back(DESTROY[i]+1);
            }
        }
    }
    rep(i,DESTROYT.size()){
        if(wait[DESTROYT[i]-1]!=0){
            waitT[DESTROY[i]-1] = max(Btime[DESTROY[i]],waitT[DESTROY[i]-1]);
            ans = max(ans,Btime[DESTROY[i]]+Btime[DESTROY[i]-1]);
        }
        if(wait[DESTROYT[i]+1]!=0){
            waitT[DESTROY[i]+1] = max(Btime[DESTROY[i]],waitT[DESTROY[i]+1]);
            ans = max(ans,Btime[DESTROY[i]]+Btime[DESTROY[i]+1]);
        }
    }
    cout << ans << endl;
}
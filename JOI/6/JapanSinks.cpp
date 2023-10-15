#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    map<ll,ll> sides; //index,0=none 1=bothBig 2=bothSmal;
    bool bigger = false;
    bool smaller = true;
    rep(i,N-1){
        if(A[i]<A[i+1]){
            if(bigger){
                sides[i] = 1;
            }else{
                sides[i] = 0;
            }
            smaller = true;
            bigger = false;
            continue;
        }
        if(A[i]>A[i+1]){
            if(smaller){
                sides[i] = 2;
            }else{
                sides[i] = 0;
            }
            bigger = true;
            smaller = false;
            continue;
        }
        sides[i] = 0;
    }
    if(A[N-1] > A[N-2]){
        sides[N-1] = 2;
    }else if(smaller && A[N-1] == A[N-2]){
        sides[N-1] = 2;
    }else{
        sides[N-1] = 0;
    }
    P B[N];
    bool allZ = true;
    rep(i,N){
        B[i].first = A[i];
        if(A[i] != 0){
            allZ = false;
        }
        B[i].second = i;
    }
    if(allZ){
        cout << 0 << endl;
        return 0;
    }
    ll cur = 1;
    ll ans = 1;
    sort(B,B+N);
    rep(i,N){
        if(sides[B[i].second] == 1){
            cur += 1;
        }
        if(sides[B[i].second] == 2){
            cur-=1;
        }
        if(i < N-1 && B[i].first != B[i+1].first){
            ans = max(ans,cur);
        }
    }
    cout << ans << endl;
}
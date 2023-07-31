#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    vector<ll> D(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,N) cin >> C[i];
    rep(i,N) cin >> D[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    sort(D.begin(),D.end());
    ll minAns = 2000000000;
    rep(i,N){
        ll k = max({*lower_bound(B.begin(),B.end(),A[i]),*lower_bound(C.begin(),C.end(),A[i]),*lower_bound(D.begin(),D.end(),A[i]),*lower_bound(A.begin(),A.end(),A[i])});
        if(k>A[i]){
        minAns = min(minAns,(k-A[i]));

        }
    }
    rep(i,N){
        ll k = max({*lower_bound(A.begin(),A.end(),B[i]),*lower_bound(C.begin(),C.end(),B[i]),*lower_bound(D.begin(),D.end(),B[i]),*lower_bound(B.begin(),B.end(),B[i])});
        if(k>A[i]){
            minAns = min(minAns,(k-B[i]));
        }
    }
    rep(i,N){
        ll k = max({*lower_bound(B.begin(),B.end(),C[i]),*lower_bound(A.begin(),A.end(),C[i]),*lower_bound(D.begin(),D.end(),C[i]),*lower_bound(C.begin(),C.end(),C[i])});
        if(k>A[i]){
            minAns = min(minAns,(k-C[i]));
        }
    }
    rep(i,N){
        ll k = max({*lower_bound(B.begin(),B.end(),D[i]),*lower_bound(C.begin(),C.end(),D[i]),*lower_bound(A.begin(),A.end(),D[i]),*lower_bound(D.begin(),D.end(),D[i])});
        if(k>A[i]){
            minAns = min(minAns,(k-D[i]));
        }
    }
    cout << minAns << endl;
}
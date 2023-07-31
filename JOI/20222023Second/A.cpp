#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<P> A(N);
    rep(i,N){
        cin >> A[i].first;
        A[i].second = i;
    }
    vector<P> B(N);
    sort(A.begin(),A.end());
    rep(i,N){
        if(abs(A[N-1].first - A[i].first) >= abs(A[i].first - A[0].first)){
            B[i].second = abs(A[N-1].first - A[i].first);
            B[i].first = A[i].second;
        }else{
            B[i].second = abs(A[i].first - A[0].first);
            B[i].first = A[i].second;
        }
    }
    sort(B.begin(),B.end());
    rep(i,N){
        cout << B[i].second << endl;
    }
}
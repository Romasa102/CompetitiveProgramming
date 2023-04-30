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
    sort(A.begin(),A.end());
    vector<P>B(N);
    rep(i,N){
        B[i].first = A[i].second;
        if(i>=1&&A[i].first == A[i-1].first){
            B[i].second = B[i-1].second;
        }else{
            B[i].second = i +1;
        }
    }
    sort(B.begin(),B.end());
    rep(i,N){
        cout << B[i].second << endl;
    }
}
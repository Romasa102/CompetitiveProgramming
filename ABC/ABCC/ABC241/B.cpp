#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> B(M);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,M){
        cin >> B[i];
    }
    bool ans = true;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    auto itr = A.begin();
    rep(i,M){
        while(B[i] != *itr){
            itr++;
            if(*itr >= N - 1){
                ans = false;
                break;
            }
        }
        if(B[i] == *itr){
            A.erase(itr);
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
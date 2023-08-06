#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    ll A[N];
    ll sum = 0;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    ll ave1 = floor(sum / N);
    ll ave2 = ceil(sum / N);
    ll biggerSize = 0;
    ll smallerSize = 0;
    rep(i,N){
        if(A[i] <= ave1){
            smallerSize += ave1 - A[i];
        }
        else if(A[i] >= ave2){
            biggerSize += A[i] - ave2;
        }
    }
    cout << max(biggerSize,smallerSize) << endl;
}
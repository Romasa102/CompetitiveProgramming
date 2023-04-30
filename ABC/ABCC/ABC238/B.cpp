#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }ll sum = 0;
    ll B[N + 1];
    rep(i,N){
        sum += A[i];
        if(sum >= 360){
            sum -= 360;
        }
        B[i] = sum;
    }
    B[N] = 360;
    sort(B,B+N+1,greater<int>());
    ll dif[N + 1];
    rep(i,N + 1){
        if(i == N){
            dif[i] = B[i] - 0;
        }
        dif[i] = B[i] - B[i + 1];
    }
    sort(dif,dif+N+1,greater<int>());
    cout << dif[0] << endl;
}
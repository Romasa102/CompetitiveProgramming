#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll light[N];
    rep(i,N){
        cin >> light[i];
    }
    ll correctBefore = 0;
    ll wrongCon = 0;
    ll correctNow = 0;
    ll ans = 0;
    rep(i,N){
        if(light[i] == i%2){
            correctNow++;
        }else{
            if(correctNow != 0){
                correctBefore = correctNow;
                correctNow = 0;
                wrongCon = 0;
            }
            wrongCon++;
        }
        ans = max(ans,correctBefore+wrongCon+correctNow);
    }
    correctBefore = 0;
    correctNow = 0;
    wrongCon = 0;
    rep(i,N){
        if(light[i] == (i+1)%2){
            correctNow++;
        }else{
            if(correctNow != 0){
                correctBefore = correctNow;
                correctNow = 0;
                wrongCon = 0;
            }
            wrongCon++;
        }
        ans = max(ans,correctBefore+wrongCon+correctNow);
    }
    cout << ans << endl;
}
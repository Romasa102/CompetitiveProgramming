#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll Pa[N];
    ll biggest = 0;
    rep(i,N){
        if(i == 0){
            cin >> Pa[i];
            continue;
        }
        cin >> Pa[i];
        biggest = max(Pa[i],biggest);
    }
    if(Pa[0] <= biggest){
        cout << biggest - Pa[0]+1 << endl;
    }else{
        cout << 0 << endl;
    }
} 
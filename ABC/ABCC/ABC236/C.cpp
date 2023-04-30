#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    string S[N];
    string T[M];
    rep(i,N){
        cin >> S[i];
    }
    rep(i,M){
        cin >> T[i];
    }
    string goal;
    ll c;
    ll now = 0;
    rep(i,M){
        goal = T[i];
        for(int j = now;j < N;j++){
            if(S[j] == T[i]){
                cout << "Yes" << endl;
                now = j + 1;
                break;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    P K[N];
    P R[Q];
    ll max = 0;
    rep(i,N){
        cin >> K[i].first >> K[i].second;
        if(K[i].first > max){
            max = K[i].first;
        }
        if(K[i].second > max){
            max = K[i].second;
        }
    }
    P M[max];
    rep(i,Q){
        cin >> R[i].first >> R[i].second;
    }
    rep(i,N){
        if(K[i].first == 1){
            M[K[i].second].second = 1;
            M[K[i].second].first = 1;
            continue;
        }
        if(K[i].second == 1){
            M[K[i].first].second = 1;
            M[K[i].first].first = 1;
            continue;
        }
        if(M[K[i].first].second > M[K[i].second].second){
            M[K[i].second].second = M[K[i].first].second+1;
            M[K[i].second].first = K[i].first;
        }
        if(M[K[i].first].second < M[K[i].second].second){
            M[K[i].first].second = M[K[i].second].second+1;
            M[K[i].first].first = K[i].second;
        }
    }
    rep(i,max){
        cout << M[i].first << "   " << M[i].second << endl;
    }
}
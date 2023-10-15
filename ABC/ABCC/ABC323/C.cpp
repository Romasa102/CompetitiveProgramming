#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[M+10];
    rep(i,M)cin >> A[i];
    string S[N+10];
    ll curScore[N+10];
    vector<vector<ll>> potential(N);
    rep(i,N){
        cin >> S[i];
        curScore[i]=i+1;
        rep(j,M){
            if(S[i][j] == 'o'){
                curScore[i]+=A[j];
            }else{
                potential[i].push_back(A[j]);
            }
        }
    }
    ll maxScore = 0;
    rep(i,N){
        maxScore = max(maxScore,curScore[i]);
    }
    rep(i,N){
        if(!potential[i].empty()){
            sort(potential[i].begin(),potential[i].end(),greater<ll>());
        }
        if(curScore[i] >= maxScore) {
            cout << 0 << endl;
            continue;
        }
        rep(j,potential[i].size()){
            curScore[i] += potential[i][j];
            if(curScore[i] >= maxScore){
                cout << j+1 << endl;
                break;
            }
        }
    }
}
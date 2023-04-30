#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S;
    deque<ll>A;
    A.push_back(N);
    cin >> S;
    for(int i = N - 1;i >= 0;i--){
        if(S[i] == 'R'){
            A.insert(A.begin(),i);
        }else{
            A.push_back(i);
        }
    }
    rep(i,N + 1){
        cout << A[i] << " ";
    }cout << endl;
} 
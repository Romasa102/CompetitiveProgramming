#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    map<ll,vector<ll>> num;
    rep(i,N){
        cin >> A[i];
        num[A[i]].push_back(i);
    }
    rep(i,N){
        if(lower_bound(num[A[i]].begin(),num[A[i]].end(),i)!=num[A[i]].end()&&lower_bound(num[A[i]].begin(),num[A[i]].end(),i)+1!=num[A[i]].end()){
            rep(j,(*(lower_bound(num[A[i]].begin(),num[A[i]].end(),i)+1)-i)){
                cout << A[i] << endl;
            }
            i=*(lower_bound(num[A[i]].begin(),num[A[i]].end(),i)+1)-1;
        }else{
            cout << A[i] << endl;
        }
    }
}
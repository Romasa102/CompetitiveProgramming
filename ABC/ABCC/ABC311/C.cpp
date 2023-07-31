#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll parent[200100];
find(i){
    if(i == parent[i]){
        return parent[i];
    }else{
        return find[i];
    }
}
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N+10){
        parent[i] = i;
    }
    vector<ll> ansV;
    rep(i,N){
        cin >> A[i];
        if(A[i] == find(i+1)){
            rep(j,N){
                if(find[j+1] == A[i]){
                    ansV.push_back(j+1);
                }
            }
        }
        parent[A[i]] == find(i+1);
    }
    cout << ansV.size() << endl;
    rep(i,ansV.size()){
        cout << ansV[i] << endl;
    }
}
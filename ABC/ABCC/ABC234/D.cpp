#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
void ins (vector<int> n, int i) {
    int left = 0;
    int right = n.size();
    int mid;
    ll An = 0;
    while(left<right){
        mid = (left+right)/2;
        ll mid_now = mid;
        if(i == n[mid]){
            An = mid;
            break;
        }
        if(i < n[mid]){
            left = mid+1; 
        }
        if(i > n[mid]){
            right = mid;
        }
        if(mid_now == mid){
            An = mid;
            break;
        }
    }
    auto itr = n.begin();
    rep(i,An){
        itr++;
    }
    n.insert(itr,i);
}

int main(){
    ll N,K;
    cin >> N >> K;
    vector<int> O(N + 10);
    rep(i,K){
        cin >> O[i];
    }
    sort(O.begin(),O.end(),greater<ll>());
    cout << O[K - 1] << endl;
    for (ll i = K; i < N; i++)
    {
        ll u;
        cin >> u;
        ins(O,u);
        cout << O[K - 1] << endl;
    }
}
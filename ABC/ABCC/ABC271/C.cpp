#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<int> a(N);
    rep(i,N){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i = 1;i <= N;i++){
        if(a[0] != i){
            if(a.size() >= 2){
                a.pop_back();
                a.pop_back();
            }else{
                cout << i-1 << endl;
                return 0;
            }
        }
        else{
            if(a.size() != 1){
                a.erase(cbegin(a),cbegin(a)+1);
            }else{
                cout << a[0] << endl;
                return 0;
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> Q(N);
    ll difference = 0;
    vector<P> process;
    rep(i,N){
        cin >> Q[i];
    }
    rep(i,N){
        if(Q[i] == N - i){
            continue;
        }
        rep(j,N){
            vector<ll> Num2(0);
            if(Q[j] == N-i){
                if(j == 0){
                    break;
                }
                Num2.push_back(Q[j-1]);
                Num2.push_back(Q[j]);
                Q.erase(Q.begin()+j-1,next(Q.begin()+j));
                Q.insert(Q.end()-i,Num2.begin(),Num2.end());
                process.push_back(make_pair(j,i+1));
            }
        }
    }
    rep(i,N){
        if(Q[i] != i+1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << process.size() << endl;
    rep(i,process.size()){
        cout << process[i].first +1 << " " << process[i].second -1 << endl;
    }
}
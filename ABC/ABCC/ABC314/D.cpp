#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll N;
    string S;
    ll Q;
    cin >> N >> S >> Q;
    char memo[N];
    ll lastInd = -1;
    ll task[Q];
    ll x[Q];
    char c[Q];
    rep(i,Q){
        cin >> task[i];
        cin >> x[i] >> c[i];
        if(task[i] == 2){
            lastInd = i;
        }else if(task[i] == 3){
            lastInd = i;
        }
    }
    rep(i,Q){
        if(i == lastInd){
            if(task[i] == 2){
                rep(j,N){
                    memo[j] = tolower(memo[j]);
                }
                continue;
            }else if(task[i] == 3){
                rep(j,N){
                    memo[j] = toupper(memo[j]);
                }
                continue;
            }
        }
        if(task[i] == 1){
            memo[x[i]-1] = c[i];
        }
    }
    rep(i,N){
        cout << memo[i];
    }
    cout << endl;

}
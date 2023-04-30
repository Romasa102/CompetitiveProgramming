#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    int N,M;
    cin >> N >> M;
    vector<P> A(M);
    vector<P> B(M);
    rep(i,M){
        cin >> A[i].first >> A[i].second;
    }
    rep(i,M){
        cin >> B[i].first >> B[i].second;
    }
    ll ans = 0;
    rep(i,M){
        if(A == B){
            ans++;
        }
    }
    if(ans == M){
        cout << "Yes" << endl;
        return 0;
    }
    vector<int> v(N);
    
    vector<P> CA(M);
    iota(v.begin(), v.end(), 1);
    do {
        int counter = 1;
        for(auto x : v){
            rep(i,M){
                if(A[i].first == counter){
                    CA[i].first = x;
                }else if(A[i].second == counter){
                    CA[i].second = x;
                }
            }
            counter++;
        }
        ans = 0;
        rep(i,M){
            rep(j,M){
                if(CA[i].first == B[j].first && CA[i].second == B[j].second){
                    ans++;
                }else if(CA[i].first == B[j].second && CA[i].second == B[j].first){
                    ans++;
                }
            }
        }
        if(ans == M){
            cout << "Yes" << endl;
            return 0;
        }
    } while(next_permutation(v.begin(), v.end()));

    cout << "No" << endl;
}
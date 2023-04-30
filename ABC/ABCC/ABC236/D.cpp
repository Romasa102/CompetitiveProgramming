#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int N;
vector<vector<int>> A;
vector<ll> an;
void maxX(int find,int XORn){
    if(find == 2 * N - 1){
        an.push_back(XORn);
        return;
    }
    rep(i,A[find].size() - 1){
        int XORm = XORn ^ A[find][i];
        maxX(find + 1,XORm);
    }
}
int main(){
    cin >> N;
    A.resize(2 * N);
    rep(i,2 * N - 1){
        A[i].resize(2 * N - i);
        rep(j,2 * N - i - 1){
            cin >> A[i][j];
        }
    }
    ll maxXOR = 0;
    vector<ll> o(2 * N);
    rep(i,2 * N){
        o.push_back(i);
    }
    maxX(0,0);
    an.resize(N * 100);
    sort(an.begin(),an.end(),greater<int>());
    
    cout << an[0] << endl;
}
#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M = 0;
    cin >> N >> M;
    vector<vector<char>> A;
    A.resize(2 * N);
    vector<P> B;
    B.resize(2 * N);
    rep(i,2 * N){
        A[i].resize(M);
        B[i].second = i;
        rep(j,M){
            cin >> A[i][j];
        }
    }
        cout << M << endl;
    rep(i,M){
        rep(j,N){
            int P1 = B[2 * j].second;
            int P2 = B[2 * j + 1].second;
            char h = A[P1][i];
            char g = A[P2][i];
            if(h == 'G'){
                if(g == 'C'){
                    B[P1].first ++;
                }else if(g == 'P'){
                    B[P2].first ++;
                }
            }
            if(h == 'C'){
                if(g == 'G'){
                    B[P2].first ++;
                }else if(g == 'P'){
                    B[P1].first ++;
                }
            }
            if(h == 'P'){
                if(g == 'G'){
                    B[P1].first ++;
                }else if(g == 'C'){
                    B[P2].first ++;
                }
            }
        }  
        rep(i,2 * N){
            cout << B[i].second << "    ";
        }cout << endl;
        sort(B.begin(),B.end(), [](P a, P b){return a.first>b.first || (a.first==b.first&& a.second<b.second);});
        rep(i,2 * N){
            cout << B[i].second << "    ";
        }cout << endl;
    }
    rep(i,2 * N){
        cout << B[i].second + 1 << endl;
    }
}
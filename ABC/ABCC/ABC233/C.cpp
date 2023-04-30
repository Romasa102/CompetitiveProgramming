#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;


int N,X;
vector<int> K;
vector<vector<int>> A(1);
int ans;
int counter = 0;
int Sans = 1;
void devide(){
    rep(i,A[counter][0]){
      //  Sans *= A[counter][i + 1];          
        counter++;
        if(counter < N){
            devide();
        }else{
            if(Sans == X){
            ans++;
            }
            Sans = 0;
        }
    }

}
int main(){
    cin >> N >> X;
    int B;
    A.resize(N + 2);
    rep(i,N){
        cin >> B;
        A[i].push_back(B);
        rep(j,A[i][0]){
            cin >> B;
            A[i].push_back(B);
        }
    }
    devide();
    cout << ans << endl;
}
#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<double,double>;
int main(){
    int N;
    cin >> N;
    vector<P> A(N);
    rep(i,N){
        cin >> A[i].first >> A[i].second;
    }
    double sum = 0;
    rep(i,N){
        double q = A[i].first / A[i].second;
        sum += q;
    }
    sum /= 2;
    int k = 0;
    while(true){
        if(sum - A[k].first / A[k].second > 0){
            sum -= A[k].first/A[k].second;
        }else{
            break;
        }
        k++;
    }
    double ans = sum * A[k].second;
    rep(i,k){
        ans += A[i].first;
    }
    cout << fixed << setprecision(7) << ans << endl;
}
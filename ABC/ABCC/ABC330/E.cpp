#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<int, int> frequency;
set<int> missing_numbers;
vector<int> A;
void update(int idx, int new_value) {
    if (--frequency[A[idx]] == 0)
        missing_numbers.insert(A[idx]);
    A[idx] = new_value;
    ++frequency[new_value];
    if(new_value<=200001){
        missing_numbers.erase(new_value);
    }
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    A.resize(N,0);
    rep(i,N)cin >> A[i];
    rep(i,200001)missing_numbers.insert(i);
    for (int x : A) {
        ++frequency[x];
        missing_numbers.erase(x);
    }
    rep(i,Q){
        ll ix,xx;
        cin >> ix >> xx;
        update(ix-1,xx);
        cout << *missing_numbers.begin() << endl;
    }
}
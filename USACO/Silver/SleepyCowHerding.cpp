#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    ll N;cin >> N;
    ll pos[N];rep(i,N)cin >> pos[i];
    sort(pos,pos+N);
    ll maxA = max(pos[N-1]-pos[1]-1-N+3,pos[N-2]-pos[0]-1-N+3);
    ll left = 0;
    ll right = 0;
    ll minM = 1LL<<60;
    if (pos[N - 2] - pos[0] == N - 2 && pos[N - 1] - pos[N - 2] > 2) {
        minM = 2;
    } else if (pos[N - 1] - pos[1] == N - 2 && pos[1] - pos[0] > 2) {
        minM = 2;
    }else{
        while(left != N-1 && right != N){
            if(pos[right]-pos[left]>=N){
                left++;
            }else{
                minM = min(minM,N-(right - left + 1));
                right++;
            }
        }
    }
    cout << minM << endl << maxA << endl;
}
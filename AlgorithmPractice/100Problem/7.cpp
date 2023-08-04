#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<P> point(N);
    map<P,bool> exist;
    rep(i,N){
        cin >> point[i].first >> point[i].second;
        exist[point[i]] = true;
    }
    map<tuple<P,P,P,P>,bool> square;
    ll maxArea = 0;
    rep(i,N){ 
        rep(j,N){
            if(i==j)continue;
            ll difx,dify;
            difx = point[j].first - point[i].first;
            dify = point[j].second - point[i].second;
            P remain1 = {point[j].first + dify,point[j].second-difx};
            P remain2 = {point[i].first + dify,point[i].second-difx};
            if(exist.find(remain1) != exist.end() && exist.find(remain2) != exist.end()){
                maxArea = max(maxArea, difx * difx + dify * dify);
            }
        }
    }cout << maxArea << endl;
}
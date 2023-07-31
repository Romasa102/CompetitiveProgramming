#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<P> AB(100);
ll N,T,M;
vector<ll> num;
vector<ll> divide2(vector<ll> nums,ll left){
    vector<ll> ans;
    if(nums.size()<=left){
        return;
    }rep(i,nums.size()-left){
        ans.push_back(nums[i])
        ans.push_back(0);
        nums.pop_back();
        ans.push_back(divide2(nums,left-1));
    }
}
int main(){
    cin >> N >>  T >> M;
    rep(i,M){
        cin >> AB[i].first >> AB[i].second;
    }
    rep(i,N){
        num.push_back(i+1);
    }
    do{
        
    }while(next_permutation(num.begin(),num.end()));
}
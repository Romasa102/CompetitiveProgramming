#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
double intersect(double a,double b,double c,double d){
    return (b-d)/(c-a);
}
int main(){
    ll N,C;
    cin >> N >> C;
    double h[N];rep(i,N)cin >> h[i];
    deque<tuple<double,double,double>> dq; //x val, gradient, intercept
    vector<double> cost(N);
    cost[0] = 0;
    dq.push_front({0,-2.0 * h[0], C + h[0] * h[0] + 0});
    repp(i,1,N){
        tuple<double,double,double> cur = dq.front();
        tuple<double,double,double> target = {h[i],0,0};
        auto it = lower_bound(dq.begin(),dq.end(),target, greater<tuple<double,double,double>>());
        if(it == dq.end())it--;
        //cout << "grad used for " << h[i] << " is :" << get<1>(*it) << " and intercept is " << get<2>(*it) << endl;
        cost[i] = get<1>(*it) * h[i] + get<2>(*it) + h[i]*h[i];
        double grad = -2 * h[i];
        double intercept = cost[i] + C + h[i] * h[i];
        while(
            !dq.empty() && 
            intersect(grad,intercept, get<1>(cur) , get<2>(cur)) < get<0>(cur)
        )
        {
            /*cout << "intersection between " << h[i] << " and " << get<1>(cur) / (-2.0)  << " is " << 
            intersect(grad,intercept , get<1>(cur) , get<2>(cur))  << " and " << get<1>(cur)/(-2.0) << " is popped." << endl;
            */
            dq.pop_front();
            cur = dq.front();
        }

        //cout << "intersection between " << h[i] << " and " << get<1>(cur) / (-2.0)  << " is " << 
        //intersect(grad,intercept, get<1>(cur) , get<2>(cur)) << endl;
        dq.push_front(
                    {intersect(grad, intercept, get<1>(cur) , get<2>(cur)),
                        grad,
                        intercept
                    });
    }/*
    rep(i,dq.size()){
        cout << "intersection " << i << "is " << get<0>(dq[i]) << endl;
    }
    rep(i,N){
        cout << "cost at " << i << " is : " << cost[i] << endl;
    }*/
    cout << (ll)cost[N-1] << endl;
}
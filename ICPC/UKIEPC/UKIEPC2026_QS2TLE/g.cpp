#include <bits/stdc++.h>
using namespace std;

template<class T> int sgn(T x){return (x>0)-(x<0);}
template<class T> struct Point{
    typedef Point P;
    T x,y;
    explicit Point(T x=0, T y=0):x(x),y(y){}
    bool operator<(P p) const {return tie(x,y)<tie(p.x,p.y);}
    bool operator==(P p) const {return tie(x,y)==tie(p.x,p.y);}
    P operator+ (P p)  const{return P(x+p.x,y+p.y);}
    P operator- (P p)  const{return P(x-p.x,y-p.y);}
    P operator* (T d)  const{return P(x*d,y*d);}
    P operator/ (T d)  const{return P(x/d,y/d);}
    T dot (P p)const{return x*p.x+y*p.y;}
    T cross(P p) const {return x*p.y-y*p.x;}
    T cross(P a, P b){return (a-*this).cross(b-*this);}
    T dist2()const {return x*x+y*y;}
    double dist()const{return sqrt(double(dist2()));}
    double angle() const {return atan2(y,x);}
    P unit()const{return *this/dist();}
    P perp()const{return P(-y,x);}
    P normal()const{return perp().unit();}
    P rotate(double a)const{
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
    }
    friend ostream& operator<<(ostream&os,P p){
        return os<<'('<<p.x<<','<<p.y<<')';
    }
};

typedef Point<double>P;
vector<P> convexHull(vector<P>pts){
    if(pts.size()<=1)return pts;
    sort(pts.begin(),pts.end());
    vector<P>h(pts.size()+1);
    int s=0,t=0;
    for(int it=2;it--;s=--t,reverse(pts.begin(),pts.end())){
        for(P p:pts){
            while(t>=s+2&&h[t-2].cross(h[t-1],p)<=0)t--;
            h[t++]=p;
        }
    }
    return {h.begin(),h.begin()+t-(t==2&&h[0]==h[1])};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<P>v(n);
    for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
    v=convexHull(v);
    double d=0;
    for(int i=0;i<v.size();i++){
        d+=(v[(i+1)%v.size()]-v[i]).dist();
    }
    int x=0;
    for(int i=0;i<v.size();i++)if(v[i].y==0)x=max(x,(int)v[i].x);
    cout<<max((double)0,ceil((m-x)/d))<<endl;
}
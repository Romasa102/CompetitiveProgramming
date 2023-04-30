#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B;
    cin >> A >> B;
    vector<int> a;
    vector<int> b;
    int M = A;
    int N = B;
    bool easy = true;
    while(M > 0){
        a.push_back(M%10);
        M/=10;
    }
    while(N > 0){
        b.push_back(N%10);
        N/=10;
    }
    int lengthMax = 0;
    if(a.size() >= b.size()){
        lengthMax = a.size();
    }else if(a.size() <= b.size()){
        lengthMax = b.size();
    }

    for (int i = 0; i < lengthMax; i++)
    {
        if(a[i] + b[i] > 10){
            easy = false;
            break;
        }
    }
    if(easy){
        cout << "Easy" << endl;
    }else{
        cout << "Hard" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int a[100];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int sumForA = 0;
    int sumForB = 0;
    sort(a, a + N, greater<int>());
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            sumForA += a[i];
        }
        if(i % 2 == 1){
            sumForB += a[i];
        }
    }
    cout << sumForA - sumForB << endl;
}
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int min1 = INT_MIN, min2 = INT_MIN;
        for(int i=0; i<n; i++){
            int t; cin >> t;
            if(t >= min1){
                min2 = min1;
                min1 = t;
            }else if(t > min2)
                min2 = t;
        }
        cout << min1 + min2 << endl;
    }
}
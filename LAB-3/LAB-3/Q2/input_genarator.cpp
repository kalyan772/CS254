#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
int main() {

    freopen("test_cases_Q2.txt","w",stdout);

    cin.tie(NULL);
	int tt = rand()%100; 
	cout<< tt <<"\n"; 
	while(tt--)
	{
       int n = rand()%1000; 
       cout << n <<"\n"; 
       for (int i = 0; i < n; ++i){
       cout<<(rand()%1000)-500<<" ";
       } cout<<"\n";
    }
    return 0;
}
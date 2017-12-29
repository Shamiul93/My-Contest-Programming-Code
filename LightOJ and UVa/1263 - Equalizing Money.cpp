#include<bits/stdc++.h>


using namespace std;
#define ll long long

int main()
{
     vector<double> v ;

     v.push_back(0);
    for(ll i = 1 ; i <= 1000000 ; i++)
    {
        double s ;
        s = log10(i);
        v.push_back(s);
    }

	return 0 ;
}

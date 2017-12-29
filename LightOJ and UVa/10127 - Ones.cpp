#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    while(cin>> n)
    {
        int num = 1 , counter = 1 ;
        while(num % n != 0 )
        {
            num = (num * 10 + 1 )% n ;
            counter ++ ;
        }

        cout << counter << endl ;
    }

    return 0 ;
}

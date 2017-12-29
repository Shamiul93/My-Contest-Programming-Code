#include<stdio.h>
#include<iostream>
using namespace std ;


long long int a, b, c, d, e, f;

long long int fn( long long int n )
{
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}

int main()
{
    long long int n, caseno = 0, t=0 , cases;
    cin>> cases ;
    while( t<cases )
    {
        cin>> a>> b>> c>> d>> e>> f>> n;
        printf("Case %I64d: %I64d\n", ++caseno, fn(n) % 10000007);
        t++ ;
    }
    return 0;
}

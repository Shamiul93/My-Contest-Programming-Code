/**
//@author: Rumman BUET CSE'15
Problem: 1028 - Trailing Zeroes (I)
Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1028

Concept:

This problem is a perfect example for prime factorization and
counting the number of all factors.

1. At first we use sieve from 2 to 10^6 (square root of 10^12)
2. In vector v we put all the primes from this sieve
3. Now we take the input of the number. We divide and modulo this number by
   all the primes smaller than it from vector v
4. Thus we can count how many times a prime factor is multiplied inside it.
5. We know that all integers can be prime factorized. Now this happened here.
6. Now the rest is HSC Level Higher Math problem.
   -> An integer has prime factors 2,3,5 respectively 4,3,1 times.
   How many factors does it have?

   Ans: Every number can be taken as many times as it appears. i.e. respectively
   2 or 3 or 5 times. And there is another way for a which is - "Taking zero times."
   so , ans = (2+1)*(3+1)*(5+1) - 1 .
   Why (-1) ? because , there is one way which means - "Taking no prime factors".
   That means 0 . - That would make no sense.

   That's all.

*/

#include <bits/stdc++.h>
#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

#define sz 1000010

vector<ll> v ;

int main()
{
    fi;
    fo;

    bool arr[1000010] = {} ;
//    cout << "hi" << endl ;
    memset(arr, true, sizeof(arr));
    arr[0] = false ;
    arr[1] = false ;


    v.push_back(2);

    for(ll i = 3 ; i < sz ; i+=2)
    {
        if(arr[i] == true )
        {
            v.push_back(i);
            for(ll j = 2*i ; j < sz ; j+= i)
            {
                arr[j] = false ;
            }
        }
    }

    ll T, t = 0 ;

    scanf("%lld",&T);

    while(T--)
    {
        t++ ;
        ll n ;
        scanf("%lld",&n);

        ll a = n ;
        ll ans = 1 ;

        /// v[i]*v[i] <= a - At first I wrote n in stead of a . Got WA several times.
        for(ll i= 0 ; i< v.size(), a > 1, v[i]*v[i] <= a ; i++)
        {

            ll oc = 0 ; /// occurrence number of a certain factor

            ll r = 0 ;
            while(r == 0 && a > 1)
            {
                r = a % v[i] ;

                if(r==0)
                {
                    oc++ ;
                    a = a / v[i] ;
                }

            }
            if(oc > 0)
            {
                ans = ans * (oc + 1) ;
            }
        }




        if(a > 1)
        {
            ans *= (1+1) ;
        }

        /**
         * Question may arise why  ans *= (1+1) ; in the next line?
         Ans: If a quotient is nonzero after dividing it with all the primes,
         and yet it's non zero except 1 , then it's a PRIME Itself. So , take it .

         * Only one prime factor of a number can be greater than sqrt of n.
         a*b*c = n (say)
         say , a > sqrt(n) , b> sqrt(n) , c< sqrt(n)
         a*b > n ; c is not even multiplied yet.
         SO, you see...
        */


        printf("Case %lld: %lld\n",t, ans - 1 ) ;

    }

    return 0 ;
}





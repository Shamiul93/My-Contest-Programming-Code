/**
@author - Rumman BUET CSE'15
27-2-2017

Problem - 1062 - Crossed Ladders

link - http://www.lightoj.com/volume_showproblem.php?problem=1062

Concept:

    It's a famous bisection problem for me and not many people has solved it.
    But I could solve it in half an hour when I didn't become a "Coder".
    So, pretty special for me.

    Whatever, This is mainly a mathematical problem.

    We know a(x) , b(y) , c . By bisection we will continuously take a value of W.
    At first , calculate the angles between W and x . Same for W and y.
    by these angles you can calculate height of buildings p and q .

    from Similar Angle Triangle formulas,
        we get ,

            c/p = m / w ; [ m is one part of W after intersecting C ]
        and for other part ,

            c / q = (W - m ) / W = 1 - m/W ;
        From these 2 eqn , we get ,

            c/q = 1 - c/p ;
            => c = 1 / (1/p + 1/q) ;

        ***Bisection:

            For this , we will take continuously changing value for W.
            The highest value of W can be p+q - d ; because , when the ladders
            touch the land , it will be the highest W. but we minus 'd' from it
            because we don't want to make 'c' = 0 .

        ***Condition:

            We can observe that, if W increases , C decreases because , while
            W increasing , the intersecting point is coming down. So,

            "THE RELATION BECOMES OPPOSITE TO OTHER PROBLEMS."

*/

#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define d 0.000000001
#define isprime false

double a , b , c , p , q , w ;

double formula()
{
    double t1 , t2 , C ;
    t1 = acos(w*1.0 / a) ;
    p = a * sin(t1) ;

    t2 = acos(w*1.0 / b) ;
    q = b * sin(t2) ;

    C = 1.0 / ( (1.0 / p) + (1.0 / q) ) ;
    return C ;
}

int main()
{
    ll T , t = 0 ;
    scanf("%lld",&T);

    while(T--)
    {
        t++ ;
        scanf("%lf %lf %lf",&a , &b , &c);

        double hi , lo , h ;

        lo = d ;
        hi = a+b-d ;

        while(hi - lo > d)
        {
            w = (lo+hi) / 2.0 ;
            h = formula();

            if(h > c)
            {
                lo = w ;
            }
            else
            {
                hi = w ;
            }
        }

        printf("Case %lld: %.10f\n",t , w) ;

    }

    return 0 ;
}

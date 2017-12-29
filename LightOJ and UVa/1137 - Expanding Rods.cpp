/**
@author - Rumman BUET CSE'15
Problem - 1137 - Expanding Rods
Link - http://www.lightoj.com/volume_showproblem.php?problem=1137

Concept-

    ** It's mainly a geometric problem. May be tough may be not.
    ** ( It's another special one for me. My friend and teammate in 2017 Pranto gave me this problem
        when I was not that extreme level coder. I solved it in <= 20 minutes. It felt good.
        Idea was good too. :3 )

    ** We will run binary search on radius of the arc from l/2 ( it's the lowest because
       if the radius is smaller than it then , the circle would not touch the chord's 2 ends.)
        to 10000(as high as possible).

    ** distance from center to the chord and center angle of
       the arc can be calculated by pethagoras.

    ** When s=r*theta is equal to new L , then it's the answer.

*/


#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define DEBUG printf("hi\n");
#define DEBUG2 printf("bi\n");
#define di 0.00000001

double  L, N, C, Lnew, r ;


using namespace std ;
int main()
{
//    fi ;
//    fo ;
    ll T, t = 0 ;
    double ans ;
    scanf("%lld ",&T) ;

    while(T--)
    {
        t++ ;
        scanf("%lf %lf %lf", &L, &N, &C) ;
        Lnew = ( 1.0 + N*C )* L ;

        r = L / 2.0 ;

        double hi, lo, mid, s = 0, per, halfang, ang  ;

        lo = r ;
        hi = 100000 ;
        ll k = 0 ;

        /// However efficient binary search is, we know bisection is not exactly accurate
            /// as precision loss happens. And we know , L= L prime. , so , h = 0. So, we take it
            /// particularly.
        if(L == Lnew)
        {
            ans = 0 ;
        }
        else
        {
            while(k < 66)
            {
                k++ ;
                mid = (lo + hi) / 2.0 ;
                per = sqrt( 1.0*mid*mid - r*r) ;
                ang = 2.0  * asin(r *1.0 / mid) ;
                s = mid * ang ;

                if(s > Lnew )
                {
                    lo = mid ;
                }
                else
                {
                    hi = mid ;
                }
            }

            ans = mid - per ;

        }



        printf("Case %lld: %.10f\n",t, ans) ;

    }

    return 0 ;
}

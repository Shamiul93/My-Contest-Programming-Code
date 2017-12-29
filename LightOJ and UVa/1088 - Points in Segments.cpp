/**
@author - Rumman BUET CSE'15
problem - 1088 - Points in Segments

link - http://www.lightoj.com/volume_showproblem.php?problem=1088

Concept -

    ** This problem uses a basic concept of Binary Search. - Upper bound & Lower bound.

    # Lower bound:
        The number which is leftmost and either greater than or equal to our target number is called the lower bound
        of that number.

    ** We know how to get lower bound.


    # Upper bound:
        The number which is the leftmost and strictly greater than our target number in a sorted array is called
        the upper bound of the number.

    ** We know how to find lower bound. I used a trick to find upper bound.

    # Think , if we want to get an integer number which is obviously and strictly greater than our target number ,
      we can increase the number by 1 and take the lower bound of that number.
      Thus we can find upper and lower bound by only one function. There are some other ways. But I found it useful.
      Have to test it more later.

*/


#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define DEBUG printf("hi\n");
#define DEBUG2 printf("bi\n");

using namespace std ;

vector<ll> v ;
ll n, q ;
ll f, l ;

void input()
{
    v.clear() ;
    for(ll i = 0 ; i< n ; i++)
    {
        ll a ;
        scanf("%lld",&a) ;
        v.push_back(a) ;
    }

    sort(v.begin(), v.end()) ;
}

ll LowerBound(ll f)
{
    ll lo, hi, mid ;
    hi = v.size() - 1 ;
    lo = 0 ;
    while(lo <= hi)
    {
        mid = (lo + hi)/2 ;

        if(f == v[mid])
        {
            hi = mid - 1 ;
        }
        else if(f > v[mid])
        {
            lo = mid + 1 ;
        }
        else
        {
            hi = mid - 1 ;
        }
    }

    return lo ;
}

int main()
{
    ios::sync_with_stdio();
//    fo ;
//    fi ;


    ll T, t = 0 ;

    cin >> T ;

    while(T--)
    {

        t++ ;
        printf("Case %lld:\n",t) ;
        scanf("%lld %lld",&n, &q) ;

        input();

        while(q--)
        {

            scanf("%lld %lld",&f, &l);

            if(f > l)
            {
                swap(f, l) ;
            }

            ll Firstidx, Lastidx, ans ;

            Firstidx = LowerBound(f) ;

            l++ ;

            Lastidx = LowerBound(l) ;

//            cout << f << " " << --l << endl ;

//            cout << Firstidx << " " << Lastidx << endl  ;
            ans =  Lastidx - Firstidx   ;

            printf("%lld\n", ans) ;
//            cout << endl ;
        }
    }

    return 0 ;
}

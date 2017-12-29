#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std ;

int one(int num)
{
    long long int mask = 1 , y ;
    int c1 = 0  ;

    mask = mask << ((8*sizeof(long long int))-2);
    while(mask)
    {
        y = num & mask ;
        if(y)
        {
            //cout << "1";
            c1++ ;
        }
//        else
//        {
//            cout << "0";
//        }

        mask = mask >> 1 ;
    }

    return c1 ;
    //cout<< " = " << c <<  endl ;
}

int main()
{
    long long int num ;
    //cin>> n ;
    long long int mask = 1 ;
    long long int  y ;

    int c1 = 0 , c0 = 0 , test , t= 0  ;

    cin>> test ;
    while(t<test)
    {
        cin >> num ;
        c1 = one(num) ;
        mask = 1 ;
        //mask = mask << ((8*sizeof(long long int))-2);
        while(!y)
        {
            y = num & mask ;
            if(y)
            {
                c0++ ;
            }
            mask = mask << 1 ;
        }
        int diff ;
        diff = pow(2,c0);
        long long int closest ;
        closest = num + diff ;
        ///cout<< closest ;
        int onenew = -1 ;
        while(onenew!=c1)
        {
            onenew = one(closest);
            closest++ ;
        }
        closest -- ;


        printf("Case %d: %lld\n",t+1 , closest);
        t++ ;
    }
}

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std ;


struct pnt
{
    long long int x ;
    long long int y ;
};

typedef pnt point ;

int main()
{
    long long int test , p , q ;
    cin>> test ;
    long long int pc = 0  , qc = 0 , i , t = 0 ;
    while(test--)
    {
        t++ ;
        cin >> p >> q ;
        point arr[p+1];

        i = 0 ;
        printf("Case %lld:\n",t);
        while( pc < p )
        {
            cin>> arr[i].x >> arr[i].y ;
            i++ ;
            pc++ ;
        }

        while(qc < q)
        {
            long long x1 , y1 , x2 , y2 , j , num = 0 ;

            cin >> x1 >> y1 >> x2 >> y2 ;

            for(j=0 ; j< p ; j++)
            {
                if(arr[j].x >= x1 && arr[j].x <= x2\
                   && arr[j].y >= y1 && arr[j].y <= y2 )
                {
                    num ++ ;
                }
            }

            cout << num << endl ;

            qc++ ;
        }
    }

    return 0 ;
}


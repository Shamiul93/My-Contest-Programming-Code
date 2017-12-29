
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std ;
int main()
{

    int i , t  , arr[] = {1,2,3,4,5,6,7,8,9,10} ;
//    for(i=0 ; i< 6 ; i++)
//    {
//        t=arr[i];
//        arr[i]=arr[9-i];
//        arr[9-i]=t ;
//    }
//    int  f , l  ;
//    cin>> f >> l ;
//    f=f-1;
//    l=l-1;
//    t=arr[f];
//    arr[f]=arr[l];
//    arr[l]=t ;
//int i , t ;
    int len = 10 ;
    for(i=0 ; i<= len/2 ; i++)
    {
        t=arr[i];
        arr[i]=arr[(len-1)-i];
        arr[(len-1)-i]=t ;
    }

    for(i=0 ; i< 10 ; i++)
    {
        cout<< arr[i]<< " ";
    }

//    char str1[1200] , str2[1200];
//    int i , test , t=0 ;
//    cin>> test ;
//
//    while(t<test)
//    {
//        scanf(" %s",str1);
//        int len = 0 ;
//        i=0 ;
//        while(str1[i])
//        {
//            len++;
//            i++ ;
//        }
//        for(i=0; i<len ; i++)
//        {
//            str2[len-i]=str1[i];
//        }
//        int tem = 1  ;
//
//        for(i=1; i<=len ; i++)
//        {
//            if(str2[i]!=str1[i-1])
//            {
//                tem = 0 ;
//                break ;
//            }
//        }
//
//        if(tem)
//        {
//            printf("Case %d: Yes\n",t+1);
//        }
//        else
//        {
//           printf("Case %d: No\n",t+1);
//        }
//        t++;
//    }
}

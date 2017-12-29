#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std ;

int main()
{
    long long first , last , day1,day2 ,yr1,yr2 , divby400 , leapday , i ;
    char month[15][15]=
    {
        "January", "February", "March","April",
        "May", "June", "July", "August",
        "September","October", "November" , "December"
    } ;
    char str1[15] , str2[15] ;
    scanf("%s ",&str1) ;
    scanf("%I64d, %I64d",&day1 , &yr1);
    scanf("%s ",&str2) ;
    scanf("%I64d, %I64d",&day2 , &yr2);

    divby400= ((yr2-1)/400)-((yr1-1)/400);
    leapday= divby400*97 ;
    last = (divby400*400)+1 ;
    for(i=last ; i<yr2 ; i++)
    {
        if((i%400==0)||(i%4==0&&i%100!=0))
        {
            leapday++ ;
        }
    }
    int monthname1 , monthname2 , idx1 , idx2 ;
    for(i=0 ; i<12 ; i++)
    {
        if(!strcmp(month[i],str1))
        {
            idx1 = i+1 ;
        }
        if(!strcmp(month[i],str2))
        {
            idx2 = i+1 ;
        }
    }
    if(idx1>2)
    {

        if((yr1%400==0)||(yr1%4==0&&yr1%100!=0))
        {
            leapday-- ;
        }
    }
    if((idx2==2&&day2==29)||(idx2>2))
    {

        if((yr2%400==0)||(yr2%4==0&&yr2%100!=0))
        {
            leapday++ ;
        }
    }

    cout<< leapday <<endl ;

}

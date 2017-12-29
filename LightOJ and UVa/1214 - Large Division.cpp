#include<iostream>
#include<cstdio>
using namespace std ;

int main()
{
    char ch ;
    int t= 0 ;
    long long int test ;
    cin>> test ;
    while(test--)
    {
        t++ ;
        long long int arr[1000]= {} , num  ;
        int i = 0 ;
        while(1)
        {
            (!i)?scanf(" %c",&ch):scanf("%c",&ch);
            if(ch!='-' && ch!=' ')
            {
                arr[i] = ch - '0' + 0 ;
                i++ ;
            }
            else if(ch==' ')
            {
                break ;
            }
        }
        int idx ;
        idx = (i-1) ;
        cin >> num;
        i = 0 ;
        long long int a , b , rem ;
        a = arr[i];
        b = num ;
        while(i<=idx)
        {
            rem = a%b ;
            i++ ;
            a = rem * 10 + arr[i];
        }
        if(!rem)
        {
            printf("Case %d: divisible\n",t);
        }
        else
        {
            printf("Case %d: not divisible\n",t);
        }
    }
    return 0 ;
}

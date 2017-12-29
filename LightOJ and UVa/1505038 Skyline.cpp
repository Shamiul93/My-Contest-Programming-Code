#include <bits/stdc++.h>
#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000

using namespace std;

class point
{
public:
    ll x ;
    ll y ;

    point()
    {
        x = 9999999 ;
        y = 9999999 ;
    }

    point(ll a, ll b)
    {
        x = a ;
        y = b ;
    }
};

int dominance[mx] = {} ;
point arr[mx] ;
ll T ;

void print()
{
    int tem = 0 ;

    for(ll i = 0 ; i < T ; i++)
    {
        if(dominance[i] == 1)
        {
            cout <<  arr[i].x << " " <<  arr[i].y  << endl ;
            tem = 1 ;
        }
    }

    if(tem == 0)
    {
        cout << "No Non-Dominating Element Found." << endl ;
        return ;
    }

    return ;
}


void Merge(ll lo, ll mid, ll hi)
{
    int i, j, k;

    int n1 = mid - lo + 1;
    int n2 =  hi - (mid + 1) + 1 ; // n2 == hi - mid ;


    point L[n1], R[n2];


    for (i = 0; i < n1; i++)
    {
        L[i] = arr[lo + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }


    i = 0 ;
    j = 0 ;
    k = lo ;

    while (i < n1 && j < n2)
    {
        if (L[i].x < R[j].x)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return ;
}


void mergeSort(ll lo, ll hi)
{
    if (lo >= hi)
    {
        return ;
    }

    ll mid = (lo+hi) / 2 ;

    mergeSort(lo, mid);
    mergeSort(mid+1, hi);

    Merge(lo, mid, hi);
    return ;
}

ll p = 0 ;
void skyline(ll lo, ll hi)
{
    if(lo == hi)
    {
        return ;
    }
    ll mid ;
    mid = (lo + hi) / 2 ;

    skyline(lo, mid) ;
    skyline(mid+1, hi) ;

    int tem = 0 ;

    for(ll i = mid + 1 ; i <= hi ; i++)
    {
        if(arr[i].y <= arr[mid].y && arr[i].x <= arr[mid].x)
        {
            tem = 1 ;
            break ;
        }
//        if(arr[i].x > arr[mid].x)
//        {
//            break ;
//        }
    }

    if(tem == 0)
    {
        for(ll i = mid - 1 ; i >= 0 ; i--)
        {
            if(arr[i].y <= arr[mid].y && arr[i].x <= arr[mid].x)
            {
                tem = 1 ;
                break ;
            }
        }
    }

    if(tem == 0)
        dominance[mid] = 1 ;

    return ;
}


int main()
{
    fi ;

    ll t = 0 ;
    cin >> T ;
    ll num ;
    num = T ;

    while(num--)
    {
        t++ ;
        ll x, y ;
        cin >> x >> y ;
        arr[t] = point(x,y) ;
    }

    mergeSort(0, T) ;
    skyline(0, T-1) ;
    print() ;

    return 0 ;
}

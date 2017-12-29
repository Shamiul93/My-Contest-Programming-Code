// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>
#define ll                                      long long int
#define ull                                     unsigned long long
#define ld                                      long double

#define ff                                      first
#define ss                                      second

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define pi acos(-1.0)
#define debug                                   printf("yes\n")
#define what_is(x)                              cout << #x << " is " << x << endl
#define pf                                      printf
#define sf                                      scanf

#define pb                                      push_back
#define mp                                      make_pair
#define eb                                      emplace_back
#define pii                                     pair<int, int>
#define piii                                    pair<pii, int>

#define SQR(a)                                  ((a)*(a))
#define QUBE(a)                                 ((a)*(a)*(a))

#define scanI(a)                                scanf("%d",&a)
#define scanI2(a,b)                             scanI(a) , scanI(b)
#define scanI3(a,b,c)                           scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d)                         scanI(a), scanI(b), scanI(c), scanI(d)

#define sll(a)                                scanf("%lld",&a)
#define sll2(a,b)                             sll(a) , sll(b)
#define sll3(a,b,c)                           sll(a), sll(b), sll(c)
#define sll4(a,b,c,d)                         sll(a), sll(b), sll(c), sll(d)

#define inf LLONG_MAX
#define minf LLONG_MIN
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define M 10000

using namespace std;


ull Hash1(string s)
{
    ull Tem = 5387 ;

    for(ull i = 0 ; i < s.size() ; i++)
    {
        ull c ;
        c = (int) s[i] ;
        Tem = (Tem % M * 33 % M + c % M) % M ;
    }
    return Tem ;
}


ull Hash2(string s)
{
    ull Tem = 5837 ;

    for(ull i = 0 ; i < s.size() ; i++)
    {
        Tem ^= (int) s[i] ;
        Tem  = Tem << 5 ;
        Tem *= Tem >> 2 ;
        Tem += Tem << 3 ;
        Tem ^= Tem << 2 ;
    }
    return Tem % M ;
}


ull Hash3(string s)
{
    ull Tem ;
    for(ull  i = 0 ; i < s.size() ; i++)
    {
        Tem = i ;
        Tem += (int) s[i];
        Tem += (Tem << 10);
        Tem ^= (Tem >> 6);
    }

    Tem += (Tem << 3);
    Tem ^= (Tem >> 11);
    Tem += (Tem << 15);

    return Tem % M ;
}


class KeyVsValue
{
public:
    string Key ;
    ll Value ;

    KeyVsValue()
    {
        Key = "notUsed" ;
        Value = -1 ;
    }

    KeyVsValue(string _Key, ll _Value)
    {
        Key = _Key ;
        Value = _Value ;
    }

    bool operator == (const KeyVsValue& kv);
};

bool KeyVsValue::operator==(const KeyVsValue& kv)
{
    return (Key == kv.Key && Value == kv.Value) ;
}


class KeyVsValueChain
{
public:
    string Key ;
    ll Value ;

    KeyVsValueChain *next ;

    KeyVsValueChain()
    {
        Key = "notUsed" ;
        Value = -1 ;
        next = 0 ;
    }
};



class Hash
{
public:
    ll Value, Collision, choice ;
    KeyVsValue ProbeArr[10020] ;
    KeyVsValueChain ChainArr[10020] ;
    ll SizeOfChainArr[10020] ;

    Hash()
    {
        Value = 0 ;
        Collision = 0 ;
        for(ll i = 0 ; i < 10020 ; i++) SizeOfChainArr[i] = 0;
    }
    Hash(ll _Choice)
    {
        Value = 0 ;
        Collision = 0 ;
        choice = _Choice ;
        for(ll i = 0 ; i < 10020 ; i++) SizeOfChainArr[i] = 0;
    }


    bool insertChain(string Key);
    bool deleteChain(string Key);
    bool searchChain(string Key);

    bool insertProbing(string Key);
    bool deleteProbing(string Key);
    bool searchProbing(string Key);


};

bool Hash::insertChain(string Key)
{
    ll Position ;

    if(choice == 1) /// Hash1
    {
        Position = Hash1(Key) ;
    }
    else if(choice == 2) /// Hash2
    {
        Position = Hash2(Key) ;
    }
    else if(choice == 3) /// Hash3
    {
        Position = Hash3(Key) ;
    }

    ll curr = Position ;
    KeyVsValueChain *tem ;


///1. onno keu ase......2. nijei already ase.....3. deleted ase....

    tem = &ChainArr[curr] ;

    while(1)
    {
//        cout << tem -> Key << endl ;
        if(tem -> Key == "notUsed" || tem -> Key == "Deleted")
        {
//            cout << "not used / deleted" << endl ;
//            cout << tem -> Key << endl ;
            tem -> Key = Key ;
            tem -> Value = Value ;
            Value++ ;
//            cout << tem -> Key << endl ;
            return true ;
        }
        if(tem -> Key == Key)
        {
//            cout << "Repeat" << endl ;
            return false ;
        }


        KeyVsValueChain *prev ;

        if(tem -> Key != Key)
        {
//            cout << "Going On!!!!" << endl ;
            Collision++;

            prev = tem ;
//            cout << prev->Key << endl ;
            tem = tem -> next ;
//            cout << tem -> Key << endl ;
            if(tem == 0)
            {
//                cout << Value << " " << Position << ChainArr[Position].Key << " " << Key << endl ;
                KeyVsValueChain *New ;
                New = new KeyVsValueChain ;
//                cout << "protik" << endl ;



                New -> Key = Key ;

//                cout << "sdkhfl" << endl ;

                New -> Value = Value ;
                New -> next = 0;

                prev -> next = New ;
//                cout << prev-> Key << endl ;
//                cout << "ji" << endl ;
//                cout << New-> Key << endl ;
                Value++;
                return true ;
            }
//            cout << "bleh" << endl ;
        }
    }
}


bool Hash::deleteChain(string Key)
{
    ll Position ;

    if(choice == 1) /// Hash1
    {
        Position = Hash1(Key) ;
    }
    else if(choice == 2) /// Hash2
    {
        Position = Hash2(Key) ;
    }
    else if(choice == 3) /// Hash3
    {
        Position = Hash3(Key) ;
    }

    ll curr = Position ;
    KeyVsValueChain *tem ;


///1. onno keu ase......2. nijei already ase.....3. deleted ase....

    tem = &ChainArr[curr] ;

    while(1)
    {
        if(tem -> Key == "notUsed")
        {
            return false ;
        }

        if(tem -> Key == Key)
        {
            tem -> Key = "Deleted" ;
            tem -> Value = -1 ;
            return true ;
        }

        if(tem -> Key != Key)
        {
            tem = tem -> next ;
            if(tem == 0)
            {
                return false;
            }
        }
    }
}


bool Hash::searchChain(string Key)
{
    ll Position ;

    if(choice == 1) /// Hash1
    {
        Position = Hash1(Key) ;
    }
    else if(choice == 2) /// Hash2
    {
        Position = Hash2(Key) ;
    }
    else if(choice == 3) /// Hash3
    {
        Position = Hash3(Key) ;
    }

    ll curr = Position ;
    KeyVsValueChain *tem ;


///1. onno keu ase......2. nijei already ase.....3. deleted ase....

    tem = &ChainArr[curr] ;

    while(1)
    {
        if(tem -> Key == "notUsed")
        {
            return false ;
        }

        if(tem -> Key == Key)
        {
            return true ;
        }

        if(tem -> Key != Key)
        {
            tem = tem -> next ;
            if(tem == 0)
            {
                return false;
            }
        }
    }
}


bool Hash::insertProbing(string Key)
{
    ll Position ;

    if(choice == 1) /// Hash1
    {
        Position = Hash1(Key) ;
    }
    else if(choice == 2) /// Hash2
    {
        Position = Hash2(Key) ;
    }
    else if(choice == 3) /// Hash3
    {
        Position = Hash3(Key) ;
    }

    ll curr = Position ;

    while(1)
    {
        if(ProbeArr[curr].Key == Key)
        {
            return false ;
        }

        if(ProbeArr[curr].Key == "notUsed" || ProbeArr[curr].Key == "Deleted")
        {
            ProbeArr[curr] = KeyVsValue(Key, Value) ;
            Value++ ;
            return true ;
        }

        Collision++;
        curr = (curr + 1) % M ;
    }
}

bool Hash::deleteProbing(string Key)
{
    ll Position ;

    if(choice == 1) /// Hash1
    {
        Position = Hash1(Key) ;
    }
    else if(choice == 2) /// Hash2
    {
        Position = Hash2(Key) ;
    }
    else if(choice == 3) /// Hash3
    {
        Position = Hash3(Key) ;
    }

    ll curr = Position ;

    ll t = 0 ;

    while(1)
    {
        if(ProbeArr[curr].Key == "notUsed")
        {
            return false ;
        }
        if(ProbeArr[curr].Key == Key)
        {
            ProbeArr[curr].Key = "Deleted" ;
            return true ;
        }
        curr = (curr + 1) % M ;
    }
}

bool Hash::searchProbing(string Key)
{
    ll Position ;

    Collision = 0 ;

    if(choice == 1) /// Hash1
    {
        Position = Hash1(Key) ;
    }
    else if(choice == 2) /// Hash2
    {
        Position = Hash2(Key) ;
    }
    else if(choice == 3) /// Hash3
    {
        Position = Hash3(Key) ;
    }

    ll curr = Position ;

    while(1)
    {
        if(ProbeArr[curr].Key == "notUsed")
        {
            return false ;
        }

        if(ProbeArr[curr].Key == Key)
        {
            return true ;
        }

        curr = (curr + 1) % M ;
    }
}


vector<string> DataSet1, DataSet2 ;
ll Number,  Length ;



ll c1 , c2 , c3 , c4 , c5 , c6 ;

Hash RandomStringChain(ll Num,  ll Len , ll Choice)
{
    srand(time(NULL));
    Hash h(Choice) ;
    ll Collision = 0 ;

    for(ll i = 0 ; i < Num ;  )
    {
        string s = "" ;
        for(ll j = 0 ; j < Len ; j++)
        {
            ll r ;
            char c ;
            r = rand() % 26 ;
            c = (char) 'A' + r ;
            s = s + c ;
        }


        if(h.insertChain(s) == true)
        {
            i++;
//            cout << i << endl ;
            Collision += h.Collision ;
            DataSet1.push_back(s) ;
        }
    }
    return h ;
}



Hash RandomStringLinear(ll Num,  ll Len , ll Choice)
{
    srand(time(NULL)) ;
    Hash h(Choice) ;
    ll Collision = 0 ;

    for(ll i = 0 ; i < Num ;  )
    {
        string s = "" ;
        for(ll j = 0 ; j < Len ; j++)
        {
            ll r ;
            char c ;
            r = rand() % 26 ;
            c = (char) 'A' + r ;
            s = s + c ;
        }


        if(h.insertProbing(s) == true)
        {
            i++;
            Collision += h.Collision ;
            DataSet1.push_back(s) ;
        }
    }
    return h ;
}


Hash ch1, ch2 , ch3 , ph1, ph2, ph3 ;
set<string> st ;
ll chk()
{
        cout << DataSet1.size() << endl ;

for(ll i = 0 ; i < DataSet1.size() ; i++)
{
    st.insert(DataSet1[i]) ;
}
cout << st.size() << "hgk" << endl ;

st.clear();
DataSet1.clear();
}

map<string, ll> Map;

void Random2()
{
    srand(time(NULL));

    ll t = 0 ;

    for(ll i = 0 ; i < Number ; )
    {
        string s = "" ;
        for(ll j = 0 ; j < Length ; j++)
        {
            ll r ;
            char c ;
            r = rand() % 26 ;
            c = (char) 'A' + r ;
            s = s + c ;
        }

        if(Map.find(s) == Map.end())
        {
            Map[s] = t ;
            DataSet2.push_back(s) ;
            t++;
            i++;
        }

    }

}


Hash JustInsertLinear(ll Num,  ll Len, ll Choice)
{
    Hash h(Choice) ;
    ll Collision = 0 ;

    for(ll i = 0 ; i < Num ;  i++)
    {
        string s ;
        s = DataSet1[i] ;

        if(h.insertProbing(s) == true)
        {
            Collision += h.Collision ;
        }
    }
    return h ;
}

#define break cout << "ksdbjh" <<  endl ;


int main()
{
    cin >> Number >> Length ;
//
//    Number = 10000 ;
//    Length = 5 ;


    ph1 = RandomStringLinear(Number, Length, 1);
    ph2 = JustInsertLinear(Number, Length, 2);
    ph3 = JustInsertLinear(Number, Length, 3);
//
    Random2();

    cout << DataSet2.size() << endl ;

    cout << "Linear Probing Method: " << endl ;


//    cout << Da
    clock_t Begin = clock() ;
    for(ll i = 0 ; i < DataSet2.size() ; i++)
    {
        ph1.searchProbing(DataSet2[i]);
    }
    clock_t End = clock() ;
    double elapsed_secs = double(End - Begin) / CLOCKS_PER_SEC ;
    cout << "Hash1: " << "Collisions: " << ph1.Collision << "       Search Time: " <<  elapsed_secs << endl ;


    Begin = clock() ;
    for(ll i = 0 ; i < DataSet2.size() ; i++)
    {
        cout << "hi" << endl ;
        ph2.searchProbing(DataSet2[i]);
    }
    End = clock() ;
    elapsed_secs = double(End - Begin) / CLOCKS_PER_SEC ;
    cout << "Hash1: " << "Collisions: " << ph2.Collision << "       Search Time: " << elapsed_secs << endl ;


    Begin = clock() ;
    for(ll i = 0 ; i < DataSet2.size() ; i++)
    {
        ph3.searchProbing(DataSet2[i]);
    }
    End = clock() ;
    elapsed_secs = double(End - Begin) / CLOCKS_PER_SEC ;
    cout << "Hash1: " << "Collisions: " << ph3.Collision << "       Search Time: " << elapsed_secs << endl ;








    return 0 ;
}


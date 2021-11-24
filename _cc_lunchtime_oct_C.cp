#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<list>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>
using namespace std;


#define ff              first
#define ss              second
#define ll              long long int
#define ull             unsigned long long int
#define pb              push_back
#define eb              emplace_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define nline           "\n"
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

#define fi(a,b,step)       for( ll i = a; i < b; i+=step)
#define fj(a,b,step)       for( ll j = a; j < b; j+=step)
#define fr(var,a,b,step)   for( ll var = a; var < b; var+=step)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)     { cerr << t ; }
void _print(int t)    { cerr << t ; }
void _print(string t) { cerr << t ; }
void _print(char t)   { cerr << t ; }
// void _print(lld t)    { cerr << t ; }
void _print(double t) { cerr << t ; }
void _print(ull t)    { cerr << t ; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//---------------------------------------------------------------------------
void IO() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

void solve() {

   ll n , k;
   cin >> n >> k;
   ll arr[n * n];

   for (int i = 0; i < n * n; ++i)
      cin >> arr[i];
   sort(arr, arr + n * n);

   ll leftNums = n / 2 ;
   ll rightNums = n * ( n - 1 - n / 2 ) ;
   ll lo , hi;
   lo = leftNums ;
   hi = n * n - (  rightNums + (n - 1) ) - 1 ;
   ll ttl = n;
   ll ans = -1 ;
   ll v[n * n];

   while (lo <= hi) {

      ll currNo = 0;
      ll m = (hi - (hi - lo) / 2 );
      ll x = 0 , y = m;
      ll pos = 0 , sum = 0 ;
      memset(v, 0, sizeof(v));

      while (currNo != ttl) {

         if (pos == leftNums ) {

            if (v[y])y++;
            else {

               v[y] = 1;
               sum += arr[y];
               currNo++;
               y++;
               pos = 0;
            }

         } else {

            if (v[x]) {
               x++;
            } else {
               v[x] = 1;
               x++ ;
               pos++;
            }
         }
      }

      if (sum <= k) {
         ans = m;
         lo = m + 1;
      } else hi = m - 1;

   }

   if (ans != -1)
      cout << arr[ans] << nline ;
   else cout << -1 << nline;

   return;
}

int main() {

   IO();

   ll t = 1;
   cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}

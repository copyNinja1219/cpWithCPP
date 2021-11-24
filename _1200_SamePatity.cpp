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

typedef                 unsigned long long ull;
typedef                 long double lld;

#define ff              first
#define ss              second
#define ll              long long int
#define pb              push_back
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
void _print(lld t)    { cerr << t ; }
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
void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

void solve() {

   int n , sum;
   cin >> sum >> n;

   if ( !(n & 1) && (sum & 1) ) {
      cout << "NO" << nline;
      return;
   }

   // sum is odd;
   if (sum & 1) {

      bool ans = 0;

      sum -= (n - 1);
      if (sum & 1 && sum > 0) {
         ans = 1;
      }

      if (ans) {

         cout << "YES" << nline;
         for (int i = 0; i < n - 1 ; ++i) {
            cout << "1 ";
         }

         cout << sum << nline;
         return;

      } else {
         cout << "NO" << nline;
         return;
      }


   } else {
      bool ans = 0;
      int sum2 = sum;
      sum2 -= (n - 1);

      sum -= (n - 1) * 2 ;
      if ( (!(sum & 1) && sum > 0) || ((sum2 & 1) && (sum2 > 0)) ) {
         ans = 1;
      }

      if (ans) {

         if (sum > 0) {

            cout << "YES" << nline;
            for (int i = 0; i < n - 1 ; ++i) {
               cout << "2 ";
            }

            cout << sum << nline;
            return;
         } else if ( sum2 & 1 && sum2 > 0) {

            cout << "YES" << nline;
            for (int i = 0; i < n - 1 ; ++i) {
               cout << "1 ";
            }

            cout << sum2 << nline;
         }

      } else {
         cout << "NO" << nline;
         return;
      }
   }




   return;
}

int main() {

   fastInput();

   ll t = 1;
   cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}
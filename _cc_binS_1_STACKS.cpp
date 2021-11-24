
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
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>
using namespace std;

typedef                 unsigned long long int ull;
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
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)


#define fri(a,b,step)   for( int i = a; i < b; i+=step)
#define frj(a,b,step)   for( int j = a; j < b; j+=step)
#define frk(a,b,step)   for( int k = a; k < b; k+=step)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//-----------------------------------------------------------------------------

// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define nline "\n"
// #define pb push_back
// #define ppb pop_back

// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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

bool checkk(ll level, ll coins)	 {
	ll currLevel = 0 , coinsSum = 0;

	for (ll i = 1 ; i <= coins ; i += 1 ) {

		if (coinsSum + i <= coins) {
			coinsSum += i;
			currLevel++;
		} else {
			break;
		}
	}


	return currLevel >= level ;
}


int binsearch(ll value , ll * sortedRadii, ll sizee) {
	// for (int i = 0; i < sizee ; i++) {
	// 	if (sortedRadii[i] > value )return i;
	// }

	ll low = 0, high = sizee , midd = 0;
	ll index = -1;
	while (low <= high) {
		midd = low + (high - low) / 2;
		if ( sortedRadii[midd] > value  ) {
			index = midd;
			high = midd - 1;
		} else	{
			low = midd + 1;
		}
	}

	return index;
}

void solve() {

	ll n;
	cin >> n;

	ll radii[100002] = { -1} ;
	ll sortedRadii[100002] = { 0 } ;

	for (int i = 0; i < n ; i++)cin >> radii[i];

	ll sizee = 1;
	sortedRadii[0] = radii[0];

	for (ll i = 1 ; i < n ; i++) {
		ll idx = binsearch(radii[i] , sortedRadii , sizee );

		if (idx == -1) {

			sortedRadii[sizee] = radii[i];
			sizee++;
		} else {
			sortedRadii[idx] = radii[i];
		}
	}

	// debug(sizee);
	cout << sizee << " ";
	for (ll i = 0 ; i < sizee ; i++) {
		cout << sortedRadii[i] << " ";
	}

	cout << "\n";
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
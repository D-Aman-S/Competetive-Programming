//link:https://codeforces.com/contest/1697/problem/A

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <assert.h>
#define flashio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod1 1000000007
#define mod2 998244353
#define PI 3.14159265358979323846
#define nli  "\n"
#define vl vector<ll>
#define vi vector<int>
#define ff first
#define ss second
#define flop(i,a,b) for(ll i=a;i<b;i++)
#define pint pair<int,int>
#define ali(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define infor(w) for(auto &x:w){cin>>x;}
#define foreach(w) for(auto x:w)
#define ans(x) cout<<(x)<<"\n"
#define sz(x) (int)(x).size()
#define mp make_pair
#define set1(x) __builtin_popcountl(x);
#define fixedfloat std::cout<<std::fixed<<std::setprecision(6)
#define asdp(x,y) memset(x, y, sizeof(x));
#define todvec(a,n,m,value) vector<vector<ll>> a(n, vector<ll>(m,value)) //makes a 2-d vector of n rows and m coloumns
#define todstr(a,n,m,value) vector<vector<char>> a(n, vector<char>(m,value))//2-d string
using namespace std;
using namespace chrono;
using ll = long long int;
using ull = unsigned long long;
using ld = long double ;

/*------------------+++++---------------+++++----------------+++++-----------------+++++------------------+++++----------------*/

#ifndef ONLINE_JUDGE
#define debugg(x...) cerr << "[" << #x << "] = ["; _show_(x); cerr << "]"<< endl;cerr<<endl;
#define star() cerr<<"********************************************"<<endl<<endl;
#else
#define debugg(x...)
#define star()
#endif

void _show_(ll a) {cerr << a;}
void _show_(int a) {cerr << a;}
void _show_(string a) {cerr << '\"' << a << '\"';}
void _show_(char a) {cerr << '\'' << a << '\'';}
void _show_(ld a) {cerr << a;}
void _show_(double a) {cerr << a;}
void _show_(ull a) {cerr << a;}
void _show_(bool a) {cerr << (a ? "true" : "false");}


template <class T, class W> void _show_(pair <T, W> p);
template <class T> void _show_(vector <T> v);
template <class T> void _show_(set <T> v);
template <class T, class W> void _show_(map <T, W> v);
template <class T> void _show_(multiset <T> v);
template <class T, class W> void _show_(pair <T, W> p) {cerr << "{"; _show_(p.ff); cerr << ","; _show_(p.ss); cerr << " }";}
template <class T> void _show_(vector <T> v) {cerr << "[" ; for (T x : v) {_show_(x); cerr << " ";} cerr << "]";}
template <class T> void _show_(vector <vector<T>> v) {cerr << nli << "{" << endl ; for (vector<T> x : v) {_show_(x); cerr << " " << endl;} cerr << "}" << endl;}
template <class T> void _show_(set <T> v) {cerr << "["; for (T x : v) {_show_(x); cerr << " " ;} cerr << "]";}
template <class T> void _show_(multiset <T> v) {cerr << "["; for (T x : v) {_show_(x); cerr << " ";} cerr << "]";}
template <class T, class W> void _show_(map <T, W> v) {cerr << "["; for (auto x : v) {_show_(x); cerr << " ";} cerr << "]";}
template <class T, class W> void _show_(unordered_map <T, W> v) {cerr << "["; for (auto x : v) {_show_(x); cerr << " ";} cerr << "]";}
template <typename T, typename... V> void _show_(T t, V... v) {cerr << " "; _show_(t); if (sizeof...(v)) cerr << " " << ", "; _show_(v...);}

/*------------------+++++---------------+++++----------------+++++-----------------+++++------------------+++++----------------*/

//Algorithms library STL
//count(first_iterator, last_iterator,x) ???> To count the occurrences of x in vector.
//find(first_iterator, last_iterator, x) ??? Returns an iterator to the first occurence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector.
//binary_search(first_iterator, last_iterator, x) ??? Tests whether x exists in sorted vector or not.

//Sort the array to make sure that lower_bound() and upper_bound() work.
//lower_bound(first_iterator, last_iterator, x) ??? returns an iterator pointing to the first element in the range [first,last) which has a value not less than ???x???.
//upper_bound(first_iterator, last_iterator, x) ??? returns an iterator pointing to the first element in the range [first,last) which has a value greater than ???x???.

/*------------------+++++---------------+++++----------------+++++-----------------+++++------------------+++++----------------*/
//functions
//making prime vector and prime character array
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vector<bool> csieve(int n) {  vector<bool> is_prime(n + 1, true); is_prime[0] = is_prime[1] = false; for (int i = 2; i <= n; i++) { if (is_prime[i] && (long long)i * i <= n) { for (int j = i * i; j <= n; j += i) {is_prime[j] = false;} }  } return is_prime;}

ll sumdigits(string &s) {ll  x = s.length() - 1; ll sum = 0; while (x >= 0) {ll d = s[x] - '0'; sum += (d); x--;} return sum;}
template<typename T> T gcd(T a, T b) {return (b ? __gcd(a, b) : a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
int logab(int a, int b)
{
  return (a > b - 1)
         ? 1 + logab(a / b, b)
         : 0;
}
/*------------------+++++---------------+++++----------------+++++-----------------+++++------------------+++++----------------*/




//solution

void helper() {
  ll t = 1;
  cin >> t;
  for (ll tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";

    ll n, m;
    cin >> n >> m;
    vl v(n);
    infor(v);
    ll sum = accumulate(ali(v), 0LL);

    if (m < sum) {
      ans(sum - m);
    }
    else {
      ans(0);
    }












    star();
  }

}















int main()
{
#ifndef ONLINE_JUDGE
  freopen("gadbad.txt", "w", stderr);
#endif
  flashio();
  high_resolution_clock::time_point timme1 = high_resolution_clock::now();

  helper();

  high_resolution_clock::time_point timme2 = high_resolution_clock::now();
  duration<double> timme_span = duration_cast<duration<double>>(timme2 - timme1);

#ifndef ONLINE_JUDGE
  cerr << "IT took me: " << timme_span.count() << " seconds." << endl;
#endif

  return 0;
}

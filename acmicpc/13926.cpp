#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

long long f(long long x, long long c, long long mod) {
    return ((__int128_t)x * x % mod + c) % mod;
}

long long rho(long long n, long long x0 = 2, long long c = 1) {
    long long x = x0;
    long long y = x0;
    long long g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(abs(x - y), n);
    }
    return g;
}
vector<long long> factors;

void factorize(long long n) {
    if (n == 1) return;
    if (primality_test(n)) {
        factors.push_back(n);
        return;
    }
    
    long long x, y, c, g = n;
    
    auto f = [=](long long x) {
        return ((__int128_t)x * x % n + c) % n;
    }
    do {
        if (g == n) {
            x = y = rand() % (n - 2);
            c = rand() % 10 + 1;
            g = 1;
        }
        x = f(x);
        y = f(f(y));
        g = gcd(abs(x - y), n);
    } while (g == 1);
    factorize(g);
    factorize(n / g);
}

void solve(int tc){
	lld n;
	cin >> n;
	factorize(n);
	factors.erase(unique(all(factors)),factors.end());
	lld ans = n;
	for(int e=0;e<sz(factors);e++){
		ans /= factors[e];
		ans *= (factors[e]-1);
	}
	printf("%lld",ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
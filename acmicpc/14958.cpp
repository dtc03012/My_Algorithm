#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <complex>
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

const double PI = acos(-1); // PI 값을 지정해 놓음
typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w){
    int n = f.size();
    if(n == 1) return;
    vector<cpx> even(n/2), odd(n/2);
    for(int i = 0; i < n; ++i)
        (i%2 ? odd : even)[i/2] = f[i];
    FFT(even, w*w);
    FFT(odd, w*w);
    cpx wp(1, 0);
    for(int i = 0; i < n/2; ++i){
        f[i] = even[i] + wp*odd[i];
        f[i + n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}
 
vector<cpx> multiply(vector<cpx> a, vector<cpx> b){
    int n = 1;
    while(n < a.size()+1 || n < b.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<cpx> c(n); 
    cpx w(cos(2*PI/n), sin(2*PI/n));
    FFT(a, w);
    FFT(b, w);
    for(int i = 0; i < n; ++i)
        c[i] = a[i]*b[i];
    FFT(c, cpx(1, 0)/w);
    for(int i = 0; i < n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

const int MAX = 301010;
string A,B;
int ans[MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	cin >> A >> B;
	{
		vector<cpx> v1,v2;
		for(int e=0;e<n;e++){
			if(A[e]=='S') v1.push_back(cpx(1,0));
			else v1.push_back(cpx(0,0));
		}
		for(int e=m-1;e>=0;e--){
			if(B[e]=='R') v2.push_back(cpx(1,0));
			else v2.push_back(cpx(0,0));
		}
		for(int e=m;e<n;e++) v2.push_back(cpx(0,0));
		vector<cpx> k = multiply(v1,v2);
		vector<int> v3;
		for(int p=m-1;p<sz(k);p++) v3.push_back((int)k[p].real());
		for(int e=0;e<sz(v3);e++) ans[e] += v3[e];
	}
	{
		vector<cpx> v1,v2;
		for(int e=0;e<n;e++){
			if(A[e]=='P') v1.push_back(cpx(1,0));
			else v1.push_back(cpx(0,0));
		}
		for(int e=m-1;e>=0;e--){
			if(B[e]=='S') v2.push_back(cpx(1,0));
			else v2.push_back(cpx(0,0));
		}
		for(int e=m;e<n;e++) v2.push_back(cpx(0,0));
		vector<cpx> k = multiply(v1,v2);
		vector<int> v3;
		for(int p=m-1;p<sz(k);p++) v3.push_back((int)k[p].real());
		for(int e=0;e<sz(v3);e++) ans[e] += v3[e];
	}
	{
		vector<cpx> v1,v2;
		for(int e=0;e<n;e++){
			if(A[e]=='R') v1.push_back(cpx(1,0));
			else v1.push_back(cpx(0,0));
		}
		for(int e=m-1;e>=0;e--){
			if(B[e]=='P') v2.push_back(cpx(1,0));
			else v2.push_back(cpx(0,0));
		}
		for(int e=m;e<n;e++) v2.push_back(cpx(0,0));
		vector<cpx> k = multiply(v1,v2);
		vector<int> v3;
		for(int p=m-1;p<sz(k);p++) v3.push_back((int)k[p].real());
		for(int e=0;e<sz(v3);e++) ans[e] += v3[e];
	}
	int mx = 0;
	for(int e=0;e<MAX;e++) mx = max(mx,ans[e]);
	printf("%d",mx);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
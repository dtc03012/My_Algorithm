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


void solve(int tc){
	lld n,d,h;
	cin >> n >> d >> h;
	lld f1 = 0,f2 = 1;
	for(int e=0;e<n;e++){
		lld da,ha;
		cin >> da >> ha;
		lld k1 = ha*(d+da) - da*(h+ha);
		lld k2 = d - da;
		lld k3 = __gcd(k1,k2);
		if(k1<=0) continue;
		k1 /= k3;
		k2 /= k3;
		if(f1*k2<k1*f2){
			f1 = k1;
			f2 = k2;
		}
	}
	printf("%.9Lf\n",(ld)f1/(ld)f2);
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
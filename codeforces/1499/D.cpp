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
lld c,d,x;
const int MAX = 20000010;
int have[MAX];
lld getans(lld k){
	k += d;
	if(k%c) return 0;
	k /= c;
	return (1ll<<have[k]);
}
void solve(int tc){
	scanf("%lld%lld%lld",&c,&d,&x);
	lld ans = 0;
	for(lld p=1;p*p<=x;p++){
		if(x%p==0){
			lld f1 = p;
			lld f2 = (x/p);
			ans += getans(f1);
			if(f1!=f2) ans += getans(f2);
		}
	}
	printf("%lld\n",ans);
}


int main(void){
	for(int e=2;e<MAX;e++){
		if(have[e]==0) for(int q=e;q<MAX;q+=e) have[q]++;
	}
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
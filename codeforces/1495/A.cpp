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
	int n;
	scanf("%d",&n);
	vector<lld> v1,v2;
	for(int e=0;e<2*n;e++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x) v1.push_back(abs(x));
		if(y) v2.push_back(abs(y));
	}
	sort(all(v1));
	sort(all(v2));
	double tot = 0;
	for(int e=0;e<n;e++) tot += sqrt(v1[e]*v1[e]+v2[e]*v2[e]);
	printf("%.9lf\n",tot);
}


int main(void){
	
	// ios_base :: sync_with_stdio(false);
	// cin.tie(NUL/L);
	// cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
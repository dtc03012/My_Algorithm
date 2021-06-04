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

const int MAX = 55;
const int MID = 55;
char arr1[MAX][MAX];
char arr2[MAX][MAX];
int dp[MAX*3][MAX*3];
int n1,m1,n2,m2;
int ly,ry,lx,rx;
pair<bool,int> can(int y,int x){
	int llx = lx,rrx = rx,lly= ly,rry = ry;
	if(y+n2>MAX*3||x+m2>MAX*3) return mk(false,0);
	for(int e=y;e<y+n2;e++){
		for(int p=x;p<x+m2;p++){
			if(dp[e][p]&&arr2[e-y][p-x]=='1') return mk(false,0);
			if(arr2[e-y][p-x]=='1'){
				llx = min(llx,p);
				rrx = max(rrx,p);
				lly = min(lly,e);
				rry = max(rry,e);
			}
		}
	}
	return mk(true,(rrx-llx+1)*(rry-lly+1));
}
void transform(){
	char arr3[MAX][MAX];
	for(int e=0;e<n2;e++){
		for(int p=0;p<m2;p++){
			arr3[m2-p-1][e] = arr2[e][p];
		}
	}
	swap(n2,m2);
	for(int e=0;e<n2;e++){
		for(int p=0;p<m2;p++){
			arr2[e][p] = arr3[e][p];
		}
	}
}
void init(){
	ly = 1e9;
	ry = -1e9;
	lx = 1e9;
	rx = -1e9;
	for(int e=0;e<n1;e++){
		for(int p=0;p<m1;p++){
			dp[e+MID][p+MID] = arr1[e][p] - '0';
			if(arr1[e][p]=='1'){
				lx = min(lx,p+MID);
				rx = max(rx,p+MID);
				ly = min(ly,e+MID);
				ry = max(ry,e+MID);
			}
		}
	}
}
void solve(int tc){
	cin >> n1 >> m1;
	for(int e=0;e<n1;e++) scanf("%s",arr1[e]);
	cin >> n2 >> m2;
	for(int e=0;e<n2;e++) scanf("%s",arr2[e]);
	init();
	int ans = 1e9;
	for(int e=0;e<MAX*3;e++){
		for(int p=0;p<MAX*3;p++){
			for(int q=0;q<4;q++){
				pair<bool,int> xx = can(e,p);
				if(xx.x) ans = min(ans,xx.y);
				transform();
			}
		}
	}
	printf("%d\n",ans);
}


int main(void){
	
	// ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
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
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	int ans = x;
	if(n%2==0){
		int rx = m - 1 - x;
		if(rx%2){
			int xx = rx + 1;
			if(xx<=n) ans = max(ans,m-1);
			else ans = max(ans,x+rx);
		}else{
			int xx = rx;
			if(xx<=n) ans = max(ans,m-1);
			else ans = max(ans,x+rx);
		}
	}else{
		int rx = m - x;
		if(rx%2){
			int xx = rx + 1;
			if(xx<=n-1) ans = max(ans,m-1);
			else ans = max(ans,x+rx);
		}else{
			int xx = rx;
			if(xx<=n-1) ans = max(ans,m-1);
			else ans = max(ans,x+rx);
		}
	}
	printf("%d\n",ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
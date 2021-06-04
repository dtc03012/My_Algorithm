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

const int MAX = 505050;
struct pos{
	int x,y,z;
	bool operator<(const inf& O){
		return x < O.x;
	}
};
struct inf{
	int y,k;
	lld f1,f2;
	bool operator<(const inf& O){
		if(y!=O.y) return y < O.y;
		if(k!=O.k) return k < O.k;
		return f1 < O.f1;
	}
};
int start = 1;
lld tot[MAX];
pos arr[MAX];
void solve(int tc){
	while(start<MAX) start *= 2;
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) {
		int x,y;
		scanf("%d%d",&x,&y);
		arr[e] = mk(x,y,e+1);
	}
	sort(arr,arr+n);
	{
		set<inf> s;
		lld f1 = 0,f2 = 0;
		for(int e=n-1;e>=0;e--){
			tot[arr[e].z] = f1 - f2*arr[e].x;
			set<pl>::iterator it = s.lower_bound({arr[e].y,arr[e].x-arr[e].y,-1e18,-1e18});
			for()
		}
	}
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
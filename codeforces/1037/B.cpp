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

const int MAX = 202020;
int arr[MAX];

void solve(int tc){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int e=0;e<n;e++) scanf("%d",&arr[e]);
	sort(arr,arr+n);
	int mid = (n/2);
	if(arr[mid]>s){
		lld ans = 0;
		for(int p=mid;p>=0;p--){
			if(arr[p]>s) ans += (arr[p]-s);
		}
		printf("%lld\n",ans);
	}else{
		lld ans = 0;
		for(int p=mid;p<n;p++){
			if(s>arr[p]) ans += (s-arr[p]);
		}
		printf("%lld\n",ans);
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
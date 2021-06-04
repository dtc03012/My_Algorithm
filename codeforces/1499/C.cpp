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

const int MAX = 101010;
lld arr[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		scanf("%lld",&arr[e]);
	}
	lld totans = 1e18;
	{
		lld totx = 0,toty = 0,mx = 1e18,my = 1e18;
		for(int e=0;e<n;e+=2){
			if(e+1==n) break;
			totx += arr[e];
			toty += arr[e+1];
			mx = min(mx,arr[e]);
			my = min(my,arr[e+1]);
			lld f1 = totx + mx*(n-(e/2)-1);
			lld f2 = toty + my*(n-(e/2)-1);
			totans = min(totans,f1+f2);
		}
	}
	{
		lld totx = arr[0],toty = 0,mx = arr[0],my = 1e18;
		for(int e=1;e<n;e+=2){
			if(e+1==n) break;
			toty += arr[e];
			totx += arr[e+1];
			mx = min(mx,arr[e+1]);
			my = min(my,arr[e]);
			lld f1 = totx + mx*(n-((e+1)/2)-1);
			lld f2 = toty + my*(n-((e-1)/2)-1);
			totans = min(totans,f1+f2);
		}
	}
	printf("%lld\n",totans);
}


int main(void){
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
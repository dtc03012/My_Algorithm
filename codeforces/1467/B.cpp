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
const int MAX = 303030;	
int arr[MAX],ck[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		ck[e] = 0;
		scanf("%d",&arr[e]);
	}
	if(n==1||n==2){
		printf("0\n");
		return;
	}
	int xx = 0;
	for(int e=1;e<n-1;e++){
		if(arr[e]>arr[e-1]&&arr[e]>arr[e+1]){
			xx++;
			ck[e] = 1;
		}
		if(arr[e]<arr[e-1]&&arr[e]<arr[e+1]){
			xx++;
			ck[e] = -1;
		}
	}
	bool suc1 = false,suc3 = false,suc2 = false;
	for(int e=1;e<n-1;e++){
		// lx
		int mx = 0;
		{
			int xx = 0;
			if(ck[e]) xx = 1;
			if(ck[e-1]) xx++;
			bool suc = true;
			if(e+1!=n-1){
				if(arr[e+1]>arr[e-1]&&arr[e+1]>arr[e+2]) suc = false;
				if(arr[e+1]<arr[e-1]&&arr[e+1]<arr[e+2]) suc = false;
			}
			if(suc){
				if(ck[e+1]) xx++;
			}else{
				if(ck[e+1]==0) xx--;
			}
			mx = max(mx,xx);
		}
		{
			int xx = 0;
			if(ck[e]) xx = 1;
			if(ck[e+1]) xx++;
			bool suc = true;
			if(e-1!=0){
				if(arr[e-1]>arr[e+1]&&arr[e-1]>arr[e-2]) suc = false;
				if(arr[e-1]<arr[e+1]&&arr[e-1]<arr[e-2]) suc = false;
			}
			if(suc){
				if(ck[e-1]) xx++;
			}else{
				if(ck[e-1]==0) xx--;
			}
			mx = max(mx,xx);
		}
		if(mx==1) suc1 = true;
		if(mx==2) suc2 = true;
		if(mx==3) suc3 = true;
	}
	if(suc3) xx -= 3;
	else if(suc2) xx -= 2;
	else if(suc1) xx -= 1;
	printf("%d\n",xx);
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
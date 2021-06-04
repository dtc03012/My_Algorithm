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
int arr[MAX],L[MAX],R[MAX];

void solve(int tc){
	int n;
	scanf("%d",&n);
	lld tot = 0;
	arr[0] = arr[n+1] = 0;
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	L[0] = 0;
	for(int e=1;e<=n;e++){
		if(L[e-1]==-1) L[e] = -1;
		else{
			L[e] = arr[e] - L[e-1];
			if(L[e]<0) L[e] = -1;
		}
	}
	R[n+1] = 0;
	for(int e=n;e>=1;e--){
		if(R[e+1]==-1) R[e] = -1;
		else{
			R[e] = arr[e] - R[e+1];
			if(R[e]<0) R[e] = -1;
		}
	}
	if(L[n]==0) printf("YES\n");
	else{
		for(int e=1;e<n;e++){
			if(L[e-1]==-1||R[e+2]==-1) continue;
			if(arr[e+1]-L[e-1]<0||arr[e]-R[e+2]<0) continue;
			printf("%d\n%d : %d - %d : %d\n",e,L[e-1],arr[e],arr[e+1],R[e+2]);
			if(L[e-1]+arr[e]==R[e+2]+arr[e+1]){
				printf("YES\n");
				return;
			}
		}
		printf("NO\n");
	}
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
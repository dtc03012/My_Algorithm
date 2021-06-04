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

int arr[14];
void solve(int tc){
	int x;
	scanf("%d",&x);
	for(int e=1;e<=14;e++) scanf("%d",&arr[e]);
	int f1 = 0,x1=0,k1 = x;
	for(int e=1;e<14;e++){
		x1 += (k1/arr[e]);
		k1 %= arr[e];
	}
	f1 += x1*arr[14] + k1;
	int f2 = 0,x2=0,k2=x;
	for(int e=4;e<14;e++){
		if(arr[e-1]>arr[e-2]&&arr[e-2]>arr[e-3]){
			k2 += (x2*arr[e]);
			x2 = 0;
		}
		if(arr[e-1]<arr[e-2]&&arr[e-2]<arr[e-3]){
			x2 += (k2/arr[e]);
			k2 %= arr[e];
		}
	}
	f2 += k2 + x2*arr[14];
	if(f1>f2) printf("BNP");
	else if(f1<f2) printf("TIMING");
	else printf("SAMESAME");
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
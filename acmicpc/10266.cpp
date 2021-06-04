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
int arr1[MAX],arr2[MAX],fail[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%d",&arr1[e]);
	for(int e=0;e<n;e++) scanf("%d",&arr2[e]);
	sort(arr1,arr1+n);
	sort(arr2,arr2+n);
	vector<int> v1,v2;
	for(int p=0;p<n-1;p++) v1.push_back(arr1[p+1]-arr1[p]);
	v1.push_back(360000-arr1[n-1]+arr1[0]);
	for(int p=0;p<n-1;p++) v2.push_back(arr2[p+1]-arr2[p]);
	v2.push_back(360000-arr2[n-1]+arr2[0]);
	for(int p=0;p<n;p++) v2.push_back(v2[p]);
	memset(fail,-1,sizeof(fail));
	int j = -1;
	for(int p=1;p<sz(v1);p++){
		while(v1[j+1]!=v1[p]&&j!=-1) j = fail[j];
		if(v1[j+1]==v1[p]) fail[p] = ++j;
	}
	bool suc = false;
	j = -1;
	for(int p=0;p<sz(v2);p++){
		while(v2[p]!=v1[j+1]&&j!=-1) j = fail[j];
		if(v2[p]==v1[j+1]){
			j++;
			if(j==sz(v1)-1){
				suc = true;
				break;
			} 
		}
	}
	if(suc) printf("possible");
	else printf("impossible");
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
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

const int MAX = 1010;
pi arr[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	vector<int> v1,v2;
	for(int e=0;e<n;e++){
		scanf("%d%d",&arr[e].x,&arr[e].y);
		v1.push_back(arr[e].x);
		v2.push_back(arr[e].y);
	}
	sort(all(v1));
	sort(all(v2));
	lld tot1 = 1;
	if(sz(v1)%2==0){
		int k2 = v1[sz(v1)/2];
		int k1 = v1[(sz(v1)/2)-1];
		tot1 = (k2-k1+1);
	}
	lld tot2 = 1;
	if(sz(v2)%2==0){
		int k2 = v2[sz(v2)/2];
		int k1 = v2[(sz(v2)/2)-1];
		tot2 = (k2-k1+1);
	}
	printf("%lld\n",tot1*tot2);
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
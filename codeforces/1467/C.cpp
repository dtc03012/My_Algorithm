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
lld arr1[MAX],arr2[MAX],arr3[MAX];
void solve(int tc){
	int n1,n2,n3;
	scanf("%d%d%d",&n1,&n2,&n3);
	lld f1=0,f2=0,f3=0,ans = 0,s1=2e9,s2=2e9,s3=2e9;
	for(int e=0;e<n1;e++){
		scanf("%lld",&arr1[e]);
		f1 += arr1[e];
		s1 = min(s1,arr1[e]);
	}
	for(int e=0;e<n2;e++){
		scanf("%lld",&arr2[e]);
		f2 += arr2[e];
		s2 = min(s2,arr2[e]);
	}
	for(int e=0;e<n3;e++){
		scanf("%lld",&arr3[e]);
		f3 += arr3[e];
		s3 = min(s3,arr3[e]);
	}
	ans = f1+f2+f3-2*min({f1,f2,f3});
	ans = max(ans,f1+f2+f3-2*min({s1+s2,s1+s3,s2+s3}));
	printf("%lld\n",ans);
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
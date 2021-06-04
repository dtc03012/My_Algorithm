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
int A[MAX],B[MAX],v[MAX][2];
void solve(int tc){
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	for(int e=0;e<=a;e++) v[e][0] = 0;
	for(int e=0;e<=b;e++) v[e][1] = 0;
	for(int e=0;e<k;e++){
		scanf("%d",&A[e]);
		v[A[e]][0]++;
	}
	for(int e=0;e<k;e++){
		scanf("%d",&B[e]);
		v[B[e]][1]++;
	}
	lld ans = 0;
	for(int e=0;e<k;e++){
		int tot = k - v[A[e]][0] - v[B[e]][1] + 1;
		ans += tot;
	}
	printf("%lld\n",ans/2);
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
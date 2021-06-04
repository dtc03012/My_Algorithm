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
const int NMAX = 2505050;
pi arr[MAX];
pair<int,pi> where[NMAX];
void solve(int tc){
	for(int e=0;e<NMAX;e++){
		where[e] = mk(-1,mk(-1,-1));
	}
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e].x);
		arr[e].y = e;
	}
	sort(arr+1,arr+n+1);
	for(int e=2;e<=n;e++){
		for(int p=e-1;p>=1;p--){
			int diff =  arr[e].x - arr[p].x;
			if(where[diff].x<p&&where[diff].x!=-1){
				printf("YES\n");
				printf("%d %d %d %d\n",arr[e].y,where[diff].y.x,arr[p].y,where[diff].y.y);
				return;
			}
			if(where[diff].x==-1){
				where[diff] = mk(e,mk(arr[p].y,arr[e].y));
			}
		}
	}
	printf("NO\n");
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
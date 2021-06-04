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

const int MAX = 50505;
struct inf{
	int y,ty,z;
};
vector<int> v[MAX][20];
int arr[MAX],ans[MAX][20];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e]);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		char s[2];
		int a,b,c;
		scanf("%s%d%d%d",s,&a,&b,&c);
		int ty = 0;
		if(s[0]=='|') ty = 1;
		v[b].push_back({a,ty,c});
	}
	for(int e=0;e<5;e++){
		
	}
	printf("1\n");
	for(int e=1;e<=n;e++) printf("%d ",ans[e]);
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
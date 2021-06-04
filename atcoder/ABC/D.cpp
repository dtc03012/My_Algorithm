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
set<int> s;
map<int,int> mm;
int num = 1;
lld org[MAX*2];
pair<pi,int> arr[MAX];
lld dp[MAX*2];
vector<lld> k1[MAX*2],k2[MAX*2];
void solve(int tc){
	int n;
	lld C;
	scanf("%d%lld",&n,&C);
	for(int e=0;e<n;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		s.insert(a);
		s.insert(b);
		arr[e] = mk(mk(a,b),c);
	}
	for(auto k : s){
		mm[k] = num;
		org[num] = k;
		num++;
	}
	for(int e=0;e<n;e++){
		arr[e].x.x = mm[arr[e].x.x];
		arr[e].x.y = mm[arr[e].x.y];
		k1[arr[e].x.x].push_back(arr[e].y);
		k2[arr[e].x.y].push_back(arr[e].y);
	}
	lld ans = 0,tot = 0;
	for(int e=1;e<num;e++){
		if(e>1){
			lld ntot = min(tot,C);
			ans += ntot*(org[e]-org[e-1]-1);
		}
		for(int p=0;p<sz(k1[e]);p++){
			tot += k1[e][p];
		}
		ans += min(tot,C);
		for(int p=0;p<sz(k2[e]);p++){
			tot -= k2[e][p];
		}
	}
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
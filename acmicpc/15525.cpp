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

const int MAX =  101010;
const lld mod = 1e9 + 7;

char S[MAX];
lld ans[MAX],cnt[MAX*2],sz[MAX*2];
int num = 1;
int dp[MAX*2][26];
int fail[MAX*2],vfail[MAX*2];
void add(string& a){
	int st = 0;
	for(int e=0;e<sz(a);e++){
		int x = a[e] - 'a';
		if(!dp[st][x]){
			dp[st][x] = num;
			sz[num] = e + 1;
			num++;
		}
		st = dp[st][x];
	}
	cnt[st]++;
}
void make_fail(){
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int e=0;e<26;e++){
			if(!dp[x][e]) continue;
			int nx = dp[x][e];
			if(x==0) fail[nx] = 0;
			else{
				int fx = fail[x];
				while(fx&&!dp[fx][e]) fx = fail[fx];
				if(dp[fx][e]){
					fail[nx] = dp[fx][e];
					if(cnt[dp[fx][e]]) vfail[nx] = dp[fx][e];
					else vfail[nx] = vfail[dp[fx][e]];
				}
			}
			q.push(nx);
		}
	}
}
void make_dp(char* S,int len){
	ans[0] = 1;
	int st = 0,cur = 0;
	for(int e=1;e<=len;e++){
		int nx = S[e] - 'a';
		while(cur&&!dp[cur][nx]) cur = fail[cur];
		if(dp[cur][nx]) cur = dp[cur][nx];
		int ncur = cur;
		while(ncur){
			ans[e] = (ans[e] + ans[e-sz[ncur]]*cnt[ncur])%mod;
			ncur = vfail[ncur];
		}
	}
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		string a;	
		cin >> a;
		add(a);
	}
	make_fail();
	cin >> (S+1);
	int len = strlen(S+1);
	make_dp(S,len);
	printf("%lld\n",ans[len]);
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
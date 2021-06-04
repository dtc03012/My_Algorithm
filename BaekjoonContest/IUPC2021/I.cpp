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

const int MAX = 505;
pair<pi,int> len[MAX];
int go[MAX][MAX];
string arr[MAX];
map<string,int> mm;
vector<int> v[3605];
int g(char x){
	return x - '0';
}
int g2(string b){
	int x1 = (g(b[0])*10+g(b[1]))*60+(g(b[3])*10+g(b[4]));
	return x1;
}
bool tmr(pair<pi,int> x,pair<pi,int> y){
	if(x.x.x!=y.x.x) return x.x.x < y.x.x;
	return arr[x.y] < arr[y.y];
}
int dp[3610][502];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=1;e<=n;e++){
		string b,c;
		cin >> arr[e] >> b >> c;
		mm[arr[e]] = e;
		int x1 = g2(b);
		int x2 = g2(c);
		for(int p=x1;p<=x2;p++){
			 v[p].push_back(e);
		}
		cout << x1 << " " <<x2 << endl;
	}
	memset(go,-1,sizeof(go));
	for(int e=0;e<=n;e++){
		go[e][e] = 0;
		go[e][0] = 0;
		go[0][e] = 0;
	}
	for(int e=0;e<m;e++){
		string a,b,c;
		cin >> a >> b >> c;
		go[mm[a]][mm[b]] = g2(c);
		go[mm[b]][mm[a]] = g2(c);
	}
	int mx = 0;
	for(int e=0;e<=3600;e++){
		for(int p=0;p<=n;p++){
			if(e) dp[e][p] = dp[e-1][p];
		}
		for(int p=0;p<sz(v[e]);p++){
			int xx = v[e][p];
			printf("%d : %d\n",e,xx);
			for(int q=0;q<=n;q++){
				if(go[xx][q]==-1) continue;
				dp[e][xx] = max(dp[e][xx],dp[max(0,e-go[xx][q])][q] + 1);
				mx = max(mx,dp[e][xx]);
			}
		}
	}
	printf("%d\n",mx);
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
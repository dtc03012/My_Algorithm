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
map<int,char> mm[MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	int cnt1 = 0,cnt2 = 0;
	for(int e=0;e<m;e++){
		char type[2];
		scanf("%s",type);
		if(type[0]=='+'){
			int u,v;
			char c[2];
			scanf("%d%d%s",&u,&v,c);
			if(mm[v].count(u)){
				if(mm[v][u]==c[0]) cnt1++;
				else if(mm[v][u]!='?') cnt2++;
			}
			mm[u][v] = c[0];
		}else if(type[0]=='-'){
			int u,v;
			scanf("%d%d",&u,&v);
			if(mm[v].count(u)){
				if(mm[v][u]==mm[u][v]) cnt1--;
				else if(mm[v][u]!='?')cnt2--;
			}
			mm[u][v] = '?';
		}else{
			int x;
			scanf("%d",&x);
			if(cnt1) printf("YES\n");
			else if(cnt2){
				if(x%2) printf("YES\n");
				else printf("NO\n");
			}else printf("NO\n");
		}
	}
	printf()
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
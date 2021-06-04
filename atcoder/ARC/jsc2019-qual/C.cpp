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

const lld mod = 1e9 + 7;
const int MAX = 202020;
char S[MAX];
void solve(int tc){
	int n;
	scanf("%d%s",&n,S);
	lld xx = 1;
	for(int e=1;e<=n;e++) xx = (xx*e)%mod;
	n *= 2;
	if(S[0]=='W'||S[n-1]=='W'){
		printf("0");
		return;
	}
	lld cnt = 1;
	for(int e=0;e<n;){
		if(e<n-1&&S[e]==S[e+1]){
			e+=2;
		}else if(S[e]=='B'){
			int tot = 0;
			if(e<n-1){
				e++;
				for(;e<n;e++){
					if(S[e]=='W') tot++;
					else break;
				}
				e++;
				if(tot>1) cnt = (cnt*2)%mod;
			}
		}else if(S[e]=='W'){
			cnt = 0;
			break;
		}
	}
	cnt = (cnt*xx)%mod;
	printf("%lld\n",cnt);
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
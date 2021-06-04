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

int cnt1[10],cnt2[10],ten[10],cnt3[10];
void solve(int tc){
	ten[0] = 1;
	for(int e=1;e<6;e++) ten[e] = ten[e-1] * 10;
	int k;
	scanf("%d",&k);
	string a,b;
	cin >> a >> b;
	for(int e=0;e<4;e++){
		cnt1[a[e]-'0']++;
		cnt2[b[e]-'0']++;
		cnt3[a[e]-'0']++;
		cnt3[b[e]-'0']++;
	}
	int tot = 0,rtot = 0;;
	for(int e=1;e<=9;e++){
		for(int p=e;p<=9;p++){
			cnt3[e]++;
			cnt3[p]++;
			if(cnt3[e]<=k&&cnt3[p]<=k){
				printf("%d : %d\n",e,p);
				rtot++;
				cnt1[e]++;
				cnt2[p]++;
				int f1 = 0,f2 = 0;
				for(int q=1;q<=9;q++){
					f1 += q*ten[cnt1[q]];
					f2 += q*ten[cnt2[q]];
				}
				if(f1>f2) tot++;
				cnt1[e]--;
				cnt2[p]--;
			}
			cnt3[e]--;
			cnt3[p]--;
		}
	}
	printf("%.9lf\n",(double)(tot)/(double)rtot);
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
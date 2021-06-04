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

vector<string> v;
vector<string> kk[9];
void f(int x){
	if(sz(kk[x])) return;
	f(x-1);
	for(int e=0;e<sz(kk[x-1]);e++){
		string a = kk[x-1][e] + kk[x-1][e];
		string b = kk[x-1][e];
		for(int p=0;p<sz(kk[x-1][e]);p++){
			if(kk[x-1][e][p]=='A') b += "B";
			else b += "A";
		}
		kk[x].push_back(a);
		kk[x].push_back(b);
	}
	int lim = (1<<(x-1));
	string a = "";
	for(int e=0;e<lim;e++) a += "A";
	for(int e=0;e<lim;e++) a += "B";
	kk[x].push_back(a);
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	kk[1].push_back("AB");
	f(n);
	printf("%d\n",sz(kk[n]));
	for(int e=0;e<sz(kk[n]);e++) cout << kk[n][e] << "\n";
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
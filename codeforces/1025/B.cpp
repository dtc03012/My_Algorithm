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

void solve(int tc){
	int n;
	scanf("%d",&n);
	int a,b;
	scanf("%d%d",&a,&b);
	vector<int> v1,v2;
	int alim = sqrt(a);
	for(int e=2;e<=alim;e++){
		if(a%e==0){
			v1.push_back(e);
			while(a%e==0){
				a/=e;
			}
		}
	}
	if(a!=1) v1.push_back(a);
	int blim = sqrt(b);
	for(int e=2;e<=blim;e++){
		if(b%e==0){
			v2.push_back(e);
			while(b%e==0){
				b/=e;
			}
		}
	}
	if(b!=1) v2.push_back(b);
	for(int e=1;e<n;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		vector<int> s1,s2;
		for(int e=0;e<sz(v1);e++){
			if(a%v1[e]==0||b%v1[e]==0) s1.push_back(v1[e]);
		}
		for(int e=0;e<sz(v2);e++){
			if(a%v2[e]==0||b%v2[e]==0) s2.push_back(v2[e]);
		}
		v1 = s1;
		v2 = s2;
	}
	if(sz(v1)==0&&sz(v2)==0){
		printf("-1\n");
	}else if(sz(v1)){
		printf("%d\n",v1[0]);
	}else{
		printf("%d\n",v2[0]);
	}
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
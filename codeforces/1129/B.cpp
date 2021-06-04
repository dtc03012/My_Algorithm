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


int MAX = 1000000;
void solve(int tc){
	int k;
	scanf("%d",&k);
	vector<int> v;
	while(true){
		for(int e=2;e<=2000;e++){
			if((e-1)*MAX>=k&&(k+MAX)%e==0){
				int tot = MAX - (k+MAX)/e;
				if((e-1)>=tot) continue;
				for(int p=0;p<e-2;p++) v.push_back(-1);
				v.push_back(-(tot-(e-2)));     
				v.push_back(MAX);
				printf("%d\n",sz(v));
				for(int e=0;e<sz(v);e++) printf("%d ",v[e]);
				1return;
			}
		}
		MAX--;
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
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

const int MAX = 1505;
vector<vector<pi> > arr1,arr2,arr3;
vector<int> v;
int comprow = -1;
bool comp(vector<pi>& a,vector<pi>& b){
	if(a[comprow].x!=b[comprow].x) return a[comprow].x < b[comprow].x;
	return a[comprow].y < b[comprow].y;
}
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	arr1 = vector<vector<pi> >(n,vector<pi>(m));
	arr2 = vector<vector<pi> >(n,vector<pi>(m));
	arr3 = vector<vector<pi> >(n,vector<pi>(m));
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			scanf("%d",&arr1[e][p].x);
			arr1[e][p].y = e;
		}
	}
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			 scanf("%d",&arr2[e][p].x);
			 arr2[e][p].y = e;
		}
	}
	for(int p=0;p<m;p++){
		bool can = true;
		for(int e=1;e<n;e++) if(arr2[e][p].x<arr2[e-1][p].x) can = false;
		if(can) v.push_back(p);
	}
	if(sz(v)==0){
		for(int e=0;e<n;e++){
			for(int p=0;p<m;p++){
				if(arr1[e][p].x!=arr2[e][p].x){
					printf("-1");
					return;
				}
			}
		}
		printf("0");
	}else{
		for(int q=0;q<min(10,sz(v));q++){
			for(int e=0;e<n;e++) for(int p=0;p<m;p++) arr3[e][p] = arr1[e][p];
			comprow = v[q];
			sort(all(arr3),comp);
			bool suc = true;
			for(int e=0;e<n;e++){
				for(int p=0;p<m;p++){
					if(arr3[e][p].x!=arr2[e][p].x) suc = false;
				}
			}
			if(suc){
				printf("1\n%d\n",v[q]+1);
				return;
			}else{
				if(m==1){
					printf("-1");
					return;
				}
				int wh = -1;
				for(int p=0;p<m;p++) if(p!=v[q]) wh = p;
				comprow = wh;
				sort(all(arr1),comp);
				for(int e=0;e<n;e++){
					for(int p=0;p<m;p++) arr1[e][p].y = e;
				}
				comprow = v[q];
				sort(all(arr1),comp);
				bool suc = true;
				for(int e=0;e<n;e++){
					for(int p=0;p<m;p++){
						if(arr1[e][p].x!=arr2[e][p].x) suc = false;
					}
				}
				if(suc){
					printf("2\n%d %d\n",wh+1,v[q]+1);
					return;
				}
			}
		}
		printf("-1");
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
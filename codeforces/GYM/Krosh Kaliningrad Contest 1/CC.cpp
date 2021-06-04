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
 
const int MAX = 101010;
int arr[MAX],ans[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%d",&arr[e]);
	sort(arr,arr+n);
	int st = 0;
	for(int p=0;p<n;p+=2) ans[p] = arr[st++];
	for(int p=1;p<n;p+=2) ans[p] = arr[st++];
	bool suc = false;
	for(int p=1;p<n;p+=2){
		if(ans[p]<=ans[p-1]||ans[p]<=ans[p+1]) suc= true;
	}
	if(suc){
		if(n==2){
			printf("-1");
			return;
		}
		vector<int> v;
		int mid = (n/2);
		for(int p=0;p<n-1;p++) if(p!=mid) v.push_back(arr[p]);
		ans[0] = arr[mid];
		ans[1] = arr[n-1];
		int st = 0;
		for(int p=2;p<n;p+=2) ans[p] = v[st++];
		for(int p=3;p<n;p+=2) ans[p] = v[st++];
		bool suc = false;
		for(int p=1;p<n;p+=2){
			if(ans[p]<=ans[p-1]||ans[p]<=ans[p+1]) suc= true;
		}
		if(suc){
			int mid = n/2,last = n-1;
	int st = 0;
	while((n/2)!=last){
		ans[st++] = arr[mid--];
		ans[st++] = arr[last--];
	}
	if(n%2) ans[st] = arr[0];
	else{
		ans[st++] = arr[0];
		ans[st++] = arr[1];
	}
	bool suc = false;
	for(int p=1;p<n;p+=2){
		if(ans[p]<=ans[p-1]||ans[p]<=ans[p+1]) suc = true;
	}
	if(suc) printf("-1");
	else{
		for(int p=0;p<n;p++) printf("%d ",ans[p]);
	}
		}
		else{
			for(int p=0;p<n;p++) printf("%d ",ans[p]);
		}
	}
	else{
		for(int p=0;p<n;p++) printf("%d ",ans[p]);
	}
}
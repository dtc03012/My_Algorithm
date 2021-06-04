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


const int MAX = 10101;
const int NMAX = 103;
const int INF = 1000000000;
pi arr1[NMAX],arr2[NMAX];
vector<int> v[NMAX],gv[NMAX];
int have[NMAX];
struct Hopcroft_Karp{
    int N, A[MAX], B[MAX], dist[MAX];
    bool used[MAX]; 
    vector<int> adj[MAX];

    Hopcroft_Karp(){
    }
    void init(int N){
		this->N = N;
		memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        memset(used,0,sizeof(used));
        for(int e=0;e<MAX;e++) adj[e].clear();
    }
    void add_edge(int x,int y){
        adj[x].push_back(y);
    }
    void bfs(){
        queue<int> Q;
        for(int i=1; i<=N; i++){
            if(!used[i]){
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        while(!Q.empty()){
            int a = Q.front();
            Q.pop();
            for(int b: adj[a]){
                if(B[b] != -1 && dist[B[b]] == INF){
                    dist[B[b]] = dist[a] + 1;
                    Q.push(B[b]);
                }
            }
        }
    }
    bool dfs(int a){
        for(int b: adj[a]){
            if(B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b])){
                used[a] = true;
                A[a] = b;
                B[b] = a;
                return true;
            }
        }
        return false;
    }
    int flow(){
        int match = 0;
        while(1){
            bfs();
            int flow = 0;
            for(int i=1; i<=N; i++)
                if(!used[i] && dfs(i)) flow++;
            if(flow == 0) break;
            match += flow;
        }
        return match;
    }
};
int n,m,c,k;
Hopcroft_Karp gh;
bool can(lld x){
	gh.init(n);
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			lld vv = (arr1[e].x-arr2[p].x)*(arr1[e].x-arr2[p].x);
			vv += (arr1[e].y-arr2[p].y)*(arr1[e].y-arr2[p].y);
			if(vv>x) continue;
			for(int q=0;q<sz(v[p]);q++){
				int nx = v[p][q];
				for(int p=1;p<=c;p++){
					int v1 = c*(nx-1) + p;
					gh.add_edge(e,v1);
				}
			}
		}
	}
	if(gh.flow()==n) return true;
	return false;
}
void print_ans(lld x){
	gh.init(n);
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			lld vv = (arr1[e].x-arr2[p].x)*(arr1[e].x-arr2[p].x);
			vv += (arr1[e].y-arr2[p].y)*(arr1[e].y-arr2[p].y);
			if(vv>x) continue;
			for(int q=0;q<sz(v[p]);q++){
				int nx = v[p][q];
				for(int p=1;p<=c;p++){
					int v1 = c*(nx-1) + p;
					gh.add_edge(e,v1);
				}
			}
		}
	}
	gh.flow();
	cout << x << "\n";
	for(int e=1;e<=n;e++){
		int nx = (gh.A[e]-1)/c + 1;
		for(int r=0;r<sz(gv[nx]);r++){
			int p = gv[nx][r];
			lld vv = (arr1[e].x-arr2[p].x)*(arr1[e].x-arr2[p].x);
			vv += (arr1[e].y-arr2[p].y)*(arr1[e].y-arr2[p].y);
			if(vv<=x){
				cout << p << "\n";
				break;
			}
		}
	}
}
void solve(int tc){
	cin >> n >> m >> c >> k;
	for(int e=1;e<=n;e++){
		cin >> arr1[e].x >> arr1[e].y;
	}
	for(int e=1;e<=m;e++){
		cin >> arr2[e].x >> arr2[e].y;
	}
	for(int e=1;e<=k;e++){
		cin >> have[e];
		for(int p=0;p<have[e];p++){
			int r;
			cin >> r;
			v[r].push_back(e);
			gv[e].push_back(r);
		}
	}
	lld ll = 0,rr = 1e12,mid,ans = 1e12;
	while(ll<=rr){
		mid = (ll+rr)/2;
		if(can(mid)){
			ans = min(ans,mid);
			rr = mid - 1;
		}else{
			ll = mid + 1;
		}
	}
	if(ans==1e12){
		cout << "-1";
		return;
	}
	print_ans(ans);
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}
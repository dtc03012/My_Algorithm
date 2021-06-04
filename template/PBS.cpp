for(int e=0;e<q;e++) hi[e] = m;
	for(int e=0;e<q;e++) lo[e] = 1;
	while(true){
		int flag = false;
		for(int e=0;e<=m+1;e++) v[e].clear();
		for(int e=0;e<q;e++){
			if(lo[e]>hi[e]) continue;
			flag = true;
			v[(lo[e]+hi[e])/2].push_back(e);
		}
		if(!flag) break;
		for(int e=1;e<=n;e++){
			vis[e] = e;
			sz[e] = 1; 
		}
		for(int e=0;e<m;e++){
			int w = arr[e].w,x = arr[e].x,y = arr[e].y;
			x = find(x);
			y = find(y);
			if(x!=y){
				vis[y] = x;
				sz[x] += sz[y];
				sz[y] = 0;
			}
			for(int q=0;q<v[e+1].size();q++){
				int now = v[e+1][q];
				int ll = que[now][0],rr = que[now][1];
				ll = find(ll);
				rr = find(rr);
				if(ll==rr){
					hi[now] = e;
					ans[now][0] = w;
					ans[now][1] = sz[ll];
				}else lo[now] = e+2;
			}
		}
	}
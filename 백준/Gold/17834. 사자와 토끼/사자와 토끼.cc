#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> edge[50005];
int color[50005];
bool ch = false;
int num_1;
void dfs(int start, int c){
	color[start] = c;
	if(c==1) num_1++;
	for(int i : edge[start]){
		if(!color[i]){
			dfs(i,c%2+1);
			if(ch) return;
		}
		else if(color[i]==c){
			ch = true;
			return;
		}
	}
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i = 0;i<m;i++){
		int x,y; scanf("%d %d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1,1);
	if(ch) printf("%d",0);
	else{
		printf("%lld",(long long)num_1*(long long)(n-num_1)*2);
	}
	return 0;
}
#include <stdio.h>
#include <queue>
#define MAX 200001

int check[MAX], dist[MAX];
int subin, sister;
int result;
std::queue<int> q;
int main()
{
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &subin, &sister);
	
	check[subin]= 1;
	q.push(subin);
	while( !q.empty() ){
		int now= q.front();
		q.pop();
		if (now== sister)
			break;
		
		if( now> 0 ){
			if( !check[now-1] ){
				check[now-1]= 1;
				dist[now-1]= dist[now]+1;
				q.push(now-1);
			}
		}
		if( now< MAX-1 ){
			if( !check[now+1] ){
				check[now+1]= 1;
				dist[now+1]= dist[now]+1;
				q.push(now+1);
			}
		}
		if( now* 2< MAX ){
			if( !check[now* 2] ){
				check[now* 2]= 1;
				dist[now* 2]= dist[now]+1;
				q.push(now* 2);
			}
		}
	}
	printf("%d", dist[sister]);
	return 0;
}

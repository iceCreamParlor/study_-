#include <stdio.h>
#include <queue>
using namespace std;
int water[3];
queue<int> q;
int main()
{
	freopen("input.txt", "r", stdin);
	for(int i=0; i<3; i++){
		scanf("%d", &water[i]);
	}
	q.push(water[2]);
	while(!q.empty() ){
		
	}
	return 0;
}

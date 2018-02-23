#include <stdio.h>
#include <queue>
#define MAX 10000

int check[MAX], result[MAX];
bool IsSosu[MAX];
std::queue<int> q;
void Init(){
	for(int i=0; i< MAX; i++){
		result[i]= 0;
		check[i]= 0;
	}
}
void initSosu(){
	for(int i=1000; i< MAX; i++){
		short yaksu= 0;
		for( int j=1; j<= i; j++  ){
			if(yaksu>2){
				break;
			}
			if( i%j==0 ){
				yaksu++;
			}
		}
		if(yaksu==2) IsSosu[i]= true;
	}
}
int convert(int num){
	int temp=1; 
	for(int i=1; i< num; i++)
		temp*= 10;
	return temp;
}
int change(int now, int digit, int num){
	int temp= convert(digit); int afterConvert;
	int div= now/ temp %10;
	afterConvert= now- div* temp + num* temp;
	return( afterConvert );
}
int main()
{
	freopen("input.txt", "r", stdin);
	int start, final;
	initSosu();
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++){

		Init(); 

		scanf("%d %d", &start, &final);
		
		q.push(start); check[start]= 1;
		while( !q.empty() ){
			int now= q.front(); q.pop();
			for(int i=1; i<=4; i++){
				for(int j=0; j<= 9; j++){
					int next= change(now, i, j);
					if( !IsSosu[next] ) continue;
					if( !check[next] && next >= 1000 ){
						result[next]= result[now]+1;
						check[next]= 1;
						q.push(next);
					}
				}
			}
		}
		printf("%d\n", result[final] );
	}
	return 0;
}

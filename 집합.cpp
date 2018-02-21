#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	int num, ip, S; char cmd[20];
	scanf("%d", &num);
	for(int i=0 ; i< num ; i++){
			scanf("%s", &cmd);
			if( strcmp(cmd, "empty") && strcmp(cmd, "all") ) scanf("%d", &ip);
			if(!strcmp(cmd, "add"))	S= S | (1<< --ip);
			else if(!strcmp(cmd, "check")){
				if( S & (1<< --ip) ) printf("1\n");
				else printf("0\n");
			}
			else if(!strcmp(cmd, "remove"))	S= S & ~(1<< --ip);
			else if(!strcmp(cmd, "toggle"))	S= S^ (1<< --ip);
			else if(!strcmp(cmd, "all"))	S= (1<<20) -1;
			else if(!strcmp(cmd, "empty"))	S= 0;
			else printf("error");
		}
	return 0;
}

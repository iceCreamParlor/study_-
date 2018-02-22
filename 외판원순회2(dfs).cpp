#include<iostream>
#include<cstdio>
using namespace std;
 
int arr[11][11];  //map.
int check[11];  //���ø� �湮 �ߴ��� check
int n;          //n.
int m = 987654321;  //��ȸ�� �ּ� ���
 
void input(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}
 
void dfs(int start, int y, int sum, int cnt){
    //��� ���ø� �鷶��(cnt==n) && �ٽ� ��ŸƮ ���÷� �� ���(start==y)
    if(cnt == n && start == y){
        if(m > sum) m = sum;
        return;
    }
 
    for(int x=0; x<n; x++){
        if(arr[y][x] == 0) continue;    //���� ���� ���� ���(�ڱ��ڽ�����)
 
        //�湮 ���� �ʰ� y,x�� 0���� ū ���
        if(!check[y] && arr[y][x] >0) {
            check[y] = true;    //�湮 üũ
            sum+=arr[y][x];
 
            if(sum <= m){   //sum�� m ���� ���� ��츸 Ž�� ����
                //[1,2]�̾����� [2,-]�� ������.
                dfs(start, x, sum, cnt+1);
            }
 
            //�湮�� ��ϰ� �� �ʱ�ȭ
            check[y] = false;
            sum-=arr[y][x];
        }
    }
}
 
void solution(){
    for(int y=0; y<n; y++){
        //������ ��(����)���� �����ϴ� ���
        dfs(y, y, 0, 0);
    }
}
 
 
void output(){
    printf("%d", m);
}
 
int main(void){
    input();
    solution();
    output();
    return 0;
}
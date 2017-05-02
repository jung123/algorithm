#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int trees[100001];
int main(int argc, char** argv) {
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int T;
	int test_case;
    int n,tmp,lazer,i,res,j,num,prev;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		n = res = 0;
		memset(trees,0,sizeof(int)*100001);		
		// 여기서 tree의 크기 구함 
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&tmp);
			trees[tmp]++;
		}
		//
		for(i=0;i<n;i++){
			prev = 100000;
			scanf("%d",&lazer);
			j = lazer;
			tmp =1;
			num = 0;
			// 짜르기 
			while(++j <= prev){
				res += tmp++ * trees[j];  
				num += trees[j];
				trees[j] = 0;
			}
			trees[lazer] += num;
			// 1길어지기 
			for(j=lazer;j>=1;j--){
				trees[j+1] = trees[j];
			}
			prev = lazer;
		}
		printf("Case #%d\n", test_case);
		printf("%d\n",res);
	}

	return 0;
}

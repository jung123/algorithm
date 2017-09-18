#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int score[300000];
int score_compare(const void *arg1,const void *arg2);
int main(int argc, char** argv) {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int TC;
	int test_case;
    bool aa;
    int n,i,tmp,high,res;
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
        // 점수를 받는다. 
		cin >> n;
        for(i=0;i<n;i++){
        	scanf("%d\n",score+i);
		}
        // 정렬
		qsort(score,n,sizeof(int),score_compare);
		//
        res = 0;
        tmp = n-1;
        high = score[0];
        while(tmp >= 0){
        	i =0;
        	aa = true;
        	while(i < tmp){
        		if(score[i]+(i+1) > score[tmp] + n){
        			aa = false;
        			break;
				}
				i++;
			}
			if(aa != false){
				res = tmp+1;
				break;
			}
			tmp--;
		}
		//
		printf("Case #%d\n", test_case);	
		printf("%d\n",res);
	}
	return 0;
}
int score_compare(const void *arg1,const void *arg2){
	if(*(int *)arg1 > *(int *)arg2) return -1;
	else if(*(int *)arg1 == *(int *)arg2) return 0;
	else if(*(int *)arg1 < *(int *)arg2) return 1;
}

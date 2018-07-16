#include<stdio.h>
int MaxOfThree(int A,int B,int C){
	if(A>=B && A>=C)	return A;
	if(B>=A && B>=C)	return B;
	if(C>=A && C>=B)	return C;
}
int MaxSubsequeenceSum_4(int A[],int N){
	int i,Sum,MaxSum;
	Sum=0;
	MaxSum=0;
	for(i=0;i<N;i++){
			Sum+=A[i];
			if(Sum>MaxSum)
				MaxSum=Sum;
			else
				if(Sum<0)
					Sum=0;
	}
	return MaxSum;
}
int MaxSubsequeenceSum_3(int A[],int Left, int Right){
	int Mid,i,j,Sum,MaxLeftSum,MaxRightSum,MaxSum,MaxLeftBoardSum,MaxRightBoardSum;
	if(Left==Right)
		if(A[Left]>0)	return A[Left];
			else	return 0;
	Mid=(Left+Right)/2;
	MaxLeftSum=MaxSubsequeenceSum_3(A,Left,Mid);
	MaxRightSum=MaxSubsequeenceSum_3(A,Mid+1,Right);
	MaxLeftBoardSum=0;Sum=0;
	for(i=Mid;i>=0;i--){
		Sum+=A[i];
		if(Sum>MaxLeftBoardSum)	MaxLeftBoardSum=Sum;
	}
	MaxRightBoardSum=0;Sum=0;
	for(i=Mid+1;i<Right;i++){
		Sum+=A[i];
		if(Sum>MaxRightBoardSum) MaxRightBoardSum=Sum;
	}
	return MaxOfThree(MaxLeftSum,MaxRightSum,MaxLeftBoardSum+MaxRightBoardSum);
}
int MaxSubsequeenceSum_2(int A[],int N){
	int Sum,MaxSum,i,j;
	MaxSum=0;
	for(i=0;i<N;i++){
		Sum=0;
		for(j=i;j<N;j++){
			Sum+=A[j];
			if(Sum>MaxSum)
				MaxSum=Sum;
		}
	}
	return MaxSum;
}
int MaxSubsequeenceSum_1(int A[],int N){
	int Sum,MaxSum,i,j,k;
	MaxSum=0;
	for(i=0;i<N;i++)
			for(j=i;j<N;j++){
					Sum=0;
					for(k=i;k<=j;k++)
						Sum+=A[k];
					if(Sum>MaxSum)
						MaxSum=Sum;
			}
	return MaxSum;
}
int main(){
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d" ,&a[i]);
	 printf("%d",MaxSubsequeenceSum_4(a,n));
	return 0;
}

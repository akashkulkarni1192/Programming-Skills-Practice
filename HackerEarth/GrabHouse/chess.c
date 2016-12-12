//	1 2 3 4
//  1 4
//  1


#include <stdio.h>
#include<math.h>
int arr[11];
int mat[11][11];
int main()
{
	int i,j,n,player,p1,p2,k, l;
	scanf("%d",&n);
	player = pow(2,n);
	arr[1]=1;
	for(i=1;i<=player;i++){
		arr[i+1]=i+1;
		for(j=1;j<=player;j++)
			if(i>j)
				scanf("%d",&mat[i][j]);
	}
	// printf("\n\n");
	// for(i=1;i<=player;i++){
	// 	for(j=1;j<=player;j++)
	// 		printf("%d ",mat[i][j]);
	// 	printf("\n");
	// }
	// printf("\n\n");
	// for(i=1;i<=player;i++){
	// 	printf("%d ",arr[i]);
	// }
	k=0;
	l=player/2;
	while(l>=1){
		for(i=1;i<=l-1;i+=2){
			p1=i;
			p2=i+1;
			if(p1<p2){
				if(mat[p1][p2]==1)
					arr[k++]=p1;
				else
					arr[k++]=p2;
			}
			else
				printf("\ncheck trianglar matrix for [%d,%d]",p1,p2);
			// (p1<p2)
			// 	?(mat[p1][p2]==1)
			// 		?arr[k++]=p1
			// 		:arr[k++]=p2
			// 	:printf("\ncheck trianglar matrix for [%d,%d]",p1,p2);

		}
		l/=2;
	}
	printf("%d",arr[1]);
    return 0;
}

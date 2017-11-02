#include<stdio.h>



void bestfit(int n, int np, int block_sizes[10], int process_sizes[10]){
	int temp[10],i,j,tp,frag,b_visited[10]={0},bno,k;
	for(i=0;i<n;i++)
		temp[i]=block_sizes[i];
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(block_sizes[j]<block_sizes[i]){
				tp = block_sizes[i];
				block_sizes[i] = block_sizes[j];
				block_sizes[j] = tp;  

			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",block_sizes[i]);
	for(i=0;i<np;i++){
		// printf("i value is %d\n",i);
		for(j=0;j<n;j++){
		// printf("popopopo\n");

			if(block_sizes[j]>=process_sizes[i]){
				if (b_visited[j]!=1){
					frag = block_sizes[j]-process_sizes[i];
					for(k=0;k<n;k++){
						if(temp[k] == block_sizes[j])
							bno = k;
					}
					printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",i,process_sizes[i],bno,block_sizes[j],frag );

					b_visited[j]=1;
					break;
				}

			}
		}
	}






}

void main(){
int n,i,block_sizes[10],np,process_sizes[10];
printf("Enter number of blocks");
scanf("%d",&n);
printf("Enter the block sizes");
for(i=0;i<n;i++)
scanf("%d",&block_sizes[i]);
printf("Enter number of process");
scanf("%d",&np);
for(i=0;i<np;i++)
scanf("%d",&process_sizes[i]);
bestfit(n,np,block_sizes,process_sizes);


}


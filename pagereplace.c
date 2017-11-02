#include<stdio.h>



void fifo(int n,int p,int a[10]){
	int i,ans[10]={-1},j,flag=1,l,k,rep=0;
	for(i=0;i<n;i++)
		ans[i] = -1;

	
	for(i=0;i<p;i++){
		flag = 1;
		printf("For page %d\n",a[i]);
		for(j=0;j<n;j++){
			if(ans[j] == a[i]){
				for(k=0;k<n;k++){
					printf("%d\t",ans[k]);

				}
				printf("H\n");
				flag = 0;
				break;
			}	

			
		}
		if(flag){
			for (k = 0; k < n; k++)
			{
				if(ans[k] == -1){
					ans[k] = a[i];
					for(l=0;l<n;l++){
						printf("%d\t",ans[l]);

					}
					printf("M\n");
					flag = 0;					
					break;
				}
			}
		}if(flag){
			ans[rep++] = a[i];
			if(rep >= n)
				rep=0;
			for(l=0;l<n;l++){
				printf("%d\t",ans[l]);

			}
			printf("M\n");
			flag = 0;


		}
	}


	

}






void lru(int n,int p,int a[10]){
	int i,ans[10]={-1},j,flag=1,l,k,rep=0,status[10];
	for(i=0;i<n;i++)
		ans[i] = -1;

	
	for(i=0;i<p;i++){
		flag = 1;
		printf("For page %d\n",a[i]);
		for(j=0;j<n;j++){
			if(ans[j] == a[i]){
				for(k=0;k<n;k++){
					printf("%d\t",ans[k]);


				}
				printf("H\n");
				flag = 0;
				status[j]=1;
				break;
			}	

			
		}
		if(flag){
			for (k = 0; k < n; k++)
			{
				if(ans[k] == -1){
					ans[k] = a[i];
					for(l=0;l<n;l++){
						printf("%d\t",ans[l]);

					}
					printf("M\n");
					flag = 0;					
					break;
				}
			}
		}if(flag){
			if(status[rep]==1){
				rep++;
				status[rep]=0;
			}
			if(rep >= n)
				rep=0;
			ans[rep++] = a[i];
			if(rep >= n)
				rep=0;
			for(l=0;l<n;l++){
				printf("%d\t",ans[l]);

			}
			printf("M\n");
			flag = 0;


		}
	}


	

}



void main()
{
	int n,p,i,a[10];	
	printf("Enter frame size");
	scanf("%d",&n);
	printf("Enter the number of pages");
	scanf("%d",&p);
	for(i=0;i<p;i++){
		scanf("%d",&a[i]);
	}
	fifo(n,p,a);
	lru(n,p,a);


}
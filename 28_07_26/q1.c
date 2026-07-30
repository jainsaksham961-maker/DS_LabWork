// Q1) WACP to store n elements in 1D array then count and print total even and odd elements in array
# include <stdio.h>
# define max 50
int main(){
	int odd_count=0,even_count=0,n;
	printf("Enter size of array:");
	scanf("%d",&n);
	int a[max],i;
	for(i=0;i<n;i++){
		printf("Elem %d:",i+1);
		scanf("%d",&a[i]);
		}
	for(i=0;i<n;i++){
		if(a[i]%2==0)
			even_count++;
		else
			odd_count++;
		}
	printf("Number of even elems = %d \n Number of odd elems = %d \n",even_count,odd_count);
	return 0;
}
	
		
	


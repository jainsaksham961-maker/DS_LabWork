/* Q2) WACP to store n elems in 1D array then swap the content of array and finally display the content after swapping. Don't use temporary array.
*/
# include <stdio.h>
# define max 50
int main (){
	int n;
	printf("Enter array size:");
	scanf("%d",&n);
	int a[max],i;
	for(i=0;i<n;i++){
		printf("Elem %d:",i+1);
		scanf("%d",&a[i]);
		}
	for(i=0; i < n/2; i++){
		int temp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = temp;
		}
	printf("Swapped array:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
		}
	printf("\n");		
	return 0;
}				

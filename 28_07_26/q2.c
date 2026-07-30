/* Q2) WACP to store n elems in 1D array (including(+ve,-ve & 0), then seperate and store them in different 
arrays (i.e. +ve, -ve & 0). Don't use temporary array.
*/
# include <stdio.h>
# define max 50
int main (){
	int n;
	printf("Enter array size:");
	scanf("%d",&n);
	int a[max],i;
	int pos[max],neg[max],zero[max];
	int p_c=0,n_c=0,z_c=0;
	for(i=0;i<n;i++){
		printf("Elem %d:",i+1);
		scanf("%d",&a[i]);
		if(a[i]>0)
			pos[p_c++]=a[i];
		else if(a[i]<0)
			neg[n_c++]=a[i];
		else
			zero[z_c++]=a[i];
		}
	for(i=0;i<p_c;i++)
		printf("Positive elems:%d",pos[i]);
	printf("\n");		
	for(i=0;i<n_c;i++)
		printf("Negative elems:%d",neg[i]);
	printf("\n");		
	for(i=0;i<z_c;i++)      
		printf("Zeroes:%d",zero[i]);
	printf("\n");		
	return 0;
}		
		

# include <stdio.h>
#define MAX 100
void rotateArr(int a[],int n, int k){
	int i,j,t;
	k=k%n;
	for(i=0;i<k;i++){
		t=a[n-1];
		for(j=n-1;j>0;j--){
		   a[j]=a[j-1];
		   }
		a[0]=t;
		}
}

int main(){
	int n,a[MAX],i,k;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter array elems:\n");
	for(i=0;i<n;i++){
	scanf("%d",&a[i]);}
	printf("Enter value of 'K' to rotate the arr:");
	scanf("%d",&k);
	rotateArr(a,n,k);
	for(i=0;i<n;i++){
	printf("%d",a[i]);}
	printf("\n");
	return 0;
}

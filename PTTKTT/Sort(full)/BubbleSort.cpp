#include <stdio.h>

typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void Swap(recordtype &x, recordtype &y){
	recordtype temp = x;
	x = y;
	y = temp;
}

void BubbleSort(recordtype a[], int n){
	int i,j;
	for(i=0;i<=n-1;i++){
		for(j=n-1;j>=i+1;j--){  //Xet tu phan tu cuoi cung di qua trai
			if(a[j].key < a[j-1].key){
				Swap(a[j],a[j-1]);
			}
		}
	}
}

int main(){
	int n,i;
	recordtype a[100];
	FILE* file = fopen("dayso.inp","r");
	fscanf(file,"%d",&n);
	
	for(i=0;i<=n-1;i++){
		fscanf(file,"%d",&a[i]);
	}
	
	printf("Day so truoc khi sap xep noi bot (Bubble Sort) : \n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	printf("\n-------------------------------");
	
	BubbleSort(a,n);
	printf("\nDay so sau khi sap xep noi bot (Bubble Sort) : \n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}

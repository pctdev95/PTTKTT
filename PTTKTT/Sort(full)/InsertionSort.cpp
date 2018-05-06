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

void InsertionSort(recordtype a[], int n){
	int i,j;
	for(i=0;i<=n-1;i++){
		j=i;
		while((j>0) && (a[j].key < a[j-1].key)){  //Khi j>0 va gia tri cua a[j] < gia tri cua a[j-1]  (a[j-1] la gia tri cua phan tu dung truoc a[j])
			Swap(a[j],a[j-1]);		//Doi cho gia tri a[j] va a[j-1]
			j--;	//giam j xuong 1 sao cho j < i mot gia tri
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
	
	printf("Day so truoc khi sap xep xen (Insertion Sort) : \n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	printf("\n-------------------------------");
	
	InsertionSort(a,n);
	printf("\nDay so sau khi sap xep xen (Insertion Sort) : \n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	
	
	return 0;
}

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

void SelectionSort(recordtype a[], int n){
	int i,j,lowindex;
	keytype lowkey;
	for(i=0;i<=n-1;i++){
		lowkey = a[i].key;   //gia tri cua phan tu thu i
		lowindex = i;		//vi tri
		
		
		for(j=i+1;j<=n-1;j++){
			if(a[j].key < lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		Swap(a[i],a[lowindex]);
	}
}

int main(){
	int i, n;
	recordtype a[100];
	FILE* file = fopen("dayso.inp","r");
	
	fscanf(file,"%d",&n);    //Nhap vao so phan tu trong mang
	for(i=0;i<=n-1;i++){
		fscanf(file,"%d",&a[i]);
	}
	
	printf("Day trupc khi sap xep theo kieu Selection Sort la : \n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	printf("\n------------------------------------------\n");
	
	SelectionSort(a,n);
	printf("Day sau khi sap xep theo kieu Selection Sort la : \n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

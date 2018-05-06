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

int FindPivot(recordtype a[], int i, int j){
	keytype firstkey;
	int k;
	k = i + 1; //i la chi so dau tien, k la chi so thu 2 sau i
	firstkey = a[i].key;  //Gia tri cua khoa dau tien
	while((k<=j) && (a[k].key == firstkey)) k++;
	if(k>j) return -1;
	if(a[k].key > firstkey) return k;
	return i;
}

int Partition(recordtype a[], int i, int j, keytype pivot){
	int L,R;
	L = i;
	R = j;
	while(L <= R){
		while(a[L].key < pivot) L++;
		while(a[R].key >= pivot) R--;
		if(L<R)	Swap(a[L], a[R]);
	}
	return L; //Tra ve diem phan hoach
}

void QuickSort(recordtype a[], int i, int j){   //i la chi so dau tien, j la chieu dai mang
	keytype pivot;
	int pivotindex, k;
	pivotindex = FindPivot(a,i,j);
	if(pivotindex != -1){
		pivot = a[pivotindex].key;
		k = Partition(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
	}
}

int main(){
	int n,i;
	FILE* file = fopen("dayso.inp","r");
	recordtype a[100];
	fscanf(file,"%d",&n);
	
	for(i=0;i<n;i++){
		fscanf(file,"%d",&a[i]);
	}
	
	printf("Day so truoc khi sap xep nhanh (Quick Sort) : \n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	printf("\n-------------------------------");
	
	QuickSort(a,0,n-1); //Sap xep mang a bat dau voi chi so 0, mang co chieu dai la n-1
	printf("\nDay so sau khi sap xep nhanh (Quick Sort) : \n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}

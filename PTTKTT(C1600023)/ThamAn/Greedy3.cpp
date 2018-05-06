// Bai toan cai ba lo 1
// Moi do vat co so luong khong han che
// Giai bang phuong phap THAM AN
#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct {
	char TenDV[20];
	float TL, GT, SL;
	int PA;
}DoVat;

DoVat * ReadFromFile(float *W, int *n){
	FILE *f;
	f = fopen("CaiBalo3.INP", "r");
	fscanf(f, "%f",W); // Xac dinh trong luong Ba lo
	DoVat *dsdv;
	dsdv=(DoVat*)malloc(sizeof(DoVat));
	int i=0;
	while (!feof(f)){
 		fscanf(f, "%f%f%f", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL);
 		fgets(dsdv[i].TenDV,25,f);
 		dsdv[i].TenDV[strlen(dsdv[i].TenDV)-1]='\0';
 		dsdv[i].PA=0;
 		i++;
 		dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1)); 
	} *n=i;
 	fclose(f);
 	return dsdv;
}

void swap(DoVat *x, DoVat *y){
	DoVat Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}

//Sap xep thu tu giam dan
void BubbleSort(DoVat *dsdv, int n){
	int i,j;
	for(i=0; i<=n-2; i++)
 		for (j=n-1; j>=i+1; j--){
 			float DGJ = dsdv[j].GT/dsdv[j].TL;  // Gia tien do vat[j] = Gia tri[j]  /  Trong luongj[j]
 			float DGJ_1 = dsdv[j-1].GT/dsdv[j-1].TL;	//Gia tien do vat[j - 1] = Gia tri[j - 1]  /  Trong luong[j - 1]
 			if (DGJ>DGJ_1) // Neu Gia tien[j]  > Gia tien[j-1]
				swap(&dsdv[j],&dsdv[j-1]);	//Swap [j] & [j - 1]
 		}
}

//In 
void InDSDV(DoVat *dsdv ,int n, float W){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("|---|--------------------|---------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-20s|%-9s|%-9s|%-9s|%-9s|%-9s|\n", "STT", " Ten Do Vat","T. Luong", "Gia Tri", "Don Gia","S. luong", "P. An");
	printf("|---|--------------------|---------|---------|---------|---------|---------|\n");
	for(i=0;i<n;i++){
		printf("|%-3d",i+1);
		printf("|%-20s",dsdv[i].TenDV);
		printf("|%-9.1f",dsdv[i].TL);
		printf("|%-9.1f",dsdv[i].GT);
		printf("|%-9.1f",dsdv[i].GT/dsdv[i].TL);
		printf("|%-9.1f",dsdv[i].SL);
		printf("|%-9d|\n",dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}
	printf("|---|--------------------|---------|---------|---------|---------|---------|\n");
	printf("Trong luong cua ba lo= %9.1f\n",W);
	printf("Tong trong luong= %9.1f, Tong gia tri= %9.1f\n", TongTL, TongGT);
	printf("Phuong an (" );
	for(i=0; i<n; i++){
		printf(" %d,",dsdv[i].PA);
	}
	printf(")\n");
}

void Greedy(DoVat *dsdv,int n, float W){
	int i;
	for(i = 0; i < n; i++) {
		dsdv[i].PA = (W / dsdv[i].TL);	//Phuong an[i] = Trong luong ba lo  /  Trong luong[i]  
		W = W - dsdv[i].PA * dsdv[i].TL;	//Trong luong con lai cua balo = Trongluong cua ba lo  -  Trong luong cua do vat[i]
 	}
}

void Greedy_SL(DoVat *dsdv,int n, float W){
	int i;
	for(i = 0; i < n; i++) {
		dsdv[i].PA = (W / dsdv[i].TL);	//Phuong an[i] = Trong luong ba lo  /  Trong luong[i]  
		if(dsdv[i].PA > dsdv[i].SL){	//Neu PA > SL
			dsdv[i].PA = dsdv[i].SL;	//PA = SL
			W = W - dsdv[i].SL* dsdv[i].TL;
		}
		else{
			W = W - dsdv[i].PA * dsdv[i].TL;	//Trong luong con lai cua balo = Trongluong cua ba lo  -  Trong luong cua do vat[i]
 		}
	}
}


int main(){
	int n;
	float W;
	
	DoVat *dsdv;				//Tao ra danh sach cac do vat
	dsdv=ReadFromFile(&W, &n);	//Doc du lieu tu file
 	BubbleSort(dsdv,n);			//Sap xep cac do vat theo thu tu giam dan
	Greedy_SL(dsdv,n,W);			//Dung thuat toan tham an de lua chon ra phuong an
	InDSDV(dsdv,n,W);			//In ra danh sach do vat va phuong an lua chon
	free(dsdv);					//Giai phong vung nho
	return 0;
}

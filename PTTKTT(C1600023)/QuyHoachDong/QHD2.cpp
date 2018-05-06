//Bai toan cai ba lo 2
// Moi do vat chi co mot cai
// Du lieu cho trong file D://PT_TKTT/Giao trinh moi/thuc hanh/Balo.INP


#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenDV[20];
	int TL, GT, PA;
}DoVat;

typedef int bang[50][100];// Ba lo co trong luong toi da 99 va co toi da 50 do vat

int min(int a, int b){
	return (a<b)? a:b;
}
DoVat * ReadFromFile(int *W, int *n){
     FILE *f;
     f=fopen("balo1-quyhoachcdong.inp", "r");
     fscanf(f, "%d",W); // Xac dinh trong luong Ba lo
	 DoVat *dsdv;
	 dsdv=(DoVat*)malloc(sizeof(DoVat));
	 int i=0;
 	 while (!feof(f)){
	   fscanf(f, "%d%d",&dsdv[i].TL,&dsdv[i].GT);
	   fgets(dsdv[i].TenDV,20,f);/////Bo dau &
	   dsdv[i].TenDV[strlen(dsdv[i].TenDV)-1]='\0';
	   dsdv[i].PA=0;
	   i++;
	   dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1)); 
	 }
	 *n=i;
     fclose(f);
     return dsdv;
}

void InDSDV(DoVat *dsdv ,int n, int W){
	int i,TongTL=0, TongGT=0;
	printf("|---|--------------------|---------|---------|---------|\n");
	printf("|%-3s|%-20s|%-9s|%-9s|%-9s|\n", "STT", "     Ten Do Vat   ","T. Luong", "Gia Tri", "P. An");
	printf("|---|--------------------|---------|---------|---------|\n");
	for(i=0;i<n;i++){
		printf("|%-3d",i+1);
		printf("|%-20s",dsdv[i].TenDV);
		printf("|%-9d",dsdv[i].TL);
		printf("|%-9d",dsdv[i].GT);
		printf("|%-9d|\n",dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|--------------------|---------|---------|---------|\n");	
	printf("Trong luong cua ba lo= %d\n",W);
	printf("Tong trong luong= %d, Tong gia tri= %d\n", TongTL, TongGT);
}
void TaoBang(DoVat *dsdv,int n,int W, bang F,bang X){
   int xk, yk, k;
   int FMax, XMax, V;

// Dien h?ng dau tien cua hai bang

  for(V= 0; V<=W; V++) {
     X[0][V] = min (V/dsdv[0].TL,1) ;
     F[0][V] = X[0][V] * dsdv[0].GT;
  }

// ?ien c?c d?ng c?n lai

   for(k= 1; k<n; k++)   
     for(V=0; V<=W; V++) {
	  FMax = F[k-1][V] ;
	  XMax = 0;
	  yk = min (V/dsdv[k].TL,1);
	  for(xk = 1; xk<=yk; xk++)
	    if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT>FMax){
	       FMax=F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
	       XMax= xk;
	   }
	  F[k][V] = FMax;
	  X[k][V] = XMax;
    }
  
}

void InBang(int n, int W, bang F, bang X){
	int V, k;
	for(k=0; k<n; k++){
	  for(V=0; V<=W; V++)
	    printf("%4d%2d",F[k][V], X[k][V]);
	   printf("\n"); 
    }
}

void TraBang(DoVat *dsdv, int n, int W, bang X) {
   int k, V;
   V = W;
   for(k= n-1; k>=0; k--) {
      dsdv[k].PA = X[k][V];
      V = V - X[k][V] * dsdv[k].TL;
   }
}


int main(){
	int n, W;
	bang X,F;
	DoVat *dsdv;
	dsdv=ReadFromFile(&W, &n);
	TaoBang(dsdv,n,W,F,X);
	InBang(n,W,F,X);
	TraBang(dsdv,n,W,X);
	InDSDV(dsdv,n,W);
	free(dsdv);
	return 0;
}

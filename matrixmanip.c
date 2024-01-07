#include <stdio.h>
#include <stdlib.h>


void unos_m(int** a, int n)
{
     int i,j;
     for(i=0;i<n;i++){
	  *(a+i)=(int*)malloc(n*sizeof(int));
	  for(j=0;j<n;j++)
	       scanf("%d",&a[i][j]);
     }
}

void ispis_m(int** a, int n, int m)
{
     int i,j;
     printf("Ispis matrice:\n");
     for(i=0;i<n;i++){
	  for(j=0;j<m;j++)
	       printf("%4d",a[i][j]);
	  printf("\n");
     }
}

int max_m(int** a, int n)
{
     int i,j,max=a[0][0];
     for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	       if(a[i][j]>max)
		    max=a[i][j];
     return max;
}

int provera_polja(int** a, int** b, int n, int m)
{
     int i, j, maxa, maxb;
   
     maxa= max_m(a, n);
     maxb= max_m(b, m);
   
     for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	       if(a[i][j]==maxa){
		    if(b[i][j]==maxb)
			 return 1;
		    else
			 return 0;  
	       }
}

void zamena_sa_nulom(int** a, int n){
     int i,j, i1, maxa;
   
     maxa= max_m(a, n);
   
     for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	       if(a[i][j]==maxa)
		    for(i1=0;i1<n;i1++){
			 a[i][i1] = 0;
			 a[i1][j] = 0;
		    }
}

void brisanje(int** a, int n){
     int i, j, maxa, **mat, i1, j1;     
   
     maxa= max_m(a, n);
     
     for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	       if(a[i][j]==maxa){
		    i1=i+1;
		    j1=j+1;		
	       }

     mat=(int**)malloc(i1*sizeof(int*));
     for(i=0;i<i1;i++)
     {
	  *(mat+i)=(int*)malloc(j1*sizeof(int));
	  for(j=0;j<j1;j++)
	       mat[i][j]=a[i][j];
     }
     
     ispis_m(mat,i1,j1);
}
 
int main(){
     int dim1, dim2, **mat1,**mat2;
   
     printf("Unesite dimenziju prve matrice: ");
     scanf("%d",&dim1);
     mat1=(int**)malloc(dim1*sizeof(int*));
     printf("Unesite prvu matricu:\n");
     unos_m(mat1, dim1);
   
     printf("Unesite dimenziju druge matrice: ");
     scanf("%d",&dim2);
     mat2=(int**)malloc(dim2*sizeof(int*));
     printf("Unesite drugu matricu:\n");
     unos_m(mat2, dim2);
   
     ispis_m(mat1, dim1, dim1);
     ispis_m(mat2, dim2, dim2);
   
     if(provera_polja(mat1,mat2,dim1,dim2)==1)
     {
	  printf("\n\t\tIzmenjene matrice:\n");
	  zamena_sa_nulom(mat1, dim1);
	  zamena_sa_nulom(mat2, dim2);
	  ispis_m(mat1, dim1, dim1);
	  ispis_m(mat2, dim2, dim2);
     }
     else
     {
	  printf("\n\t\tIzmenjene matrice:\n");
	  brisanje(mat1,dim1);
	  brisanje(mat2,dim2);
     }
}

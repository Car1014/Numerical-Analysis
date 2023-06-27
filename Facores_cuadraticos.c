#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    int n;
    double q=0,p=0;
    double raiz1,raiz2;
    printf("Ingresa el grado de tu polinomio\n");
    scanf("%d",&n);
    double a[n+1];
    for (int i=0;i<n+1;i++){
        printf("Ingresa el valor de a[%d]\n",i);
        scanf("%lf",&a[i]);
    }
    double b[n-1],R,S;
    //int aux=0;
    int conta=0;
    while(n>2){


            for(int k=0;k<n-1;k++){
                if(k==0){
                    b[k]=a[k];
                     //printf("_____%.5lf\n",b[k]);
                    continue;
                }
                if(k==1){
                    b[k]=a[k]-(p*b[k-1]);

                     //printf("_____%.5lf --- b[%.5lf]\n",b[k],b[k-1]);
                    continue;
                }

                b[k]=a[k]-(p*b[k-1])-(q*b[k-2]);
            }

            if(conta>0 && fabs(R-(a[n-1]-(p*b[n-2])-(q*b[n-3])))<0.001 && fabs(S-(a[n]-(q*b[n-2])))<0.001 ){

                printf("x^2 %lfx %lf\n",p,q);
                printf("\nLas raices son: \n");
                    if((pow(p,2)-4*(1)*(q))<0){

                        printf("(%f + %fi) /2\n",-p,sqrt((pow(p,2)-4*(1)*(q))*(-1)));
                        printf("(%f - %fi)/2\n",-p,sqrt((pow(p,2)-4*(1)*(q))*(-1)));
                    }else{
                        raiz1=(-p+sqrt((pow(p,2)-4*(1)*(q))))/2;
                        raiz2=(-p-sqrt((pow(p,2)-4*(1)*(q))))/2;
                        printf("%f\n",raiz1);
                        printf("%f\n",raiz2);
                    }

                printf("\n");
                for (int i=0;i<n-1;i++){
                    printf("x^%d %.4lf  ",n-i-2,b[i]);
                }
                printf("\n");
                R=S=0;
                printf("%d ",n);
                n=n-2;
                printf("%d- ",n);
                printf("-------------\n");
                if(n<=2){
                    raiz1=-b[1]/b[0];
                    printf("%f",raiz1);
                    break;
                }

                for(int k=0;k<=n;k++){
                    a[k]=b[k];
                }
            }
            R=a[n-1]-(p*b[n-2])-(q*b[n-3]);
            S=a[n]-(q*b[n-2]);
            //printf("R_____%.5lf\n",R);
            //printf("S_____%.5lf\n\n",S);

            p=(R/b[n-2])+p;
            q=(S/b[n-2])+q;
            //printf("b[n-2]_____%f\n",b[n-2]);
            //printf("p=_____%.5lf\n",p);
            //printf("q=_____%.5lf\n", q );
            conta++;
    }

    return 0;
}













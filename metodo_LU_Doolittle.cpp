//Doolittle
#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cout<<"Dame el tamaño de la matriz cuadrada"<<endl;
    cin>>n;
    float a[n][n+1];
    for (int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){

            cin>>a[i][j];
        }
    }
    ////Se muestra la matriz ingresada
    cout<<endl;
    cout<<"La matriz ingresada es: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    //Matris U y L
    float u[n][n];
    float l[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            u[i][j]=l[i][j]=0;
            if(i==j){
                l[i][j]=1;
            }
        }
    }
    ////////////////////////////////
    cout<<endl;
    cout<<"Matriz inicializada U: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Matriz inicializada L: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }
    //////////////////////////////


    //Primer renglon de U

    for(int j=0;j<n;j++){
        u[0][j]=a[0][j];
    }

    //Primer columna de l;

    for(int i=0;i<n;i++){
        l[i][0]=(a[i][0]/u[0][0]);
    }

    for (int i=1;i<n-1;i++){

        //Renglones 2<=i<=n-1 de u
        for(int j=i;j<n;j++){
            float auxU=0;
            for(int k=0;k<=i-1;k++){
                auxU=auxU+(l[i][k]*u[k][j]);
            }
            u[i][j]=a[i][j]-auxU;
        }

    //Columnas 2<=j<=n-1 de L

       for(int j=i+1;j<n;j++){
            float suma=0;
            for(int k=0;k<i+1;k++){
                suma+=l[j][k]*u[k][i];
            }
            l[j][i]=(a[j][i]-suma)/u[i][i];
       }


    }
    cout<<endl;
    cout<<"Matriz L: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }
    //ultimo renglon de U

    float aux1=0;
    for(int k=0;k<n-1;k++){
        aux1+=(l[n-1][k]*u[k][n-1]);

        //cout<<"----"<<l[n-1][k]<<" "<<u[k][n-1];
    }
    u[n-1][n-1]=a[n-1][n-1]-aux1;

    cout<<endl;
    cout<<"Matriz U: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }
    //Calculo de d con sustitucion hacia adelante

    float d[n];

    for(int i=0;i<n;i++){
        d[i]=a[i][n];
        for(int k=0;k<i;k++){
            d[i]-=l[i][k]*d[k];
            //cout<<"---- ";
        }
        //cout<<"++++++"<<d[i]<<endl;
    }

    //Calculo de x con sustitucion hacia atras


    float x[n];

    for(int i=n-1;i>=0;i--){

        float suma2=0;

        for(int k=i+1;k<n;k++){
            suma2+=(u[i][k]*x[k]);
        }
        x[i]=(d[i]-suma2)/u[i][i];

    }
    cout<<endl;
    cout<<"Resultados: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"x"<<i<<" "<<x[i]<<endl;
    }


}






























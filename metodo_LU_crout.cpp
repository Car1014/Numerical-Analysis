//Crout
#include<bits/stdc++.h>
using namespace std;

int main(){

     int n;
    cout<<"Dame el tamanio de la matriz cuadrada"<<endl;
    cin>>n;
    float a[n][n+1];
    for (int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            cin>>a[i][j];
        }
    }
    ////Se muestra la matriz ingresada
    cout<<endl;
    cout<<"Matriz ingresada:\n"<<endl;
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
                u[i][j]=1;
            }
        }
    }
    ////////////////////////////////
    cout<<endl;
    cout<<"Matriz inicializada U: \n"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Matriz inicializada L: \n"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }



    //Primera columna de L:

    for(int i=0;i<n;i++)l[i][0]=a[i][0];

    //Primer renglon de U:

    for(int j=0;j<n;j++)u[0][j]=a[0][j]/l[0][0];


    for(int j=1;j<n-1;j++){

        //columnas 2<=j<=n-1 de l

        for(int i=j;i<n;i++){

            l[i][j]=a[i][j];
            for(int k=0;k<j;k++){
                l[i][j]-=(l[i][k]*u[k][j]);
            }

        }

        //Renglones 2<=i<=n-1 de u

        for(int i=j+1;i<n;i++){
            float suma=0;
            for(int k=0;k<i;k++){
                suma+=(l[j][k]*u[k][i]);
            }
            u[j][i]=(a[j][i]-suma)/l[j][j];
        }


    }


    //ultima columna de L;

    l[n-1][n-1]=a[n-1][n-1];

    for(int k=0;k<n-1;k++){

        l[n-1][n-1]-=(l[n-1][k]*u[k][n-1]);

    }



    //////////////////////////////////////////////////
    cout<<endl;
    cout<<"Matriz U: \n"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Matriz L: \n"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }
    //////////////////////////////////////////////////


    float d[n];

    for(int i=0;i<n;i++){

        d[i]=a[i][n];

        for(int k=0;k<i;k++){

            d[i]-=(l[i][k]*d[k]);

        }
        d[i]/=l[i][i];
    }

    float x[n];

    for(int i=n-1;i>=0;i--){

        x[i]=d[i];
        for(int k=i+1;k<n;k++){
            x[i]-=(u[i][k]*x[k]);
        }

    }

    cout<<endl;
    cout<<"Valores de X: \n "<<endl;
    for(int i=0;i<n;i++){
        cout<<"x"<<i<<" "<<x[i]<<endl;
    }




    return 0;
}










import math

def funcion(x):
    #Modify function
    return x**2

x=float(input("Enter value: "))
count=0
while(True):
    count=count+1
    
    x=funcion(x)
    if(count>=3 and abs(x-funcion(x))>abs(x-control) ):
        print("The function does not converge")
        break

    if(abs(x-funcion(x))<.0001):
        print("The root is: ",x)
        break
    if(count==2):
        control=x
    

 







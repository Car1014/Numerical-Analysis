import math

def funtion(x):
    #funtion 
    #fx=2*math.cos(x)-math.exp(x)
    #first derivative
    #fxdx=-2*math.sin(x)-math.exp(x)
    fx=(x**3)+(x**2)-x
    fxdx=3*(x**2)-(2*x)-1
    return x-(fx/fxdx)


x=float(input("Enter the initial value: "))
count=0
while(True):
    count=count+1

    if(abs(x-funtion(x))<0.0001):
        print("The root is: ",x)
        break
    x=funtion(x)





    





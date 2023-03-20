
import math
#transcendental functions
#mayh.expo(x)
#math.sin(x)
#math.cos(x)
#math.tan(x)

def  polinomio(x):
    ##put the function that you want to evaluate
    return math.cos(x)-(x**2)+6
#Value input
xl=float(input("Number xl right side :"))
xu=float(input("Number xu left side: "))
fxl=polinomio(xl)
fxu=polinomio(xu)

while(fxl*fxu>0):
    print("The given values do not contain a root please try again")
    xl=float(input("Number xl right side :"))
    xu=float(input("Number xu left side: "))
    fxl=polinomio(xl)
    fxu=polinomio(xu)

conta=0
while(True):
    
    fxl=polinomio(xl)
    fxu=polinomio(xu)

    xr=xu-((fxu)*(xl-xu)/(fxl-fxu))

    if(conta>1 and abs(fxr-polinomio(xr))<.0001):
        break;
    print("fxl ",fxl)
    print("fxu ",fxu)

    fxr=polinomio(xr)

    if(fxr*fxl<0):
        xu=xr
    if(fxr*fxl>0):
        xl=xr
    conta=conta+1    
        
print("The root is: ",xr)



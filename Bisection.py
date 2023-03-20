import math
#transcendental functions
#mayh.expo(x)
#math.sin(x)
#math.cos(x)
#math.tan(x)

def  funcion(x):
    #put the function that you want to evaluate
    return math.cos(x)-(x**2)+6
##Values input
lr=float(input("Enter the number on the left side of the root "))
ll=float(input("Enter the number on the right side of the root "))

flr=funcion(lr)
fll=funcion(lr)

if flr*fll>0:
    print("THE GIVEN VALUES DO NOT CONTAIN A ROOT PLEASE TRY AGAIN ")
    
conta=0
while(True):
    
    if conta!=0:
        xra=xr
    xr=(lr+ll)/2
   
    fxr=funcion(xr)
    flr=funcion(lr)
    fll=funcion(ll)
  
    print("xr ",xr)
   
    if flr*fxr<0:
        ll=xr
    if flr*fxr>0:
        lr=xr
    if conta!=0: 
        if abs(xra-xr)<0.0001:
            break
    conta=conta+1
    
print("The root is " ,xr)




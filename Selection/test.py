import numpy as np
import matplotlib.pyplot as plt
#Assembly tray after
x1=[
-0.00007,
-0.000598,
-0.000212,
0.000067,
0.000815,
]
y1=[
-0.003311,
-0.0005,
-0.000561,
-0.000957,
0.005327,
]
x2=[
-0.001057,
-0.000576,
-0.001261,
-0.000411,
0.003305,
]
y2=[
-0.00276,
-0.0009,
-0.001051,
-0.000625,
0.005334,
]
x3=[
-0.000189,
0.000461,
-0.000876,
-0.000154,
0.000756,
]
y3=[
-0.002414,
0.000375,
0.000046,
0.000905,
0.001089,
]
x4=[
-0.000697,
-0.000466,
-0.001217,
-0.001081,
0.003462,
]
y4=[
-0.002472,
0.00038,
-0.000196,
0.001052,
0.001234,
]
plt.title("Assembly tray after TL") 
plt.xlim(xmax=max(x1)+0.001,xmin=min(x1)-0.001)
plt.ylim(ymax=max(y1)+0.001,ymin=min(y1)-0.001)
plt.xlabel("dx(mm)")
plt.ylabel("dy(mm)")
plt.plot(x1,
         y1,'ro')
plt.show()

# plt.savefig(r'gantry.png', dpi=300)
plt.title("Assembly tray after BL") 
plt.xlim(xmax=max(x2)+0.001,xmin=min(x2)-0.001)
plt.ylim(ymax=max(y2)+0.001,ymin=min(y2)-0.001)
plt.xlabel("dx(mm)")
plt.ylabel("dy(mm)")
plt.plot(x2,
         y2,'ro')
plt.show()

plt.title("Assembly tray after TR") 
plt.xlim(xmax=max(x3)+0.001,xmin=min(x3)-0.001)
plt.ylim(ymax=max(y3)+0.001,ymin=min(y3)-0.001)
plt.xlabel("dx(mm)")
plt.ylabel("dy(mm)")
plt.plot(x3,
         y3,'ro')
plt.show()


plt.title("Assembly tray after BR") 

plt.xlim(xmax=max(x4)+0.001,xmin=min(x4)-0.001)
plt.ylim(ymax=max(y4)+0.001,ymin=min(y4)-0.001)
plt.xlabel("dx(mm)")
plt.ylabel("dy(mm)")
plt.plot(x4,
         y4,'ro')
plt.show()
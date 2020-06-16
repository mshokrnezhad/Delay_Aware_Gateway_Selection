import matplotlib.pyplot as plt 
  
f = open("fx.txt", 'r')
n = f.readlines()
n = [int(i) for i in n]

f = open("fz.txt", 'r')
r = f.readlines()
r = [int(j) for j in r]

f = open("xs.txt", 'r')
xs = f.readlines()
xs = [int(k) for k in xs]

f = open("ys.txt", 'r')
ys = f.readlines()
ys = [int(g) for g in ys]

len_n = len(n)
len_r = len(r)

plt.scatter(xs, ys, label= "router", color= "blue", marker= "*", s=10)

plt.scatter(xs[r[0]-1], ys[r[0]-1], label= "gateway", color= "red", marker= "*", s=100)
for i in range(0, len_r):
  plt.scatter(xs[r[i]-1], ys[r[i]-1], color= "red", marker= "*", s=100)

for i in range(0, len_n):
  plt.plot([xs[i], xs[n[i]-1]], [ys[i], ys[n[i]-1]], linestyle=':', color= "green")

# x-axis label 
plt.xlabel('x - axis') 
# frequency label 
plt.ylabel('y - axis') 
# plot title 
plt.title('Under-Water Router Network with Gateways') 
# showing legend 
plt.legend() 
  
# function to show the plot 
plt.show() 


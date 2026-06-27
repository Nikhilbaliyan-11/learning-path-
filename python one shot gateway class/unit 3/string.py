s = input("enter string:")
s = s[::-1]
print(s)
i = 0
k = True
while (k):
    if s == "n":
       k = False 
    print(s[i],"  ")
    i = i+1
    
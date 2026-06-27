# # table printing using for loop

# s =input("enter a number :")
# n = int(s)

# for i in range(1,11):
#     print(n,"X",i,"=",n*i)


# program for factorial

# s = input("enter a number:")
# n = int(s)
# m=1
# for i in range(1,n+1):
    
#     m=m*i
# print(m)
    
# break in loops and program of prime numbers
# s= input("enter a number :")
# n = int(s)
# isprime=True
# for i in range(2,n):
#     if(n%i==0):
#         print("not a prime number.")
#         isture = False
#         break
# if isprime == True:
#     print("prime number")
    

# vowels 

# s=input("enter a string :")

# for i in s:
#     if i not in ["a","i","o","u","e","A","E","I","O","U"]:
#         continue

#     print(i)

# while True:
#     s = input("enter password")
#     if(s== "secret"):
#         break
#     else:
#         print("invalid password", end=" ")
#         print("try again!")

# pallindrome

# s =  int(input("enter the number "))
# k = s
# sum = 0
# while(s>0):
#     r = s % 10
#     sum = sum*10 + r
#     s = s//10
# if(sum==k):
#     print("pallindrome")
    
# else:
#     print(" not pallindrome")
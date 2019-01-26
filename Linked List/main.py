#imports
import createSparse
import multi



print("enter no of rows and columns of 1st matrix")
r1 = int(input())
c1 = int(input())

print("enter the array:")
a = [[int(input()) for j in range(c1)] for i in range(r1)]

print("printing the array:")
for row in a:
    print(' '.join(str(elem) for elem in row))

sA = createSparse.create(a)


print("enter no of rows and columns of 2st matrix")
r2 = int(input())
c2 = int(input())

print("enter the array:")
b = [[int(input()) for j in range(c2)] for i in range(r2)]

print("printing the array:")
for row in b:
    print(' '.join(str(elem) for elem in row))


sB = createSparse.create(b)

mul = multi.multi(sA, sB)


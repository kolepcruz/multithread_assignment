from random import randint


def clean_edges(m):
    height, width = len(m), len(m[0])
    for y in range(height):
        m[y][0] = 0
        m[y][width-1] = 0
    for x in range(width):    
        m[0][x] = 0
        m[height-1][x] = 0
    return m

def iterate_center(a,b,c):
    b_radius = len(b)//2
    a_height, a_width = len(a), len(a[0])
    for y in range(1,a_height-1):
        for x in range(1,a_width-1):

            for n in range(-b_radius,b_radius):
                for m in range(-b_radius,b_radius):
                    # print(f"a acessed at {(y-n,x-m)} is {a[y+n][x+m]}")
                    var2 =  a[y+n][x+m]
                    if( not 1 & var2):
                        for i in range(-b_radius,b_radius):
                            for j in range(-b_radius,b_radius):
                                c[y+i][x+j] = 1 & var2

    return c


def print_matrix(matrix):
    for n in range(len(matrix)):
        for m in range(len(matrix[n])):
            print(matrix[n][m], end=' ')
        print()
    print()


b_size = 3
A_size = 10
B = [[1 for _ in range(b_size)] for _ in range(b_size)]
A = [[1 for _ in range(A_size)] for _ in range(A_size)]
C = [[1 for _ in range(A_size)] for _ in range(A_size)]

print_matrix(B)

for n in range(len(A)):
    for m in range(len(A[n])):
        A[n][m] = 0 if randint(0, 10) > 9 else A[n][m]
print_matrix(A)

C = iterate_center(A,B,C)

print_matrix(C)
C = clean_edges(C)

print_matrix(C)
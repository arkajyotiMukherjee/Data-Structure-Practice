def multi(sA, sB):
    print("Calculating multiplication:\n")
    r = sA[0][0]
    c = sB[0][1]
    mul = []

    mul.append([r, c, 0])

    #looping through sA
    for i in range(1, sA[0][2]+1):
        r1 = sA[i][0]
        c1 = sA[i][1]
        #looping through sB
        for j in range(1, sB[0][2]+1):
            if sB[j][0] == c1:
                mul.append([ r1, sB[j][1], sA[i][2]*sB[j][2] ])

    for row in mul:
        rm = row[0]
        cm = row[1]
        i = 0
        for check in mul:
            
            if check[0] == rm and check[1] == cm and check != row and i != 0:
                row[2] += check[2]
                mul.pop(i)
            i +=1

    mul[0][2] = len(mul) - 1

    for i in range(1, len(mul)-1):
        if (mul[i][0] > mul[i+1][0]) or (mul[i][0] == mul[i+1][0] and mul[i][1] > mul[i+1][1]):
            mul[i] , mul[i+1] = mul[i+1], mul[i]


    print("printing the multiplied matrix:")
    for row in mul:
        print(' '.join(str(elem) for elem in row))

    return mul
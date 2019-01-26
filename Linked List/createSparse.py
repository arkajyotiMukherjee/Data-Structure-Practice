def create(a):
    # count = 0
    # for i in range(len(a)):
    #     for j in range(len(a[0])):
    #         if a[i][j] != 0:
    #             count += 1

    # s = [[0 for j in range(3)] for i in range(count + 1)]
    # k = 1
    # s[0][0] = len(a)
    # s[0][1] = len(a[0])
    # s[0][2] = count

    # for i in range(len(a)):
    #     for j in range(len(a[0])):
    #         if a[i][j] != 0 :
    #             s[k][0] = i
    #             s[k][1] = j
    #             s[k][2] = a[i][j]
    #             k += 1

    #Alternate method
    s = []
    s.append([len(a), len(a[0]), 0])
    k = 1

    for i in range(len(a)):
        for j in range(len(a[0])):
            if a[i][j] != 0 :
                s.append([])
                s[k].append(i)
                s[k].append(j)
                s[k].append(a[i][j])
                k += 1

    s[0][2] = len(s) - 1

    print("printing the sparse array:")
    for row in s:
        print(' '.join(str(elem) for elem in row))
    
    return s
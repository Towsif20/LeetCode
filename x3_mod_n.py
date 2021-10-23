for x in range(187):
    print(x, "     ====>      ", (x**3)%187, end=" ")
    if(x % 4 == 0):
        print()
import time
N = 100000

def linearFunc():
    sumLinear = 0
    for i in range(0,N):
            sumLinear+=i
    print("Linear Done!")

def quadFunc():
    sumQuad = 0
    for i in range (0,N):
            for j in range(0,N):
                    sumQuad += j
    print("Quad Done!")


def cubicFunc():
    sumCube = 0
    for i in range(0,N):
            for j in range(0,N):
                    for k in range (0,N):
                            sumCube += k

    print("Cubic Done!")

def main():
    #Linear Function
    start = time.time()
    linearFunc()
    end = time.time()
    #time.time() returns in seconds so we must convert
    start = start*1000
    end = end *1000
    elapsed = end - start
    print("Time Elapsed: ")
    print(elapsed)
    #Quadratic Function
    start = time.time()
    quadFunc()
    end = time.time()
    #time.time() returns in seconds so we must convert
    start = start*1000
    end = end *1000
    elapsed = end - start
    print("Time Elapsed: ")
    print(elapsed)
    #Cubic Function
    start = time.time()
    cubicFunc()
    end = time.time()
    #time.time() returns in seconds so we must convert
    start = start*1000
    end = end *1000
    elapsed = end - start
    print("Time Elapsed: ")
    print(elapsed)

main()

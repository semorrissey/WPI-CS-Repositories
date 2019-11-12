#Question 4 Morrissey
from sys import maxsize

def largestSum(arr):
    finalSum, firstIndex, secondIndex = handleSum(arr)
    print("The pair of indices that form the largest sum are " + str(firstIndex) + " and " + str(secondIndex) + ".")
    print("The sum of the values at these indices is " + str(finalSum) + ".")

def handleSum(arr): 
    currentMax = -maxsize - 1
    segmentMax = 0
    first = 0
    second = 0
    temp = 0
  
    for i in range(0,len(arr)): 
  
        segmentMax += arr[i] 
        if currentMax < segmentMax: 
            currentMax = segmentMax 
            first = temp 
            second = i 
  
        if segmentMax < 0: 
            segmentMax = 0
            temp = i+1
    return currentMax, first, second


def main():

    arr = [10,20,-5,-15,11,-4,-30,25]
    largestSum(arr)

main()

# Python program to print largest contiguous array sum 

from sys import maxsize 

# Function to find the maximum contiguous subarray 
# and print its starting and end index 
def handleSum(arr): 
    currentMax = -maxsize - 1
    segementMax = 0
    first = 0
    second= 0
    temp = 0
    for i in range(0,len(arr)): 
        segementMax += arr[i] 
        if currentMax < segementMax: 
                currentMax = segementMax 
                first = temp 
                second = i 
        if currentMax < 0: 
                segementMax = 0
                temp = i+1


# Driver program to test maxSubArraySum 
arr = [10,20,-5,-15,11,-4,-30,25,60,-20,10]
largestSum(arr) 

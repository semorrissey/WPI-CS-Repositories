import math
nums = []
for i in range (1,201):
    if(i%2 == 0):
        nums.append(i)
        
def binarySearch(k):
    comparisons = 0
    first = 0
    last = len(nums)-1
    found = False
    while first<=last and not found:
        middle = math.floor(first + (last-first)/3)
        if nums[middle] == k:
            found = True
            comparisons += 1
        else:
            if k < nums[middle]:
                last = middle-1
                comparisons += 1
            else:
                first = middle+1
                comparisons += 1
    if(not found):
        print("The given k was not found")
    else:
        print("The given k was found")
        print("It was found in " + str(comparisons) +" comparisons")
        print("K was found at index " + str(middle))
                

def main():
    print("Please enter a number: ")
    k = int(input())
    binarySearch(k)

main()

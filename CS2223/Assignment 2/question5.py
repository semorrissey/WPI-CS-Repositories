#Question 5 Morrissey
    
def inversionCount(alist):
    count = 0
    leftcount = 0
    rightcount = 0
    newlist = [] 
    if len(alist) > 1:
       mid = len(alist) // 2
       lefthalf = alist[:mid]
       righthalf = alist[mid:]
       leftcount, lefthalf = inversionCount(lefthalf)
       rightcount, righthalf = inversionCount(righthalf)

       i = 0
       j = 0

       while i < len(lefthalf) and j < len(righthalf):
         if lefthalf[i] < righthalf[j]:
             newlist.append(lefthalf[i])
             i += 1
         else:
             newlist.append(righthalf[j])
             j += 1
             count += len(lefthalf[i:])

       while i < len(lefthalf):
          newlist.append(lefthalf[i])
          i += 1

       while j < len(righthalf):
          newlist.append(righthalf[j])
          j += 1
    else:
        newlist = alist

    return count + leftcount + rightcount, newlist

def main():
    initlist = [4,1,2]
    inversions, finalList = inversionCount(initlist)
    print("Unsorted List: ", initlist)
    print("Sorted List: ",finalList)
    print("The amount of inversions in this list are: ", inversions)
main()

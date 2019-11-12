#Question 2 Morrissey


def isreverse(str1, str2):
    return str2 == reverse(str1)


def reverse(string):
    if len(string) == 0:
        return string
    else:
        return reverse(string[1:]) + string[0]

def main():
    i=0
    k=0
    print("Please enter a string: ")
    givenStr = input();
    print("Please enter another string: ")
    givenStr2 = input();
    print(isreverse(givenStr, givenStr2))

main()
        

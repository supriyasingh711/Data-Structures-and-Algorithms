def powerFunc(mid,n,m):
    ans=1
    for _ in range(1,n+1):
        ans*=mid
    if ans>m:
        return 2
    elif ans==m:
        return 1
    return 0
def NthRoot(n,m):
    low=1
    high=m
    while(low<high):
        mid=(low+high)//2
        if powerFunc(mid,n,m)==1:
            return mid
        elif powerFunc(mid,n,m)>1:
            high=mid-1
        else:
            low=mid+1
    return mid
print("the 3rd root of 27 is",NthRoot(3,27))

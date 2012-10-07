from sets import Set

def init(numbers, forks): # initial sets
    index = 0
    for x in range(1,16):
        if x == 2**index:
            forks[x] = Set([numbers[index]])
            index += 1
        else:
            forks[x] = Set([])
    
def unite(fork1, fork2): # unite two sets
    fork3 = Set()
    for ele1 in fork1:
        for ele2 in fork2:
            (big, small) = ele2 > ele1 and (ele2, ele1) or (ele1, ele2)
            fork3 |= Set([big+small, big-small])
            if ele1 != 0 and ele2 != 0:
                fork3 |= Set([ele1*ele2, float(ele1)/ele2, float(ele2)/ele1])
            else:
                fork3.add(0)
    return fork3

def calcSet(forks, index): # calculate each sets
    if forks[index]:
        return
    
    for x in range(1, index/2+1):
        if x | index == index:
            forks[index] |= unite(forks[x], forks[index-x])
                
if __name__ == '__main__':
    forks = {} 
    numbers = []
    inputs = raw_input("input 4 numbers:")
    for x in inputs.split():
        numbers.append(int(x))
    init(numbers, forks)
    for x in range(1,16):
        calcSet(forks, x)
        #print "fork[%d] = %s" % (x, forks[x])
    print 24 in forks[15]
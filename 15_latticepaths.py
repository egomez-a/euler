#function to calculate paths
def paths(n):
#apply the above stated rule for n iterations
    j = 1
    for i in range(1,n):
        j = j * (n + i) / i
    return j

def main():
  # input grid size
  p = paths(20);

#print paths
  print('The number of paths are:')
  print (p * 2)

main()
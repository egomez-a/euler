multiples = []

for i in range(1000):
    if (i % 3 == 0) or (i % 5 == 0):
        multiples += [i]
sumofmultiples = sum(multiples)
print('the sum of all multiples of 3 or 5 below 1000 is:', sumofmultiples)
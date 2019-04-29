import statistics

i = input()
data = []

while i !=-1 :
	data.append(i)
	i = input()

print 'Mean: {}'.format(statistics.mean(data))
print 'Standard deviation: {}'.format(statistics.stdev(data))

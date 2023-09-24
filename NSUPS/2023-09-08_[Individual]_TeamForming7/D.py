i = int(1);
facto = []
facto.append(1);
facto.append(1);
for i in range(2, 1000000):
	facto.append(facto[-1] * i)
print(facto[1000000])
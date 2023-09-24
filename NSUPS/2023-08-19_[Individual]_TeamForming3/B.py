n = int(input());

arr_A = [int(i) for i in input().split()]

m = int(input());

arr_B = [int(i) for i in input().split()]

a = 1;
for i in arr_A:
	a *= i;

b = 1;
for i in arr_B:
	b *= i;

def gcd(a, b):
	if b == 0:
		return a;
	return gcd(b, a % b)

result = str(gcd(a, b))

if len(result) <= 9:
	print(result)
else:
	print(result[len(result) - 9:])



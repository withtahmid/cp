sum = 0;
for(i = 1; i <= n; ++i){
	if(i % P != 0 and i % J != 0){
		sum += i;
	}
}
print(sum)

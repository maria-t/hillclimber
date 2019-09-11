double eval(int *vec){
	
	int zeroes;
	int ones;

	for (int i = 0; i < 50; i++){
		if ((i%7)==0){
			if (vec[i] == 1){
				ones++;
			}
		}
	}	
	for (int i = 50; i < 100; i++){
		if ((i%11)==0){
			if (vec[i] == 1){
				zeroes++;
			}
		}
	}
	if ((zeroes+ones) == 100){
		return 100;
}
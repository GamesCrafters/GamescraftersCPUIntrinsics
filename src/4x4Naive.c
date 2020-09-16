static void transpose(int* position) {
    int temp;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            temp = *(position+(4*i)+j);
            *(position+(4*i)+j) = *(position+(4*j)+i);
            *(position+(4*j)+i) = temp;
        }
    }
}
void flip(int* position) {
	int temp;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			temp = *(position+(4*i)+j);
			*(position+(4*i)+j) = *(position+(4*(3-i))+j);
			*(position+(4*(3-i))+j) = temp;
		}
	}
}
void rotate(int* position) {
	flip(position);
	transpose(position);
}
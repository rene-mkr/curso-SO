int getNext(int cluster, int base) {
	// Para FAT12
	int offset = cluster + cluster/2;
	int flag = cluster % 2; // Nos dice si en la parte baja o alta

	unsigned char b1,b2;
	b1 = map[base+offset];
	printf("%02x:",b1);
	b2 = map[base+offset+1];
	printf("%02x\n",b2);
	int result = b1 | b2<<8;

	if(flag) {
		result >>= 4;
	}
	else {
		result &= 0xfff;
	}

	printf("%04x\n",result);
  
	return result;
}

#include<stdio.h>
#include<stdint.h>

void main(){
	unsigned int reg=0xabcd;
	unsigned int lower;
	unsigned int upper_lowerbyte;
	printf("Original number is 0x%X\n", reg);
	lower = reg & 0x000f;
	upper_lowerbyte= (reg&0x00f0)>>4;
	printf("  lower 4 bits %X\n", lower);
	printf(" upper 4 bits of lower byte %X\n", upper_lowerbyte);
	

	


}



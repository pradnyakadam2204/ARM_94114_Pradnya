#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t reg = 0xAA;   // 1010 1010

    uint8_t read;
    
    
    printf("Before change = 0x%X\n", reg);

    
    read = (reg >> 2) & 0x07;
    printf("Bits 2 to 4 = 0x%X\n", read);

    
    reg = reg & ~(0x07 << 2);   // clear bits 2–4
    reg = reg |  (0x03 << 2);   // write 011

   
    printf("After change  = 0x%X\n", reg);

    return 0;
}

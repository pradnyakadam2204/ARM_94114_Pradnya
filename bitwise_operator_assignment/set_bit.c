#include<stdio.h>
#define bv(n)(1<<n)

void main()
{ unsigned char reg=0x2a;
 reg=reg| bv(4);
 printf("after set operation \n hexadecimal no. is %X",reg);
 printf("\n binary no. is ");
 print_bin(&reg , sizeof(reg));
 
 unsigned char reg1=0x2a;
 reg1=reg1&~ bv(1);
 printf("after clear operation \n hexadecimal no. is %X",reg1);
 printf("\n binary no. is ");
 print_bin(&reg1 , sizeof(reg1));
 
 unsigned char reg2=0x2a;
 reg2=reg2^bv(5);
 printf("after toggle operation \n hexadecimal no. is %X",reg2);
 printf("\n binary no. is ");
 print_bin(&reg2 , sizeof(reg2));
 
}

void print_bin(void *vp, int size)
{
    int i;

    // Loop from the most significant byte to the least.
    for(i = size - 1; i >= 0; i--)
    {
        unsigned char mask = 0x80;      // Start checking from MSB (bit-7)

        // Check all 8 bits of the selected byte
        while(mask)
        {
            /*
             * (char *)vp + i :
             *      - Cast vp to a byte pointer
             *      - Move to the i-th byte of the variable
             *
             * *((char *)vp + i) :
             *      - Read that byte value
             *
             * & mask :
             *      - Check whether the current bit is 1 or 0
             */
            if( *((char *)vp + i) & mask )
                printf("1");
            else
                printf("0");

            mask >>= 1;  // Move mask to next lower bit
        }

        printf(" ");     // Space between bytes
    }

    printf("\n");
}

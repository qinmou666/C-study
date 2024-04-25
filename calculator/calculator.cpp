#include <stdio.h>
#include <stdint.h>

#include <stdio.h>
#include <stdint.h>
 
void encrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0, i;
    uint32_t delta = 0x61C88647;
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];
    for (i=0; i < 32; i++) {
        sum -= delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }
    v[0]=v0; v[1]=v1;
}
 

void decrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], i;
    uint32_t delta= 0x61c88647;
    uint32_t sum = 0xc6ef3720;
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];
    for (i=0; i<32; i++) {
       
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum += delta;
    }
    v[0]=v0; v[1]=v1;
}
 
int main()
{
    /*uint32_t sum = 0, de = 0x61c88647;
    for (int k = 0; k < 32; k++)
    {
        sum -= de;
        printf("sum %d %x\n",k, sum);
    }
    */
    uint32_t Data[] = { 0xB805D767,0x63c174c3 };

    uint32_t key[4] = { 2,2,3,4 };
    printf("%x %x\n", Data[0], Data[1]);
;
 
    /*encrypt(Data, key);
    printf("%x %x\n", Data[0], Data[1]);*/
    decrypt(Data, key);
    printf("%x %x\n", Data[0], Data[1]);

    /*
    for (int i = 0; i < 8; i += 2)
    {
        uint32_t temp[2];        //定义来解密
        temp[0] = Data[i];
        temp[1] = Data[i + 1];
        decrypt(temp, key);
        //printf("%X%X",temp[0],temp[1]);
        printf("%c%c%c%c%c%c%c%c", *((char*)&temp[0] + 0), *((char*)&temp[0] + 1), *((char*)&temp[0] + 2), *((char*)&temp[0] + 3), *((char*)&temp[1] + 0), *((char*)&temp[1] + 1), *((char*)&temp[1] + 2), *((char*)&temp[1] + 3));
    }
    */

  

}

/*
spi master + eth
*/

#include <mbed.h>
//#include "platform/mbed_thread.h"
#include <rtos.h>

SPISlave device(PA_7, PA_6, PA_5, PA_15);
DigitalOut drdyOut(PA_10);

//int count111=0;  //for test

int main() {
 
   // int counter = 1;
 
    device.format(8,3);        // Setup:  bit data, high steady state clock, 2nd edge capture
    device.frequency(1000000); // 1MHz
 
    //int reply = 99;
    //device.reply(reply);              // Prime SPI with first reply
    //device.reply(reply);              // Prime SPI with first reply, again
 
    //printf("======================================================\r\n");
    //printf("Startup Next reply will be %d\r\n", reply);
 //int valueFromMaster=0;
 uint8_t * BufferMsv = new uint8_t[3];
 //uint8_t * BufferMsv1 = new uint8_t[3];  //for test
//  uint8_t * BufferMsv2 = new uint8_t[3];
//  uint8_t * BufferMsv3 = new uint8_t[3];
 BufferMsv[0]=0xc8;
 BufferMsv[1]=0x64;
 BufferMsv[2]=0x32;
/*
 BufferMsv1[0]=0x99;
 BufferMsv1[1]=0xff;
 BufferMsv1[2]=0x99;

 BufferMsv2[0]=0x64;
 BufferMsv2[1]=0x64;
 BufferMsv2[2]=0x64;

 BufferMsv3[0]=0x32;
 BufferMsv3[1]=0x32;
 BufferMsv3[2]=0x32;
//  BufferMsv[0]=10;
//  BufferMsv[1]=20;
//  BufferMsv[2]=30;
*/ 
 //uint32_t counterDRDY=0;  //for test

    while (1) {
        //if(counterDRDY==1){counterDRDY=0; device.reply(99);}
        drdyOut=1;  
                    wait_ns(5);
                    //counterDRDY++;
        if (device.receive()) {
            //device.reply(111); count111++; //for test
            //if(count111==10){device.reply(222); count111=0;}  //for test
            //valueFromMaster = device.read();
            //printf("valueFromMaster = %d \n\r", valueFromMaster);
            for(int i=0; i<3; ++i){
                device.reply(BufferMsv[i]);
            }
/*
 if(counterDRDY>=0 && counterDRDY<40){
            for(int i=0; i<3; ++i){
                device.reply(BufferMsv1[i]);
            }
 }
 if(counterDRDY>=40 && counterDRDY<80){
            for(int i=0; i<3; ++i){
                device.reply(BufferMsv2[i]);
            }
 }
 if(counterDRDY>=80 && counterDRDY<120){
            for(int i=0; i<3; ++i){
                device.reply(BufferMsv3[i]);
            }
 }
 if(counterDRDY==120){counterDRDY=0;} 
 */          
            // for(int i=0; i<3; ++i){
            //     BufferMsv[0]+=i;
            //     BufferMsv[1]+=i;
            //     BufferMsv[2]+=i;
            // }
            //device.reply(valueFromMaster);
            //printf("device.reply = %d \n\r", valueFromMaster);
            // printf("%d Something rxvd, and should have replied with %d\n\r", counter++, reply);
            // device.reply(++reply);              // Prime SPI with next reply
            // printf("    Received value from Master (%d) Next reply will be %d \r\n", valueFromMaster, reply);
        }
        // wait_ms(500);
        //wait_ns(2300);
        //wait_ns(1);
        drdyOut=0;
        // wait_ms(2000);
        //wait_ns(5);
//wait_ns(2300);
        wait_ns(3000);
/*
         if(counterDRDY>=0 && counterDRDY<40){
            BufferMsv[0]=0x0a;
            BufferMsv[1]=0x14;
            BufferMsv[2]=0x1e;
             //printf("-----%u------------- \n", counterDRDY);
             //wait(3000);
         }
         if(counterDRDY>=40 && counterDRDY<80){
            BufferMsv[0]=0xff;
            BufferMsv[1]=0xff;
            BufferMsv[2]=0xff;
             //printf("-----%u------------- \n", counterDRDY);
             //wait(3000);
         }
        if(counterDRDY>=80 && counterDRDY<120){
            BufferMsv[0]=0x32;
            BufferMsv[1]=0x37;
            BufferMsv[2]=0x3c;
             //printf("-----%u------------- \n", counterDRDY);
             //wait(3000);
         }
         */
        //if(counterDRDY==120){counterDRDY=0;}
         
    }
    //delete[] BufferMsv;
}

/*
int main() {
 
    int counter = 1;
 
    device.format(8,3);        // Setup:  bit data, high steady state clock, 2nd edge capture
    device.frequency(1000000); // 1MHz
 
    int reply = 99;
    device.reply(reply);              // Prime SPI with first reply
    device.reply(reply);              // Prime SPI with first reply, again
 
    printf("======================================================\r\n");
    printf("Startup Next reply will be %d\r\n", reply);
 int valueFromMaster=0;
    while (1) {
        if (device.receive()) {
            valueFromMaster = device.read();
            printf("valueFromMaster = %d \n\r", valueFromMaster);
            device.reply(valueFromMaster);
            printf("device.reply = %d \n\r", valueFromMaster);
            // printf("%d Something rxvd, and should have replied with %d\n\r", counter++, reply);
            // device.reply(++reply);              // Prime SPI with next reply
            // printf("    Received value from Master (%d) Next reply will be %d \r\n", valueFromMaster, reply);
        }
    }
}
*/
//SPISlave device(SPI_MOSI, SPI_MISO, SPI_SCK, SPI_CS);
/*
SPISlave device(PA_7, PA_6, PA_5, PA_15);
int main() {
    device.reply(0x00);              // Prime SPI with first reply
    while(1) {
        if(device.receive()) {
            int v = device.read();   // Read byte from master
            v = (v + 1) % 0x100;     // Add one to it, modulo 256
            device.reply(v);         // Make this the next reply
            printf("v = device.read = %d", v);
        }
    }
}
*/
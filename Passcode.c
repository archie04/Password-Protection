#include<reg51.h>
void dota(unsigned char);
void check();
void dis(unsigned char*,unsigned char);
void setup(unsigned char);
void delay();
void delay1();
unsigned char p[5];
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;

sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
sfr lcd=0xa0;
unsigned char x=0;

 void main()
 {

 
 P2=0x00;
 setup(0x38);
 delay();
 setup(0x01);
 delay();
 setup(0x10);
 delay();
 setup(0x0c);
 delay();
 setup(0x81);
 delay();
 dis("enter password",14);
 delay();
 setup(0x01);
 delay();
 while(1)
{
 

 
 r4=1;
 r3=1;
 r2=1;
 r1=0;
 if(c1==0)
  {
   dota('*');
   delay1();
   p[x]='1';
   x=x+1;
  }
 if(c2==0)
 {
  dota('*');
   delay1();
   p[x]='2';
   x=x+1;
  }
 if(c3==0)
   {
 	dota('*');
   delay1();
   p[x]='3';
   x=x+1;
	}
 r2=1;
 r3=1;
 r4=1;
 r2=0;
 r1=1;
 if(c1==0)
 {
  dota('*');
   delay1();
   p[x]='4';
   x=x+1;
   }
 if(c2==0)
 {
  dota('*');
   delay1();
   p[x]='5';
   x=x+1;
  }
 if(c3==0)
 {
 dota('*');
   delay1();
   p[x]='6';
   x=x+1;
   }
 r2=1;
 r3=0;
 if(c1==0)
  {

   dota('*');
   delay1();
   p[x]='7';
   x=x+1;
   }
 if(c2==0)
 {
 dota('*');
   delay1();
   p[x]='8';
   x=x+1;
 }
 if(c3==0)
 {
 	dota('*');
   delay1();
   p[x]='9';
   x=x+1;
   }

  r2=1;
  r1=1;
  r3=1;
  r4=0;
  if(c1==0)
  {
  dota('*');
   delay1();
   p[x]='*';
   x=x+1;
  }
 if(c2==0)
  {
   dota('*');
   delay1();
   p[x]='0';
   x=x+1;
 }
 if(c3==0)
 {
 	dota('*');
   delay1();
   check();
   delay();
   delay();
 }
 


 }
}

void check()
{
 if(p[0]=='1'&&p[1]=='2'&&p[2]=='3'&&p[3]=='4')
 {
  setup(0x01);
  delay();
  dis("password correct",16);
  delay();
 }
 else
 {
  setup(0x01);
  delay();
  dis("incorrect",9);
  delay();
 }
 setup(0x01);
 delay();
 dis("enter password",14);
 delay();
 setup(0x01);
 delay();
 x=0;

}

void setup(unsigned char i)
 {
  P2=i;
  rs=0;
  rw=0;
  en=1;
  delay();
  en=0;

  }
 void dota(unsigned char h)
  {
   P2=h;
   rs=1;
   rw=0;
   en=1;
   delay();
   en=0;
 
   }
   void delay()
   {
	 unsigned int z;
	 for(z=0;z<10000;z++);
	  
	 
	 
	}
   void delay1()
   {
    unsigned int i,j;
	for(i=0;i<200;i++)
	 for(j=0;j<2000;j++);
	}

	void dis(unsigned char*arr, unsigned char w)
	{
	 unsigned char u;
	 for(u=0;u<w;u++)
	 {
	   dota(arr[u]);
	   delay();
	   }
	 }

	  

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int read(char c){return c>='a'? (c-'a'+10):(c-'0');}
char output(int plain){return (plain < 10) ? (plain + '0') : (plain + 'a' - 10);}
int main()
{

 	int M[4],K[8],n;

    int Inv_S_box[]={0xE, 0x3, 0x4, 0x8, 0x1, 0xC, 0xA, 0xF,0x7, 0xD, 0x9, 0x6, 0xB, 0x2, 0x0, 0x5	};
    int S_box[]={0xE, 0x4, 0xD, 0x1, 0x2, 0xF, 0xB, 0x8,0x3, 0xA, 0x6, 0xC, 0x5, 0x9, 0x0, 0x7};
	//p置换
    int p[16] = { 1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16 };
	

	cin>>n;
    getchar();
	while(n--)
	{   //读入密钥
		char c;
		for (int i = 0;i < 8 ;i++){
         	c = getchar();
             K[i] = read(c);
          	//key[i] = ((c>= 'a')?(c -'a' + 10):(c- '0'));
        }
      	getchar();
        //读入明文
      	for (int i = 0;i < 4 ;i++){
         	c = getchar();
          	M[i] = read(c);
            //plain[i] = ((c>= 'a')?(c -'a' + 10):(c- '0'));
        }
      	getchar();	
        
        //1-3轮
		for(int m=0;m<3;m++)
		{
			for(int j = 0 ;j< 4;j++)
            {	
              M[j] = M[j]^ K[m + j];
              M[j] = S_box[M[j]];
            }
            //p置换
			int tmp[4];
            tmp[0] = ((M[0] & 0x8) >> 0) | ((M[1] & 0x8) >> 1) | ((M[2] & 0x8) >> 2) | ((M[3] & 0x8) >> 3);
            tmp[1] = ((M[0] & 0x4) << 1) | ((M[1] & 0x4) >> 0) | ((M[2] & 0x4) >> 1) | ((M[3] & 0x4) >> 2);
            tmp[2] = ((M[0] & 0x2) << 2) | ((M[1] & 0x2) << 1) | ((M[2] & 0x2) >> 0) | ((M[3] & 0x2) >> 1);
            tmp[3] = ((M[0] & 0x1) << 3) | ((M[1] & 0x1) << 2) | ((M[2] & 0x1) << 1) | ((M[3] & 0x1) >> 0);
            M[0] = tmp[0];
            M[1] = tmp[1];
            M[2] = tmp[2];
            M[3] = tmp[3];
		}

		//第4轮 
		
      	for(int j = 0 ;j< 4;j++){
          M[j] ^= K[3 + j];
          M[j] = S_box[M[j]];		
          M[j] ^= K[4 + j];
    	}
      
        for (int i = 0; i < 4; ++i) {
            char t = output(M[i]);
            //char t = (M[i] < 10) ? (M[i] + '0') : (M[i] + 'a' - 10);
            putchar(t);
        }
        putchar(' ');
               
        //解密
	    M[3] ^= 0x1;
        for(int j = 0;j<4;j++){
          M[j] ^= K[4 + j];
          M[j] = Inv_S_box[M[j]];		
          M[j] ^= K[3 + j];
        }
      
	    for(int m=2;m >= 0;m--)
	    {
	    	//p 置换
			int tmp[4];
            tmp[0] = ((M[0] & 0x8) >> 0) | ((M[1] & 0x8) >> 1) | ((M[2] & 0x8) >> 2) | ((M[3] & 0x8) >> 3);
            tmp[1] = ((M[0] & 0x4) << 1) | ((M[1] & 0x4) >> 0) | ((M[2] & 0x4) >> 1) | ((M[3] & 0x4) >> 2);
            tmp[2] = ((M[0] & 0x2) << 2) | ((M[1] & 0x2) << 1) | ((M[2] & 0x2) >> 0) | ((M[3] & 0x2) >> 1);
            tmp[3] = ((M[0] & 0x1) << 3) | ((M[1] & 0x1) << 2) | ((M[2] & 0x1) << 1) | ((M[3] & 0x1) >> 0);
            M[0] = tmp[0];
            M[1] = tmp[1];
            M[2] = tmp[2];
            M[3] = tmp[3];
			
			//s 逆运算
			for(int i=0;i<4;i++)
			{
			  
			   M[i] = Inv_S_box[M[i]];
               M[i] ^= K[m + i];  
	        }  

		}
    	
      	for (int i = 0; i < 4; ++i) {
            char t = output(M[i]);
            //char t = (M[i] < 10) ? (M[i] + '0') : (M[i] + 'a' - 10);
            putchar(t);
        }
        putchar('\n');
		 	
  }
 
}
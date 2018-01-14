#include<stdio.h>
#include<stdlib.h>


int main()
{
 int a = 10, b = 0, c = 10;

 // The encoded string after removing first 31 characters
 // Its individual characters determine how many spaces
 // or exclamation marks to draw consecutively.
 char* str = "TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs UJq "
 "TNn*RPn/QPbEWS_JSWQAIJO^NBELPeHBFHT}TnALVlBL"
 "OFAkHFOuFETpHCStHAUFAgcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm "
 "SOn TNn ULo0ULo#ULo-WHq!WFs XDt!";
 while (a != 0)
 {
 // read each character of encoded string
 a = str[b++];
 while (a-- > 64)
 {
 if (++c == 90) // 'Z' is 90 in ascii
 {
 // reset c to 10 when the end of line is reached
 c = 10;  // '\n' is 10 in ascii
 // print newline
 putchar('\n'); // or putchar(c);
 }
 else
 {
 // draw the appropriate character
 // depending on whether b is even or odd
 if (b % 2 == 0)
 putchar('!');
 else
 putchar(' ');
 }
 }
 }
 getch();
 return 0;

}

/*
#include "stdio.h"

int main()
{
    int a, b, c;
    for (b=c=10; a="Hello!Welcome to GeeksForGeeks.\
      TFy!QJu ROo TNn(ROo)SLq SLq ULo+\
      UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^\
      NBELPeHBFHT}TnALVlBLOFAkHFOuFETp\
      HCStHAUFAgcEAelclcn^r^r\\tZvYxXy\
      T|S~Pn SPm SOn TNn ULo0ULo#ULo-W\
      Hq!WFs XDt!" [b+++21]; )

      for (; a-- > 64 ; )
         putchar ( ++c=='Z' ? c = c/ 9:33^b&1);
    return 0;
}
*/

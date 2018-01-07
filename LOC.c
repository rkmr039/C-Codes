// Software Engineering (Lab.)
// Programe to calculate Line of Code
// Rishab Kumar  00110407216    08 September 2017
// Each Header file should be in defferent line 
// multiline comment should start and end with new line 
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int getASCII(char ch)
{return ch;}
int main()
{
	FILE *fp;
	char ch =' ';
	int bl=0,totalLines=1,mcl=0,scl=0,ASCII;
	fp = fopen("locCount.c","r");
	if(fp == NULL)
		{printf("\nError Opening File\n");}
	else
	{
		while((ch = fgetc(fp) )!= EOF)
		{ 
			if(ch != '\n')
			{
				printf("%c",ch);
				ASCII = getASCII(ch);
				// calculate comments
				if(ASCII == 47)
			    {
			    	ch = fgetc(fp);ASCII = getASCII(ch);
			    	if(ASCII == 47)
			    		{scl++;/*fseek(fp,-1,1);*/}
			    	else if(ASCII == 42)
			    	{// ASCII of '\' is 47 and ASCII of '*' is 42
			    		printf("%c",ch);mcl++;totalLines++;
			    		while((ASCII = getASCII(ch)) != 47)
			    		{
			    			ch = fgetc(fp);printf("%c",ch);
			    			if(ch == '\n') {mcl++;totalLines++;}
			    		}
			    	}
			    }
			}
			else
			{	
				//printf("NL\n");
				totalLines++;// blank line calculation
				if(fgetc(fp) == '\n')
					{bl++;}
				fseek(fp,-1,SEEK_CUR);
			}
		}
	}
	printf("\n\n\nLines Of Count: %d\n",totalLines-(bl+mcl+scl));
	printf("\nMCL: %d",mcl);
	printf("\nSCL: %d",scl);
	printf("\nBL : %d\n",bl );
	fclose(fp);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int functions()
{
	int value;
	printf("\n0.No Influence\n1.Significant\n2.Moderate\n3.Average\n4.Significant\n5.Essential\n");
	scanf("%d",&value);
	return value;	
}
int userInputs(int j)
{
	int value;
	switch(j)
	{
		case 0:
			printf("\n1.Low: ");
			break;
		case 1: 
			printf("\n2.Average: ");
			break;
		case 2:
			printf("\n3.High: ");
			break;
	}
	scanf("%d",&value);
	return value;
}
int main()
{
	int j,cafMatrix[14],i;
	int ufp=0,caf=0;
	float cafVar;
	int ufpMatrix[5][3];
	int weights[5][3]={3,4,6,4,5,7,3,4,6,7,10,15,5,7,10};
	printf("\n=====Unadjusted Function Calculation=====");
	for(i=0; i<5; i++)
		{
			switch(i)
			{

				case 0:
				
				printf("\nNumber of external inputs: ");
				break;
				
				case 1:
				printf("\nNumber of external outputs: ");
				break;
				case 2:
				printf("\nNumber of enquries: ");
				break;
				case 3:
				printf("\nNumber of internal loghical files: ");
				break;
				case 4:
				printf("\nNumber of exteraal interface: ");
				break;
			}

			for(j=0; j<3; j++)
			{
				ufpMatrix[i][j] = userInputs(j);
			}
	    }
	for(i=0; i<5; i++)
	{
		for(j=0; j<3; j++)
		{
			ufp += ufpMatrix[i][j]*weights[i][j]; 
		}
	}
	printf("\nUnadjusted Function Point: %d",ufp);
	printf("\n=====Complexity Adjustment Calculation:=====");    
	printf("\nSelect any one choice: ");
	for(i=0; i<14; i++)
	{
		switch(i)
		{
			case 0:
			 printf("\nDose the system requires reliable backup and recovery?");
			 cafMatrix[i] = functions();
			 break;
			case 1:
			 printf("\nIs data communication required?");
			 cafMatrix[i] = functions();
			 break;
			case 2:
			 printf("\nAre there distributed processing system?");
			 cafMatrix[i] = functions();
			 break; 
			case 3:
			 printf("\nIs performance critical?");
			 cafMatrix[i] = functions();
			 break;
			case 4:
			 //printf("\nWill the system run in existing heavily utilized operational environment?");
			 cafMatrix[i] = functions();
			 break;
			case 5:
			// printf("\nDose the system require online data entry?");
			 cafMatrix[i] = functions();
			 break;   
			case 6:
			 printf("\nDose the online data entry require the input transasction to be built over multiple screens or operations?");
			 cafMatrix[i] = functions();
			 break;
			case 7:
			 //printf("\nAre the master file update online?");
			 cafMatrix[i] = functions();
			 break;
			case 8:
			 printf("\nIs the inputs, outputs, files or inquries complex?");
			 cafMatrix[i] = functions();
			 break;
			case 9:
			 printf("\nIs the internal procesing complex?");
			 cafMatrix[i] = functions();
			 break;
			case 10:
			 printf("\nIs the code designed to be reusable?");
			 cafMatrix[i] = functions();
			 break;
			case 11:
			 /*printf("\nAre conversion and installation included in the design?");*/
			 cafMatrix[i] = functions();
			 break;   
			case 12:
			 /*printf("\nIs the system designed for multiple installations in different organisations?");
			 cafMatrix[i] = functions();
			 */
			break;
			case 13:
			 printf("\nIs the application designed to facilitate change nand ease of use by the user?");
			 cafMatrix[i] = functions();
			 break;
		}
	}
	for(i=0; i<14; i++)
	{
		caf += cafMatrix[i];	
	}
	cafVar = 0.65+(0.01*caf);
	//printf("\nComplexity Adjustment Function: %f",cafVar);
	printf("\nFunction Point: %f",cafVar*ufp);
return 0;
}
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void answer();
void money();
FILE *fptr;
char line[200];
char ch;
int flag=1,flag1=1;
int j;
char ans;
   int count1=1;
   int count2=1;
int mon=1000;
int mon1=0;
int flag2=1;
int main()
{
 
    /*INTRO*/
    printf("------------------------WELCOME TO KBC------------------------\n");
    printf("THE RULES ARE \n 1. ONLY ONE PERSON CAN PLAY AT A TIME \n 2. MONEY IS ADDED TO EXISTING AMOUNT AFTER EVERY QUESTION \n 3. THERE ARE 2 LIFELINES YOU CAN USE\n");
    char opt;
    
    
    int i=4,count=1;
    int linenumber;
    fptr=fopen("kbc.txt","r");
    
    /*QUESTIONS*/
    do
    {
    linenumber=i;
    printf("\n");
    printf("\n");
    printf("\n_____YOU WILL RECEIVE %d RUPEES FOR THIS QUESTION_____\n",mon-mon1);
    while(fgets(line, sizeof line, fptr)!='\0')
    {
        if(count<linenumber)
        {
        printf(" %s",line);
        }
        else if(count==linenumber)
        {

            break;
        }
        count++;
    }
    
    
    
    i=i+4;
    if(count2==1)
    
    
    /*LIFELINE*/
    {
    printf("\n DO YOU WANT ANY LIFELINE? \n IF YESS ENTER Y\n IF NO ENTER N \n ");
    scanf(" %c",&opt);
    if(opt=='Y' || opt=='y')
    {
            char ans1;
            ch=line[0];
             printf("\n ENTER YOUR FIRST ANSWER: \n");
             scanf(" %c",&ans);
        if(tolower(ans)!=tolower(ch))
            {
                printf("\n ENTER YOUR SECOND ANSWER \n");
                scanf(" %c",&ans1);
                if(tolower(ans1)==tolower(ch))
                /*2ND ATTEMPT*/
                {
		// (only applicable to windows ) Beep(659,1200);
		// (only applicable to windows ) Beep(698,350);
		printf("__________________________________________");
                printf("\n|------ CONGRATS! CORRECT ANSWER---------|");
                money();
                    flag=1;
                }
            else
            {
                printf("WRONG ANSWER\n");
                flag=0;
            }
            }
            /*1ST ATTEMPT*/
            else
            {
		// (only applicable to windows ) Beep(659,1200);
		// (only applicable to windows ) Beep(698,350);
               printf("__________________________________________");
               printf("\n|------ CONGRATS! CORRECT ANSWER---------|");
               money();
               flag=1;
            }

    count2++;
    }
    else if(opt=='N' || opt=='n')
    {
    answer();
    }
    }
    else
    {
      answer();
    } 
}while(flag==1);

return 0;
}


    /*ANSWERS*/
void answer()
{
    int j=1;
    char ans;
    int count1=1;
    printf(" enter the answer: ");
    scanf(" %c",&ans);
        if(count1==j)
        {
            ch=line[0];


            if(tolower(ans)==tolower(ch))
            {
		// (only applicable to windows ) Beep(659,1200);
		// (only applicable to windows ) Beep(698,350);
                printf("__________________________________________");
                printf("\n|------ CONGRATS! CORRECT ANSWER---------|");
                money();
                flag=1;
            }
        else
        {
            printf("\nWRONG ANSWER");
            flag=0;
            printf("\nYOU WON TOTAL %d RUPEES",mon1);
        }
        count1++;
        }


    j=j+1;
    count1=count1-1;
}

   /*MONEY*/
void money()
{
 if(mon==1024000)
 {
  flag2=0;
 }
 mon1=mon;
 printf("\n|---- YOU WON TOTAL %8d RUPEES!!!---|\n",mon);
 printf("|________________________________________|");
 mon=mon*2;
}

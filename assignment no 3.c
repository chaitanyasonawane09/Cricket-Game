
#include<stdio.h>
#include<string.h>

struct player
{
    int age;
    int no_ODI;
    int no_twenty;
    int no_wickets;
    char name[20];
    char country[20];
    char category[20];
    int average;


};

void accept(int n,struct player s[n]);
void display(int n,struct player s[n]);
void batsman(int n,struct player s[n]);
void bowlers(int n,struct player s[n]);
void avg_batscore(int n,struct player s[n]);
void maxwicket(int n,struct player s[n]);
void highscore(int n,struct player s[n]);
int main()
{
    int n,option;
    printf("enter the no of cricket player : ");
    scanf("%d",&n);
    struct player s[n];
    do
    {     printf("\n");
          printf("\n");
        printf("enter the option : \n");
         printf(" 1: accept the information \n 2: display the information \n 3: Number of batsman of a particular country  \n 4: Number of bowlers of a particular country \n 5: Sort the Batsman as per the average batting score(Bubble/insertion sort) \n 6: The bowler that has taken a maximum no of wickets \n 7:Batsman with highest average score (Binary search) \n 0: exit \n");
         scanf("%d",&option);
         switch(option)
         {
             case 1:  printf("\n");
                      printf("enter the information of players\n");
                     accept(n,s);
                     break;
            case 2: printf("the information of players\n");
                     display(n,s);
                     break;
            case 3: printf("the  no batsman of country\n");
                     batsman(n,s);
                     break;
            case 4: printf("the  no bowlers of country\n");
                     bowlers(n,s);
                     break;
           case 5: printf("the avg_batscore \n");
                    avg_batscore(n,s);
                     break;
            case 6: printf("the bowler with highest wickets \n");
                     maxwicket(n,s);
                     break;
            case 7: printf("the player with highest avg_score \n");
                     highscore(n,s);
                     break;

         }
    }while(option!=0);



}
void accept(int n,struct player s[n])
{
  int i;
  for(i=0;i<n;i++)
  {
      printf("enter the information of %d player : age,no_ODI,no_twenty,no of wickets,name,country,category ,avg batscore\n",i+1);
      scanf("%d%d%d%d%s%s%s%d",&s[i].age,&s[i].no_ODI,&s[i].no_twenty,&s[i].no_wickets,s[i].name,s[i].country,s[i].category,&s[i].average);

  }
}

void display(int n,struct player s[n])
{
  int i;
    printf("the information of player : \n");
      printf("----------------------------------------------------------------------\n");
      printf("age ODI twenty wic.  name     country      category        avg batscore \n");
      printf("------------------------------------------------------------------------\n");
  for(i=0;i<n;i++)
  {
      printf("%d \t%d \t\t%d \t%d \t%s \t%s \t%s \t\t%d \n",s[i].age,s[i].no_ODI,s[i].no_twenty,s[i].no_wickets,s[i].name,s[i].country,s[i].category,s[i].average);

  }
      printf("--------------------------------------------------------------------------\n");
}
void batsman(int n,struct player s[n])
{
    int i=0,count=0;
    char c[20];
    printf("enter the name of country : ");
    scanf("%s",c);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].country,c)==0&&strcmp(s[i].category,"batsman")==0)
        {
            count++;
        }

    }
    printf("the no of batsman of %s are : %d \n",c,count);

}
void bowlers(int n,struct player s[n])
{
    int i=0,count=0;
    char c[20];
    printf("enter the name of country : ");
    scanf("%s",c);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].country,c)==0&&strcmp(s[i].category,"bowler")==0)
        {
            count++;
        }

    }
    printf("the no of bowler of %s are : %d \n",c,count);

}
void avg_batscore(int n,struct player s[n])
{
   int  max;

   char temp[100];
   int tem=0;
   int t=0;
    for (int i = 0; i < n-1; i++)
    {

        max = i;
        for (int j = i+1; j < n; j++)
          if (s[j].average > s[max].average)
            max = j;

tem=s[max].average;
s[max].average=s[i].average;
s[i].average=tem;
  strcpy(temp, s[max].name);
  strcpy(s[max].name,s[i].name);
  strcpy(s[i].name,temp);
t=s[max].age;
s[max].age=s[i].age;
s[i].age=t;
  strcpy(temp, s[max].country);
  strcpy(s[max].country,s[i].country);
  strcpy(s[i].country,temp);
    strcpy(temp, s[max].category);
  strcpy(s[max].category,s[i].category);
  strcpy(s[i].category,temp);
   t=s[max].no_wickets;
s[max].no_wickets=s[i].no_wickets;
s[i].no_wickets=t;
   t=s[max].no_twenty;
   s[max].no_twenty=s[i].no_twenty;
   s[i].no_twenty=t;
   t=s[max].no_ODI;
   s[max].no_ODI=s[i].no_ODI;
   s[i].no_ODI=t;
    }
 printf("----------------------------------------------------------------------\n");
      printf("age ODI twenty wic.  name       country        category      avg batscore \n");
      printf("------------------------------------------------------------------------\n");
  for(int i=0;i<n;i++)
  {
      printf("%d \t%d\t \t%d \t%d \t\t%s \t%s \t%s \t\t%d \n",s[i].age,s[i].no_ODI,s[i].no_twenty,s[i].no_wickets,s[i].name,s[i].country,s[i].category,s[i].average);

  }
      printf("--------------------------------------------------------------------------\n");
}
void maxwicket(int n,struct player s[n])
{
    int max=0,k=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(s[i].category,"bowler")==0 || (strcmp(s[i].category,"all_rounder"))==0)
    {
           if(s[i].no_wickets>max)
           {
               max=s[i].no_wickets;
               k=i;
           }
        }
    }
    printf("the bowler with highest wicket %d is %s \n",s[k].no_wickets,s[k].name);


}
void highscore(int n,struct player s[n])
{

  int max=0,k=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(s[i].category,"bowler")==0 || (strcmp(s[i].category,"all_rounder"))==0)
    {
           if(s[i].average>max)
           {
               max=s[i].average;
               k=i;
           }
        }
    }
    printf("the batsman with highest average score %d is %s \n",s[k].average,s[k].name);



}

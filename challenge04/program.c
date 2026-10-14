#include<stdio.h>
int main(){

float expense;
float smalltotal = 0,mediumtotal = 0,largetotal = 0;
float total=0,average;

int smallcount=0,mediumcount=0,largecount=0;
int validcount=0;
while(1){
printf("ENTER EXPENSE (0 TO STOP) : ");
scanf("%f",&expense);;

if(expense == 0){
  break;
}

else if (expense < 0){
    printf("ENTERED NEGATIVE OR INVALID AMOUNT \n");
     continue;
}

else
{
validcount++;
total = total+expense;
if(expense < 100)
{
smallcount++;
smalltotal = smalltotal+expense;
printf("category:small\n");
}

else if (expense < 500)
{
mediumcount++;
mediumtotal = mediumtotal+expense;
printf("category:medium\n");
}

else
{
    largecount++;
largetotal = largetotal+expense;
printf("category:large\n");
       }
     }
}
printf("number of validexpense : %d\n",validcount);
printf("toatl no of validexpense : %.2f\n",total);
printf("no of small count : %d\n",smallcount);
printf("total no of small expenses : %.2f\n",smalltotal);
printf(" no of medium count : %d\n",mediumcount);
printf("toatl no of medium expenses : %.2f\n",mediumtotal);
printf("no of large count : %d\n",largecount);
printf("total no of  lagre expenses : %.2f\n",largetotal);

if(validcount > 0)
{
average = total / validcount;
printf("average of the valid expense  = ₹ %.2f\n",average);
}
else{
printf("invalid expense has been entered \n ");
}

return 0;

}

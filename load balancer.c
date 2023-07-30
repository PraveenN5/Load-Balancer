#include <stdio.h>
int
no_of_circuits (int n)		//n for number of circuits
{
  float capacity;
  capacity = 19200 / n ;	      /**240 volts X 100 Ampa=24,000 watts
      80 percent of 24,000 watts= 19,200= maximum electric capacity of the house **/
  return capacity;
}
int main()
{
    int x,y,n,q,j,k,b=0,b1,y1,power,a=0,c=0;//x=no of circuits,n=no of devices
    int v,i,hr;
   int temp[x],p[n],sat[x],end[x],totp[x],dev[n];
   int s,e,temp_1,total_power;
   char dev_names[n][100];
    printf("enter number of circuits in a home:");
    scanf("%d",&x);
    printf ("maximun capacity of each circuit is %d KWH\n", no_of_circuits (x));
    printf("enter total no of devices in a home:");
    scanf("%d",&n);
     q=0;
     for(j=0;j<x;j++)
     {
         printf("enter the no of appliances connected to circuit %d:",j+1);
         scanf("%d",&y);
         temp[j]=y;
          b1 = b;
      b = b + y;
      if (n< b)
	{
	  printf
	    (" default error: more number of appliances is connected than the total number of appliances\n");
	  y1 = n - b1;
	  printf ("so you can give only  %d applicances to %d circuit\n", y1,j+1);
		 return 0;
	}
         for(k=0;k<y;k++)
         {
             printf("enter the appliance %d connected to circuit %d:",k+1,j+1);
              scanf ("%s", dev_names[q]);
              printf("enter the volatage consumed by %s connected to %d circuit:",dev_names[q],j+1);
	  scanf("%d",&v);
	   printf("enter the current  consumed by %s connected to %d circuit:",dev_names[q],j+1);
	  scanf("%d",&i);
	   printf("enter the no of hours the appliance  %s is running  connected to %d circuit:",dev_names[q],j+1);
	  scanf("%d",&hr);
	  p[q]=v*hr*i;
	  q++;
         }
     }
     s=0;
   e=temp[0]-1;
   temp_1=0;
   temp[x]=0;
   for(j=0;j<x;j++)
   {
       sat[j]=s;
       end[j]=e;
       for(k=s;k<=e;k++)
       {
           temp_1=temp_1+p[k];
       }
       totp[j]=temp_1;
       s=e+1;
       e=s+temp[j+1]-1;
       temp_1=0;
   }
    for(j=0;j<x;j++)
    {
        printf("the total power of circutit %d is %d \n",j+1,totp[j]);
        if(totp[j]>=no_of_circuits (x))
        {
            printf("the circuit %d is not balanced \n",j+1);
        }
        else
        {
            printf("the circuit %d is  balanced \n",j+1);
            c=c+1;
        }
        temp_1=temp_1+totp[j];
    }
    printf("total power of all circuits is %d \n",temp_1);
    if(c==x)
    {
        printf("the load of the all circuits is balanced\n");
        return 0;
    }
int ptemp,m=0;
     for(j=0;j<x;j++)
     {
     if(totp[j]>=no_of_circuits (x))
     {
         ptemp=p[sat[j]];
         m=sat[j];
         for(k=sat[j];k<=end[j];k++)
         {
             if(p[k]>=ptemp)
             {
                 ptemp=p[k];
                 m=k;
             }
         }
        printf("the device %s is consuming more power in circuit %d",dev_names[m],j+1);
        totp[j]=totp[j]-p[m];
         if(totp[j]<=no_of_circuits (x))
         {
             printf("the new power of the circuit %d is %d\n",j+1,totp[j]);
         }
     }
}
power=totp[0];
for(j=0;j<x;j++)
{
    if(power>=totp[j])
    {
        power=totp[j];
        a=j;
    }
}
printf("the circuit %d is  consuming less power\n",a+1);
totp[a]=totp[a]+p[m];
 if(totp[a]<=no_of_circuits (x))
         {
             printf("\n the new power of the circuit %d is %d\n",a+1,totp[a]);
             printf("the circuit %d is balanced",a+1);
         }
for(j=0;j<x;j++)
{
total_power=total_power+totp[j];
}
if(total_power<=19200)
{
    printf("the total load of  the house is balanced");
}
else
{
    printf("the load of the house is not balanced");
}
return 0;
}
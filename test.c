#include<stdio.h>


int min();
int main()
{
    int i,j,no_of_p,t1,pos,t2,time=0,total,temp,n;


    printf("\nEnter number of programs ? :");
    scanf("%d",&no_of_p);
    n = no_of_p;
    int p[n];
    int arr_time[no_of_p], brt_time[no_of_p],remain_time[no_of_p],wait_time[no_of_p],turn_around[no_of_p];
    for(i=0;i<no_of_p;i++)
    {
        printf("\nEnter Arrival Time of p%d ?: ",i+1);
        scanf("%d",&arr_time[i]);
    }
    for(i=0;i<no_of_p;i++)
    {
        printf("\nEnter Burst Time of p%d ?: ",i+1);
        scanf("%d",&brt_time[i]);
    }

    printf("\nEnter time slice for 1st iteration? :");
    scanf("%d",&t1);
    printf("\nEnter time slice for 2nd iteration? :");
    scanf("%d",&t2);
    
    printf("\nFor the First Iteration with time slice %d", t1);

    for(i=0;i<no_of_p;i++)
    {
        remain_time[i] = brt_time[i];
    }
     for(i=0;i<no_of_p;i++)
     {
         if (remain_time[i]>0 && remain_time[i] <t1)
         {
             time+=remain_time[i];
             remain_time[i]=0;
         }
       else if (remain_time[i]>0)
       {
           time+=t1;
           remain_time[i] -= t1;
       }
       
       if (remain_time[i]>0)
       {
       turn_around[i] = time - arr_time[i];
       if ( turn_around[i] - (brt_time[i]-remain_time[i])>0)
       {wait_time[i] = turn_around[i] - (brt_time[i]-remain_time[i]);}
       else
       {wait_time[i] = 0;}
       
       }    

       if (arr_time[i]>(time-min(brt_time[i-1],t1)))
       {
        
           wait_time[i] = wait_time[i]+1-(t2)-(arr_time[i]-(time-min(brt_time[i-1],t1)));
       }    

       

     }

for (i=0;i<n;i++)
{
    printf("\n The reamining time for process p%d is  %d",i+1,remain_time[i]);
}








printf("\nFor the iteration 2 with time slice %d", t2);


     for(i=0;i<no_of_p;i++)
     {

        
         if (remain_time[i]>0)
       {
           if (i!=0)
            {
                
                    turn_around[i] = turn_around[i-1] + (brt_time[i]-remain_time[i])  ;
                    wait_time[i] += turn_around[i] - (brt_time[i]-remain_time[i]);  
                    
                
              
            }
            else
            {
                turn_around[i] += time - turn_around[no_of_p-1];
                wait_time[i] += turn_around[i] - (brt_time[i]-remain_time[i])+1; 
            }
             
       
       }



         if (remain_time[i]>0 && remain_time[i]<t2)
         {
             time+=remain_time[i];
             remain_time[i]=0;
         }
       else if (remain_time[i]>0)
       {
           time+=t2;
           remain_time[i] -= t2;
       }
       
       

     }


for(i=0;i<n;i++)
{
    wait_time[i] += (n-1-i)*t2;
}

for (i=0;i<n;i++)
{
    printf("\n The reamining time for process p%d is  %d",i+1,remain_time[i]);
}


int wait_time_1[no_of_p],brt_time_1[no_of_p];

for (i=0;i<n;i++)
{
    brt_time_1[i] = remain_time[i];
}

for(i=0;i<n;i++)
    {
		p[i]=i+1;
    }

for(i=0;i<n;i++)
    {
	pos=i;
	for(j=i+1;j<n;j++)
	{
	    if(brt_time_1[j]<brt_time_1[pos])
		pos=j;
	}

	temp=brt_time_1[i];
	brt_time_1[i]=brt_time_1[pos];
	brt_time_1[pos]=temp;

	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
    }

    wait_time_1[0]=0;
    for(i=1;i<n;i++)
    {
	wait_time_1[i]=0;
	for(j=0;j<i;j++)
	    wait_time_1[i]+=brt_time_1[j];
    }

for (i=0;i<n;i++)
{
    wait_time[i] += wait_time_1[p[i]];
}


for (i=0;i<no_of_p;i++)
{
    turn_around[i] = wait_time[i] + brt_time[i];
}



  
 
  for(i=0;i<no_of_p;i++)
  {
      
      printf("\n Turn Around Time for process%d is %d",i+1,turn_around[i]);

      printf("\n Waiting Time for process%d is %d",i+1,wait_time[i]);

      
  }

total = 0;
  for (i = 0; i <n; i++)
  {
      total += wait_time[i];
  }

  printf("\n The Average waiting time is %d", total/n);
  total = 0;
  
for (i = 0; i <n; i++)
  {
      total += turn_around[i];
  }
  printf("\n The Average Turn Around time is %d", total/n);





    return 0;
}


int min(int a, int b)
{
    if (a>b)
    {
        return b;
    }
    else 
    {
        return a;
    }    


}







#include <stdio.h>
#include <stdlib.h>
#include "list.h"

entry item;
List a1,a2,a3,a4;
entry arr[85];

int partition(entry a[],int low,int high)
{
    int pivot=a[high].priority;
    int i=low,j;
    for(j=low;j<high;j++)
    {
        if(a[j].priority<pivot)
        {
            entry temp;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    entry temp=a[high];
    a[high]=a[i];
    a[i]=temp;
    return i;
}

void Quicksort(entry a[],int low,int high)
{
    if(low<high)
    {
        int pivot=partition(a,low,high);
        Quicksort(a,low,pivot-1);
        Quicksort(a,pivot+1,high);

    }
}

int TransferListToArray(entry arr[],int i,List *l)
{
   int j=0;

   while(!isempty(l))
    {
     Delete(l,j,&item);
     arr[i].data=item.data;
     arr[i].priority=item.priority;
     i++;
   }
   return i;
}

void ProcessAllRequests()
{

   int i=0;
   int j=0;

   i=TransferListToArray(arr,i,&a1);
   i=TransferListToArray(arr,i,&a2);
   i=TransferListToArray(arr,i,&a3);
   i=TransferListToArray(arr,i,&a4);

   Quicksort(arr,0,i-1);

   for(int k=0;k<i;k++)
   {
      printf("character: %c priority: %d\n",arr[k].data,arr[k].priority);
   }
}

int main()
{

  createlist(&a1);
  createlist(&a2);
  createlist(&a3);
  createlist(&a4);
  int j,size; entry x,all_list[80];
  while(!isfull(&a1)||!isfull(&a2)||!isfull(&a3)||!isfull(&a4)){
      printf("Enter The data :\n");

            scanf("%c",&x.data);
            printf("Choose The priority\n1-Critical\n2-High\n3-Medium\n4-Low\n");
            scanf("%d",&x.priority);
        if(!isfull(&a1)){
            Insert(&a1,x,ListSize(&a1));
            }
       else if(!isfull(&a2)){
            Insert(&a2,x,ListSize(&a2));
            }
       else if(!isfull(&a3)){
            Insert(&a3,x,ListSize(&a3));
        }
       else if(!isfull(&a4)){
            Insert(&a4,x,ListSize(&a4));
            }
       else{break;}
    printf("1-continue\n2-end\n");
    scanf("%d",&j);
    getchar();
    if(j==2){
        break;
    }
  }
while(1){
     int key;
   printf("enter \n1:search  \n2:empty all lists  \n3:join lists  \n4:update requests Priority\n5:process all requests \n6:Delete\n7:end  \n");
    scanf("%d",&key);
        if(key== 2)
        {
        emptyLists(&a1,&a2,&a3,&a4);
        printf("2\n");
        }
        else if(key== 3)
        {
       join(&a1,&a2,&a3,&a4);
       printf("3\n");
        }
        else if(key== 4)
        {
        entry y;
       printf("Enter The data :\n");
            scanf(" %c",&y.data);
            printf("Enter new priority\n");
            scanf("%d",&y.priority);
            updatePriority(&a1,&a2,&a3,&a4,y.data,y.priority);

        }else if(key== 5)
        {
             printf("\n\n");
             ProcessAllRequests();
        }else if(key==6){
            int listno=0;

            int pos=0;
             printf("choose List to delete from\n1-List1\n2-List2\n3-List3\n4-List4\n");
             scanf("%d",&listno);
             if(listno==1){
                printf("Enter position of character to be deleted\n");
                scanf("%d",&pos);
                Delete(&a1,pos,&item);
             }else if(listno==2){
                 printf("Enter position of character to be deleted\n");
                scanf("%d",&pos);
                Delete(&a2,pos,&item);
             }else if(listno==3){
                 printf("Enter position of character to be deleted\n");
                scanf("%d",&pos);
                Delete(&a3,pos,&item);
             }else if(listno==4){
                printf("Enter position of character to be deleted\n");
                scanf("%d",&pos);
                Delete(&a4,pos,&item);
             }
        }
        else if(key== 7)
        {
             return 0;
        }
       else if(key== 1)
        {
       size=a1.Size+a2.Size+a3.Size+a4.Size;
       int Searchkey;
       printf("enter \n1:search data  \n2:search priority  \n3:search both  \n");
       scanf("%d",&Searchkey);
        if(Searchkey== 1)
        {
        //for data
        sortAllLists(all_list,&a1,&a2,&a3,&a4,1);
        printf("enter data that you want to search for it \n");
        scanf(" %c",&x.data);
        binary_search(1,x.priority,x.data,all_list,size);
        }
        else if(Searchkey== 2)
        {
        //for priority
        sortAllLists(all_list,&a1,&a2,&a3,&a4,0);
        printf("enter priority that you want to search for it \n");
        scanf("%d",&x.priority);
        binary_search(3,x.priority,x.data,all_list,size);
        }
        else if(Searchkey== 3)
        {
        //for both
        sortAllLists(all_list,&a1,&a2,&a3,&a4,1);
        printf("enter data and priority that you want to search for it \n");
        scanf(" %c %d",&x.data,&x.priority);
        binary_search(2,x.priority,x.data,all_list,size);
        }
        else{break;}
        }
   }

    return 0;
}

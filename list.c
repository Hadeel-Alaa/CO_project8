#include "list.h"
#include <stdio.h>
#include <stdlib.h>
void createlist(List *l){
   l->Size=0;
}

int isfull(List *l){
  return l->Size==MAX;
}

int isempty(List *l){
  return l->Size==0;
}
void Insert(List *l,entry item,int position){
    if(!isfull(l)){
        int i;
        for(i=l->Size-1;i>=position;i--){
      l->arr[i+1]=l->arr[i];
    }
    l->arr[position]=item;
    l->Size++;
    }else{
      printf("list is full\n");
    }
}
void Delete(List *l,int p,entry *e){
  if(!isempty(l)){
    *e=l->arr[p];
    int i;
    for(i=p;i<l->Size;i++){
      l->arr[i]=l->arr[i+1];
    }

    l->Size--;
  }else{
    printf("list is empty\n");
  }
}
void destroy(List *l){
   l->Size=0;
}

void emptyLists(List *l1,List *l2,List *l3 ,List *l4){
    destroy(l1);
    destroy(l2);
    destroy(l3);
    destroy(l4);
}

int ListSize(List *l){
  return l->Size;
}


void join(List *l1,List *l2,List *l3,List *l4){
entry x;
while(l3->Size<MAX&&(l4->Size>0)){
    Delete(l4,0,&x);
    Insert(l3,x,l3->Size);
}
while(l2->Size<MAX&&(l3->Size>0)){
    Delete(l3,0,&x);
    Insert(l2,x,l2->Size);
}
while(l1->Size<MAX&&(l2->Size>0)){
    Delete(l2,0,&x);
    Insert(l1,x,l1->Size);
}
}
///////

//////////////////////////////////binary search///////////////////////////////////////////////////////////////
void binary_search(int req,int prior,char item,entry a[],int size)
{
    if(req==1||req==3)
    {
        /////////////search in data///////////////
        int lift,right,mid,begin,endd;
        lift=0;
        right=size;
        //////////search for the last element///////////
        while(lift<right)
        {
            mid=(lift+right)/2;
            if(a[mid].data > item)
            {
                right=mid;
            }else
            {
                lift=mid+1;
            }
        }
        endd=right-1;
        /////////////end////////////////
        lift=0;
        right=size;
        ///////////////search for first element////////////////////
        while(lift<right)
        {
            mid=(lift+right+1)/2;
            if(a[mid].data < item)
            {
                lift=mid;
            }else
            {
                right=mid-1;
            }
        }
        if(lift==0)
            begin=right;
        else
            begin=right+1;
        //////////////////end///////////////////
        if(req==1)
        {
        	//////////////////print all elemnt that equal to item/////////////////////
        	int i;
            for(i=begin;i<=endd;i++)
            {
                printf("%c priority is : %d\n",item,a[i].priority);
            }
            /////////////////////end///////////////////////////
        }else
        {
        	////////////////////////to print search in both//////////////////////////
        	int i;
            for(i=begin;i<=endd;i++)
            {
                if(a[i].priority==prior)
                {
                    printf("char that priority equal to %d is : %c\n",prior,a[i].data);
                }
            }
            ////////////////////////////end//////////////////////
        }
    }else
    {
        ///////////////search in priorty///////////
        int lift,right,mid,begin,endd;
        lift=0;
        right=size;
        ///////////////////search for last element//////////////////
        while(lift<right)
        {
            mid=(lift+right)/2;
            if(a[mid].priority > prior)
            {
                right=mid;
            }else
            {
                lift=mid+1;
            }
        }
        endd=right-1;
        ///////////////////////end////////////////////
        lift=0;
        right=size;
        ////////////////////search for first element//////////////
        while(lift<right)
        {
            mid=(lift+right+1)/2;
            if(a[mid].priority < prior)
            {
                lift=mid;
            }else
            {
                right=mid-1;
            }
        }
        if(lift==0)
            begin=right;
        else
            begin=right+1;
        ///////////////////////////////////end//////////////////
        //////////////print all element that priority equal to prior///////////////////
        int i;
        for(i=begin;i<=endd;i++)
        {
                printf("char that priority equal to %d is : %c\n",prior,a[i].data);
        }
    }
}
    //*************************************************START LOOPING ON LISTS*******************************************************

void loopingLists(List *l,char req,int newp){
    for(int i=0;i<l->Size;i++){
        if(l->arr[i].data==req){
            l->arr[i].priority= newp;
        }
    }
}

//************************************************* END LOOPING ON LISTS********************************************************

//******************************************** START UPDATE PRIORITY FUNCTION***************************************************

void updatePriority(List *l1,List *l2,List *l3,List *l4,char req,int newP){
    if(!isempty(l1))
        loopingLists(l1,req, newP);
    if(!isempty(l2))
        loopingLists(l2,req,newP);
    if(!isempty(l3))
        loopingLists(l3,req,newP);
    if(!isempty(l4))
        loopingLists(l4,req,newP);
}

//******************************************** END UPDATE PRIORITY FUNCTION***************************************************



///////////////////////////////////sort//////////////////////////////////////////////////////////////
int partitions(List *l,int low,int high, int sortBy)
{
    char pivot=(*l).arr[low].data;
    int pivot1;
    if(sortBy==0)
        pivot1=(*l).arr[low].priority;


    int i=low+1,j;
    for(j=low+1; j<=high; j++)
    {
        if(sortBy==0)
        {
            if((*l).arr[j].priority<pivot1)
            {
                entry temp;
                temp= (*l).arr[j];
                (*l).arr[j]= (*l).arr[i];
                (*l).arr[i]= temp;
                i++;
            }
        }
        else
        {
            if((*l).arr[j].data<pivot)
            {
                entry temp;
                temp= (*l).arr[j];
                (*l).arr[j]= (*l).arr[i];
                (*l).arr[i]= temp;
                i++;
            }
        }
    }

    entry temp= (*l).arr[low];
    (*l).arr[low]= (*l).arr[i-1];
    (*l).arr[i-1]= temp;
    return i-1;
}
void quicksort(List *l,int low,int high,int sortBy)
{
    if(low<high)
    {
        int pivot=partitions(l,low,high,sortBy);
        quicksort(l,low,pivot-1,sortBy);
        quicksort(l,pivot+1,high,sortBy);
    }
}


void sortAllLists(entry a[],List *l1,List *l2,List *l3,List *l4,int sortBy)
{

    int j=0;
    for(int i=0; i<(*l1).Size; i++)
    {
        a[j]=(*l1).arr[i];
        j++;
    }
    for(int i=0; i<(*l2).Size; i++)
    {
        a[j]=(*l2).arr[i];
        j++;
    }
    for(int i=0; i<(*l3).Size; i++)
    {
        a[j]=(*l3).arr[i];
        j++;
    }
    for(int i=0; i<(*l4).Size; i++)
    {
        a[j]=(*l4).arr[i];
        j++;
    }

    quicksort(a,0,((*l1).Size+(*l2).Size+(*l3).Size+(*l4).Size)-1,sortBy);
}
////////////////////////////////////////////end////////////////////////////////////////////////


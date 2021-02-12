
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define MAX 20
typedef struct
{
    int priority;
    char data;

} entry;

typedef struct
{
    entry arr[MAX];
    int Size;

} List;
void createlist(List *l);
int isfull(List *l);
int isempty(List *l);
void Insert(List *l,entry item,int position); //can insert till current size as there should not be holes in list
void Delete(List *l,int p,entry *e);
void destroy(List *l);
void emptyLists(List *l1,List *l2,List *l3 ,List *l4);
int ListSize(List *l);
void join (List *l1,List *l2,List *l3,List *l4);
void binary_search(int req,int prior,char item,entry a[],int size);
void loopingLists(List *l,char req,int newp);
void updatePriority(List *l1,List *l2,List *l3,List *l4,char req,int newP);
int partitions(List *l,int low,int high, int sortBy);
void quicksort(List *l,int low,int high,int sortBy);
void sortAllLists(entry a[],List *l1,List *l2,List *l3,List *l4,int sortBy);
#endif // LIST_H_INCLUDED

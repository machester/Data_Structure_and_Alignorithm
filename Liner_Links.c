
#include <stdio.h>
#include <stdlib.h>


typedef enum {
    False = 0,
    True = !False
}status;

struct student{
    int ID;
    char name[20];
    double score;

}students;

typedef struct NodeDef{
    struct student item;
    //int item;
    struct Node *next;
}Node;

Node *nodeList;

void CreatList(Node **nodeHeard, int length);
void ShowList(Node *pList);
void ClearList(Node **pList);
void InsertList(Node **pList, int i);

void InsertList(Node **pList, int i)
{
    struct student *st;
}

void CreatList(Node **nodeHeard, int length)
{
    Node *p;
    Node *t;
    int i;

    *nodeHeard = (Node *)malloc(sizeof(Node));      //init list heard
    t = *nodeHeard;
    if(NULL == t)
        return;
    printf("Inpput format: ID\t name\t score\t\n");
    for(i = 0; i < length; i++)
    {
        p = (Node *)malloc(sizeof(Node));

        scanf("%d", &(p ->item.ID));
        scanf("%s", &(p ->item.name));
        scanf("%lf", &(p ->item.score));

        t ->next = p;
        t = p;
    }
    t ->next = NULL;            //list end
}
void ShowList(Node *pList)
{
   int i;
   Node *p;

   p = pList ->next;        //get heard address
   i = 1;
   if(NULL == p)
       printf("list is empty.\n");
   while (NULL != p)        // list not empty.
   {
       printf("%d:  ID: %d,     name: %s,       score: %5.2lf\n",\
       i, p->item.ID, p ->item.name, p ->item.score);

       p = p ->next;
       ++i;
   }
}
void ClearList(Node **pList)
{
    Node *temp, *q;
    temp = *pList;

    if(NULL == temp->next)              //heard is empty.
        printf("list has been clearned.");
    else
    {
        while (NULL != temp)            //heard nont empty
        {
            q = temp ->next;
            free(temp);
            temp = NULL;
            temp = q;
        }
        // set heard to empty
        temp = *pList;
        temp ->next = NULL;
    }

}

int main()
{

    int selection = 0;
    int parts = 0;
    int length;
    status breakFlag = False;
    printf("Plese select:\n");
    while(1)
    {
        printf("1.Input:    2.Show List:   3.Search:        4.Insert\n");
        printf("5.Insert:   6.Sort         7.Delete List    8.Quit\n");

        scanf("%d", &selection);
        switch (selection) {
            case 1:
                printf("input parts:");
                scanf("%d", &parts);
                CreatList(&nodeList, parts);
                break;
            case 2:
                ShowList(nodeList);
                break;
            case 3:
                printf("Reserved\n");
                break;
            case 4:

                InsertList(&nodeList, 0);
                printf("Reserved\n");
                break;
            case 5:
                printf("Reserved\n");
                break;
            case 6:
                printf("Reserved\n");
                break;
            case 7:
                ClearList(&nodeList);
                break;
            case 8:
                exit(0);
            default:
                printf("\n/---- Select error. -----/\n");
                break;
        }
        if (True == breakFlag)
            break;
    }
}


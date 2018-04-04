#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    False = 0,
    True = !False
}status;

typedef struct{
    int ID;
    char name[20];
    double score;
}students;

//liner linked list
struct NodeList{
    int *p;
    students *NodeData;
    struct Node *nextNode;
}*nodeList;

void SantexInput(students *pStdList);
void DataCheck(students *pStdList);
status _F_Quit(void);


int parts;

int main(void)
{
    int selection = 0;
    parts = 0;
    status breakFlag = False;
    students *pStdList;

    printf("Plese select:\n");
    while(1)
    {
        printf("1.Input\t 2.Check\t 3.Quit\n");
        printf("4.Delete Data\t 5.Serach Data\t 6.SoratData\t 7.ChangeData\n");

        scanf("%d", &selection);
        switch(selection)
        {
            case 1:
                printf("input parts:");
                scanf("%d", &parts);
                pStdList = (students *)malloc \
					     (sizeof(students) * parts);
                if(NULL == pStdList)
                {
                    exit(1);
                }
                SantexInput(pStdList);
                break;
            case 2:
                DataCheck(pStdList);
                break;
            case 3:
                breakFlag = _F_Quit();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                printf("\n/---- Select error. -----/\n");
                break;
        }
        if(True == breakFlag)
            break;
    }
    free(pStdList);
    printf("\n/------------- EXTI SUCCESS ---------------/\n");
    return 0;
}


void SantexInput(students *pStdList)
{
    int i;

    printf("Input format: \nID\t name\t score\n");
    for(i = 0; i < parts; i++)
    {
        scanf("%d", &((pStdList + i)->ID));
        scanf("%s", &((pStdList + i)->name));
        scanf("%lf", &((pStdList + i)->score));
    }
    printf("\n/---- Input Accepted. ----/\n");
}
void DataCheck(students *pStdList)
{
    int i;

    if(0 == parts)
        printf("\nDatabase is empty.\n");
    else
    {
        printf("Data List:\n");
        for(i = 0; i < parts; i++)
        {
            printf("%d. ID: %d\t name:%s\t score: %4.2f\n", (i+1), \
		    (pStdList + i) ->ID, \
		    (pStdList + i) ->name, \
		    (pStdList + i) ->score);
        }
        printf("\n/----- Data check completed. ----/\n");
    }
}
status _F_Quit(void)
{
    return True;
}

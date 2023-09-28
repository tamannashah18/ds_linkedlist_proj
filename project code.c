#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int not=1,cnt1=0,cnt2=0,avt;
struct train{
    char pnr[11];
    char name[20];
     int nac,ac2,ac3;
    int arr,dep,avt;
}t1[5];
struct node
{
    struct pass
    {
        char name[10];
        int age;
        int des;
        int class;
        char pnr[11];
    }p;
struct node *next;
}*f1,*l1,*nn,*t,*f2,*l2;

void trainread(int a)
{
    FILE *f;
    int i=0;
    f=fopen("train.txt","r");
        while(fread(&t1[i],sizeof(struct train),1,f))
        {
            if(i==a)
            {
                printf("PNR %s\n",t1[i].pnr);
                printf("NAME %s\n",t1[i].name);
                printf("Amt NON OF AC CLASS %d\n",t1[i].nac);
                printf("Amt OF 2 tier AC CLASS %d\n",t1[i].ac2);
                printf("Amt OF 3 tier AC CLASS %d\n",t1[i].ac3);
                printf("ARRIVAL TIME %d hours\n",t1[i].arr);
                printf("DEPARTURE TIME %d hours\n", t1[i].dep);
                printf("AVAILABILITY %d\n",t1[i].avt);
            }
            i++;
        }
    fclose(f);
}
void trains()
{
    if(nn->p.des==1)
    {
        
        trainread(1);
    }   
    else
    if(nn->p.des==2)
    {
        trainread(2);
    }
    else
    printf("INAVILD DESTINATION");        
}
void pass()
{
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter passenger name\n");
    scanf("%s",nn->p.name);
    printf("Enter passenger age\n");
    scanf("%d",&nn->p.age);
	printf("SELECT destination:\n");
	printf("Enter 1 for surat to mumbai\n");
	printf("Enter 2 for mumbai to baroda\n");
	printf("Enter 3 for jaipur to baroda\n");
	printf("Enter 4 for mumbai to delhi\n");
    scanf("%d",&nn->p.des);
    printf("Enter passenger class\n");
    scanf("%d",&nn->p.class);
}
void insert(int a)
{
    if(t1[a].avt>0)
    {
        strcpy(nn->p.pnr,t1[a].pnr);
        switch(a+1)
        {
        case 1:
            if(f1==NULL)
            {
                f1=nn;
            }
            else
            {
                l1->next=nn;
            }
            l1=nn;
            cnt1++;
            break;
        case 2:
            if(f2==NULL)
            {
                f2=nn;
            }
            else
                {
                    l1->next=nn;
                }
                l2=nn;
                cnt2++;
            break;
        }
    }
}
void display(int a)
{
    switch(a)
    {
        case 1:
            t=f1;
            printf("PNR\t\tName\t\tAge\t\tDestination\t\tClass\n");
            while(t!=l1)
            {
                printf("%s %s %d %d %d \n",t->p.pnr,t->p.name,t->p.age,t->p.des,t->p.class);
                t=t->next;
            }
            printf("%s %s %d %d %d \n",t->p.pnr,t->p.name,t->p.age,t->p.des,t->p.class);
            break;
        case 2:
            t=f2;
            printf("PNR\t\tName\t\tAge\t\tDestination\t\tClass\n");
            while(t!=l2)
            {
                printf("%s %s %d %d %d \n",t->p.pnr,t->p.name,t->p.age,t->p.des,t->p.class);
                t=t->next;
            }
            printf("%s %s %d %d %d \n",t->p.pnr,t->p.name,t->p.age,t->p.des,t->p.class);

            break;
        default:
        printf("INVAILD INPUT\n");
        break;
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\nENTER 1 to Add new passenger details\n");
        printf("ENTER 2 to View passenger details\n");
        printf("ENTER 3 to Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                pass();
                trains();
                printf("ENTER 1 to book in train 1\n");
                printf("ENTER 2 to book in train 2\n");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                    insert(0);
                    break;
                    case 2:
                    insert(1);
                    break;
                    default:
                    printf("INVALID VALUE\n");
                    break;
                }
                break;
            case 2:
                printf("ENTER 1 to VIEW bookings in train 1\n");
                printf("ENTER 2 to VIEW bookings in train 2\n");
                printf("ENTER 4 to VIEW bookings in all trains \n");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                    display(1);
                    break;
                    case 2:
                    display(2);
                    break;
                    case 3:
                    display(0);
                    break;
                    default:
                    printf("INVALID VALUE\n");
                    break;
                }
                break;
        }
    }
}
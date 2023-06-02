#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 25

struct playlist
{
	char songName[MAXSIZE];	        //data members of a dll
	char singerName[MAXSIZE];
	float songSize;
	char movieName[MAXSIZE];

	struct playlist *next;		//Link part of dll
	struct playlist *prev;
};
typedef struct playlist *NODE;

//Function prototypes
NODE getnewnode_dll();
NODE insert_end_dll(NODE);
NODE insert_after_dll(NODE, char[]);
NODE delete_specific_dll(NODE, char[]);
void display_dll(NODE);

int main()
{
	NODE head=NULL;
	int i,n;
	char song[	MAXSIZE], deletesong[MAXSIZE];
	printf("Enter number of songs\n");
	scanf("%d", &n);
	if(n<=1)
        printf("Meera cannot create playlist.");
    else
    {
        for(i=0;i<n;i++)
            head=insert_end_dll(head);
        display_dll(head);
        printf("Enter song name afer which to add new song\n");
        scanf("%s",song);
        head=insert_after_dll(head, song);
        display_dll(head);
        printf("Enter song name to delete\n");
        scanf("%s", deletesong);
         head = delete_specific_dll(head, deletesong);
        printf("Songs in Playlist\n");
        display_dll(head);
    }
	return 0;
}

NODE getnewnode_dll()
 {
	NODE newnode = (NODE)malloc(sizeof(struct playlist));
	if(newnode==NULL)
	{
		printf("Song not created\n");
		exit(0);
	}
	printf("Enter the song details:\n");
	printf("Song name, Singer name, Size in MB, Movie name\n");
	scanf("%s%s%f%s",newnode->songName, newnode->singerName,&newnode->songSize,newnode->movieName);
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

NODE insert_end_dll(NODE head)
{
    NODE cur = head;
	NODE newnode = getnewnode_dll();
	if(head == NULL)
            head = newnode;
	else
	{
		while(cur -> next != NULL)
			cur = cur -> next;
        cur -> next = newnode;
        newnode -> prev = cur;
	}
	return head;
}

//DLLinsertAfter() function definition
NODE insert_after_dll(NODE head, char song[MAXSIZE])
{
	NODE newnode = getnewnode_dll();
	NODE cur = head, back=NULL;
	if(head == NULL)
	{
		printf("Adding song is not possible as the play list is empty\n");
	}
	else
    {
        while(cur != NULL) // traverse till specified song.
        {
            if(strcmp(cur -> songName,song)==0)
                break;
            back=cur;
            cur=cur->next;
        }
        //one time shift to next node.
        back=cur;
        cur=cur->next;
        //after shifting, if reached end of list, cur becomes NULL and back points to last node.
        if(cur==NULL && strcmp(back -> songName,song)==0)
        {
            back->next=newnode;
            newnode->prev=back;
        }
        else if(cur != NULL) // intermediate song node.
        {
            back->next = newnode;
            newnode->prev = back;
            newnode->next = cur;
            cur->prev = newnode;
        }
        else // song not present.
            printf("Song not found\n");
    }
	return head;
}

NODE delete_specific_dll(NODE head, char deletesong[MAXSIZE])
{
    NODE cur=head,back=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if(head->next==NULL)
    {
        if(strcmp(head->songName,deletesong)==0)
            {
                printf("Deleted %s\n",head->songName);
                free(head);
                head=NULL;
                return head;
            }
     }
     if(head->next!=NULL)
     {
        if(strcmp(head->songName,deletesong)==0)
            {
                NODE temp=head;
                head=head->next;
                printf("Deleted %s\n",temp->songName);
                free(temp);
                return head;
            }
        }
        while(cur->next!=NULL)
        {
            if(strcmp(cur->songName,deletesong)==0)
                break;
            back=cur;
            cur=cur->next;
        }
        if(cur->next==NULL)
        {
           if(strcmp(cur->songName,deletesong)==0)
            {
                back->next=NULL;
                printf("Deleted %s\n",cur->songName);
                free(cur);
                return head;
            }
            else
            {
                printf("Song not found!!unable to delete\n");
                return head;
            }
        }
        else
        {
            back->next=cur->next;
            cur->next->prev=back;
            printf("Deleted %s\n",cur->songName);
             free(cur);
            return head;
        }
}

//DLLdiplayList() function

void display_dll(NODE head)
{
	NODE cur = head;
	if(head == NULL)
		printf("\nMusic playist is Empty.\n");
	else
	{
		printf("\nSongs are\n");
		while(cur != NULL)
		{
            printf("%s %s %s %0.2f\n", cur->songName, cur->singerName,cur->movieName, cur->songSize);
            cur = cur->next;
		}
	}
}

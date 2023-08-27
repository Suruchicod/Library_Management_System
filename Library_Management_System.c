#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// storing user info

struct cred
{

    char name[30];
    char designation[20];
    int id;
    int bookid[5];
    struct cred *next;
};

typedef struct cred node;

// storing books info
struct books
{

    char name[30];
    char author[40];
    int copies;
    char genre[40];
    int id;
    struct books *next;
};
typedef struct books book;

// Structure to store genre information
typedef struct
{
    float num;
    char genrename;
} Genre;

node *credentials()
{

    node *head, *p;
    int i;

    head = (node *)malloc(sizeof(node));
    printf("Enter your name:\n");
    getchar();
    fgets(head->name,sizeof(head->name),stdin);
    //scanf("%s", head->name);
    printf("Enter your designation: \n");
    scanf("%s", head->designation);
    printf("Enter your id:\n");
    scanf("%d", &head->id);
    for ( i = 0; i < 5; i++)
    {

        head->bookid[i] = 0;
    }

    return (head);
}
struct Feedback {
    char name[50];
    int rating;
    char comment[100];
};
void displayFeedback(struct Feedback feedback) {
	feedback.name[strlen(feedback.name) - 1] = '\0';
    printf("\nName: %s\n", feedback.name);
    printf("Rating: %d\n", feedback.rating);
    printf("Comment: %s\n", feedback.comment);
}
void feedback() {
    struct Feedback feedback;
    
    printf("Feedback Form\n");
    printf("=============\n");
    
    printf("Enter your name: ");
    getchar();
    fgets(feedback.name, sizeof(feedback.name), stdin);
    
    //scanf("%s",feedback.name);
    
    printf("Enter your rating (1-5): ");
    scanf("%d", &feedback.rating);
    
    printf("Enter your comment (max 100 characters): ");    // Clear the newline character from the input buffer
    getchar(); 
    fgets(feedback.comment, sizeof(feedback.comment), stdin);
    
    
    printf("\nThank you for your feedback!\n");      // Display the feedback
    printf("============================\n");
    displayFeedback(feedback);
    
}
// storing book info
book *prebook()
{

    book *head, *p;
    int n,i;
    printf("Enter the number of books you want to store:\n");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {

        if (i == 0)
        {

            head = (book *)malloc(sizeof(book));
            printf("Enter the name of the book:");
			getchar();
            fgets(head->name,sizeof(head->name),stdin);
            //scanf("%s", head->name);
            printf("Enter the name of author:");
            getchar();
            fgets(head->author,sizeof(head->author),stdin);
            //scanf("%s", head->author);
            printf("Enter the number of copies:");
            scanf("%d", &head->copies);
            printf("Enter the genre:");
            scanf("%s", head->genre);
            printf("Enter the id of the book:");
            scanf("%d", &head->id);
            p = head;
        }
        else
        {

            p->next = (book *)malloc(sizeof(book));
            p = p->next;
            printf("Enter the name of the book: ");
            getchar();
            fgets(p->name,sizeof(p->name),stdin);
            //scanf("%s", p->name);
            printf("Enter the name of author: ");
            getchar();
            fgets(p->author,sizeof(p->author),stdin);
            //scanf("%s", p->author);
            printf("Enter the number of copies: ");
            scanf("%d", &p->copies);
            printf("Enter the genre: ");
            scanf("%s", p->genre);
            printf("Enter the id of the book: ");
            scanf("%d", &p->id);
        }
    }
    return (head);
}
// displaying all the books
void displaybook(book *head)
{

    book *p;
    p = head;
    int count = 0;
    while (p != NULL)
    {
    	p->name[strlen(p->name) - 1] = '\0';
    	p->author[strlen(p->author) - 1] = '\0';
        printf("%d) Name:%s Author:%s No of copies:%d Genre:%s BookID:%d\n", count + 1, p->name, p->author, p->copies, p->genre, p->id);
        p = p->next;
        count++;
    }
}

// display all the genres
void genrebook(book *head)
{

    book *p;
    p = head;
    int count = 0;
    char n[40];
    printf("Enter the genre: \n");
    scanf("%s", n);
    while (p != NULL)
    {

        if (strcmp((p->genre),n) == 0)
        {

            printf("%d) Name:%s Author:%s No of copies:%d Genre:%s \n", count + 1, p->name, p->author, p->copies, p->genre);
        }
        p = p->next;
    }
}

// display user info

void userinfo(node *head, book *books)
{

    node *p;
    p = head;
    book *q;
    q = books;
    int count = 0,i;
    while (p != NULL)
    {

        printf("\n======================================\n");
        p->name[strlen(p->name) - 1] = '\0';
        printf("%d) Name:%s | Designation:%s | User ID:%d \n", count + 1, p->name, p->designation, p->id);
        printf("\nIssued Books:\n");
        for (i = 0; i < 5; i++)
        {

            while (q != NULL)
            {

                if (q->id == p->bookid[i])
                {

                    printf("\n>%s by %s ID:%d\n", q->name, q->author,q->id);
                }
                q = q->next;
            }
            q = books;
        }
        p = p->next;
        printf("\n======================================\n");
    }
}
void search(node *head,book *books)
{
	char s1[40];
	printf("Enter the genre you want to search: \n");
	scanf("%s",s1);
	node *p;
	p = head;
    book *q;
    q = books;
    int count = 0,i;
    if(strcmp(s1,(q->genre))==0)
    {
    while (p != NULL)
    {

        for (i = 0; i < 5; i++)
        {

            while (q != NULL)
            {

                if (q->id == p->bookid[i])
                {

                    printf("\n>Genre: %s\n", q->genre);
                    printf("\nBooks:\n%s\n",q->name);
                }
                q = q->next;
            }
            q = books;
        }
        p = p->next;}
     //   printf("\n======================================\n");
    }
}

// Book issue
void issue(node **head, book **books)
{

    node *p;
    book *q;
    int count, i = 0,count3=0;
    int idu;
    int idb;
    p = *head;

    q = *books;
    int count1 = 0, count2 = 0;
    printf("Please Enter your user id: \n");
    scanf("%d", &idu);
    printf("Enter the id of the book: \n");
    scanf("%d", &idb);

    while (p != NULL)
    {

        if (p->id == idu)
        {
            for (; i < 5; i++)
            {

                if (p->bookid[i] == 0)
                {
  		    count3=1;
                    break;
                }
            }
	if(count3==1){
            while (q != NULL)
            {

                if (q->id == idb)
                {
		  if(q->copies!=0){
                    q->copies = q->copies - 1;
                    p->bookid[i] = q->id;
                    count1 = 1;
                    }
                }
                q = q->next;
            }
            }
            count2 = 1;
            break;
        }
        p = p->next;
    }
    if (count2 == 0)
    {

        printf("You need to register you credentials first to issue a book\n");
    }
    else if (count3 == 0)
    {

        printf("You cannot issue more than 5 books\n");
    }
    else if (count1 ==0) printf("You have entered the wrong book title or there is no more copies of the book");
    else
     printf("You have successfully issued a book\n");
}

// for adding new user info

node *concatenate(node *head1, node *head2)
{

    node *p = head1;
    node *q = head2;
    int count = 1;

    while (p->next != NULL)
    {

        count++;
        p = p->next;
    }
    p->next = q;
    while (p != NULL)
    {

        count++;
        p = p->next;
    }

    return (head1);
}
// returning book
void bookreturn(node **head1, book **head2)
{

    int n, m, count1 = 0, count2 = 0,i;
    node *p;
    book *q;
    p = *head1;
    q = *head2;
    printf("Enter your id: \n");
    scanf("%d", &n);
    while (p != NULL)
    {

        if (p->id == n)
        {

            printf("Enter the id of the book: \n");
            scanf("%d", &m);
            for (i = 0; i < 5 ; i++)
            {
               if(p->bookid[i] == m){
                while (q != NULL)
                {

                    if (q->id == m)
                    {

                        q->copies = q->copies + 1;
                        p->bookid[i] = 0;
                        count2 = 1;
                    }
                    q = q->next;
                }
                printf("Return Successful!\n");
            }
            count1 = 1;
            if (count2==1) break;
            }
        }
        
        p = p->next;
        if(count1==1) break;
        
        
    }
    if (count1 == 0)
        printf("First register your id to the system\n");
    else if (count2 == 0)
        printf("Wrong book id please try again\n");
}
void allgenre(book *head){

	book *q,*r;
	q=head;
	r=q->next;
	int count=0;
	while(r!=NULL){

		
		if(count==0) {
		if(strcmp((q->genre),(r->genre))!=0){
			printf("%s",q->genre);
			printf("%s",r->genre);
			}
		else{
			printf("%s",q->genre);
		}
		count++;
}

		else{
			if(strcmp((q->genre),(r->genre))!=0){
			printf("%s",r->genre);
}	

		}

	q=q->next;
	r=r->next;
		}
	
		

}

int main()
{

    node *head, *headc, *head3;
    book *head2;
    int n;
    printf("========================\n");
    printf("\nWelcome to Our Library\n");
    printf("\n========================\n");
   // char b;
    /*Genre genres[] = {
       {1, "Fiction"},
       {2, "Mystery"},
       {3, "Maths"},
       {4, "Science Fiction"},
       {5, "Thriller"},
       {6, "Science"},
       {6.1, "Physics"},
       {6.2, "Chemistry"},
       {7, "History"},
       {8, "Biography"},
       {9, "Self-Help"}
   };*/
    head2 = prebook();
    head = credentials();

    userinfo(head, head2);
    for (;;)
    {
    	char b;
        printf("\nEnter\n1.See all the books\n2.Enter new credentials\n3.Issue books\n4.Genre search\n5.View credentials\n6.Return book\n7.Give Feedback\n8.Exit the program\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:

            displaybook(head2);
            break;

        case 2:

            head3 = credentials();
            headc = concatenate(head, head3);
            head = headc;
            break;

        case 3:

            issue(&head, &head2);
            break;

        case 4:
            genrebook(head2);
            break;

        case 5:

            userinfo(head, head2);
            break;
        case 6:
            bookreturn(&head, &head2);
            break;
        case 7:
		
	        feedback();
			break;    
        case 8:
        	printf("\n************\n");
            printf("\nThank you!\n");
            //exit();
            goto end;
            break;

        default:

            break;
        }//break;
    }
    end:
   return 0; 
}


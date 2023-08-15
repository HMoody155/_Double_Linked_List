#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned char uint8;
typedef unsigned short uint16;

typedef struct Node
{
    struct Node *LeftNodeLink;
    struct Node *RightNodeLink;
    uint32 NodeData;
}Node_t;

void Insert_Node_At_Begining(struct Node **List);
void Insert_Node_At_End(struct Node **List);
void Insert_Node_After(struct Node *List);
void Insert_Node_Before(struct Node **List);
void Delete_Node_At_Begining(struct Node **List);
void Delete_Node_At_End(struct Node *List);
void Delete_Node_At_Intermediate(struct Node *List);
void Display_All_Nodes_Forward(struct Node *List);
void Display_All_Nodes_Reverse(struct Node *List);
uint32 Get_Length(struct Node *List);

struct Node *ListHead = NULL;

int main()
{
    uint32 UserChoic = 0;
    uint32 Length = 0;
    while (1)
    {
        printf("Hello in Double Linked List\n");
        printf("============================================\n");
        printf("(1) => Insert_Node_At_Begining\n");
        printf("(2) => Insert_Node_At_End\n");
        printf("(3) => Insert_Node_After\n");
        printf("(4) => Insert_Node_Before\n");
        printf("(5) => Delete_Node_At_Begining\n");
        printf("(6) => Delete_Node_At_End\n");
        printf("(7) => Delete_Node_At_Intermediate\n");
        printf("(8) => Display_All_Nodes_Forward\n");
        printf("(9) => Display_All_Nodes_Reverse\n");
        printf("(10) => Get_Length\n");
        printf("(11) => Exit Program\n");
        printf("============================================\n");
        
        printf("Enter Choice: ");
        scanf("%i", &UserChoic);
        
        switch (UserChoic)
        {
        case 1:
            Insert_Node_At_Begining(&ListHead);
        break;
        case 2:
            Insert_Node_At_End(&ListHead);
        break;
        case 3:
            Insert_Node_After(ListHead);
        break;
        case 4:
            Insert_Node_Before(&ListHead);
        break;
        case 5:
            Delete_Node_At_Begining(&ListHead);
        break;
        case 6:
            Delete_Node_At_End(ListHead);
        break;
        case 7:
            Delete_Node_At_Intermediate(ListHead);
        break;
        case 8:
            Display_All_Nodes_Forward(ListHead);
        break;
        case 9:
            Display_All_Nodes_Reverse(ListHead);
        break;
        case 10:
           Length = Get_Length(ListHead);
           printf("List Length: ");
           printf("%i", Length);
        break;
        case 11:
            printf("Exit From Program\n");
            exit(1);
        break;
        
        default:
            printf("Invalid User Choice\n");
        break;
        }

        printf("\n");
    }
    
    return 0;
}

void Insert_Node_At_Begining(struct Node **List)
{
    struct Node *TempNode = NULL;

    TempNode = (struct Node *)malloc((sizeof(struct Node)));
    if (TempNode)
    {
        printf("Enter Data: ");
        scanf("%i", &(TempNode->NodeData));
        TempNode->LeftNodeLink = NULL;

        if (!*List)
        {
            *List = TempNode;
            TempNode->RightNodeLink = NULL;
        }
        else
        {
            TempNode->RightNodeLink = *List;
            (*List)->LeftNodeLink = TempNode;
            *List = TempNode;
        } 
    }
    else
    {
        printf("Malloc can not Allocate TempNode\n");;
    }
 
}
void Insert_Node_At_End(struct Node **List)
{
    struct Node *TempNode = NULL;
    struct Node *LastNode = NULL;

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if (TempNode)
    {
        printf("Enter Data: ");
        scanf("%i", &(TempNode->NodeData));
        TempNode->RightNodeLink = NULL;
        TempNode->LeftNodeLink = NULL;

        if (!*List)
        {
            *List = TempNode;
        }
        else
        {
            LastNode = *List;
            while (NULL != LastNode->RightNodeLink)
            {
                LastNode = LastNode->RightNodeLink;
            }
            TempNode->LeftNodeLink = LastNode;
            LastNode->RightNodeLink = TempNode; 
        }
        
        
    }
    
}
void Insert_Node_After(struct Node *List)
{
    struct Node *TempNode = NULL;
    struct Node *Node_c1 = List;
    struct Node *Node_c2 = NULL;
    uint32 Position = 0, Counter = 1, Length = 0;

    printf("Enter Position: ");
    scanf("%i", &Position);

    Length = Get_Length(List);
    if (Position > Length)
    {
        printf("Invalid Position, List Has (%i) Nodes\n", Length);
    }
    else
    {
        while (Counter < Position)
        {
            Counter++;
            Node_c1 = Node_c1->RightNodeLink;
        }
        
        TempNode = (struct Node *)malloc(sizeof(struct Node));
        if (TempNode)
        {
            printf("Enter Data: ");
            scanf("%i", &(TempNode->NodeData));

            if (!(Node_c1->RightNodeLink))
            {
                TempNode->RightNodeLink = NULL;
                TempNode->LeftNodeLink = Node_c1;
                Node_c1->RightNodeLink = TempNode;
            }
            else
            {
                Node_c2 = Node_c1->RightNodeLink;
                TempNode->RightNodeLink = Node_c2;
                Node_c2->LeftNodeLink = TempNode;
                TempNode->LeftNodeLink = Node_c1;
                Node_c1->RightNodeLink = TempNode;
            }
        }
        else
        {
            printf("Malloc can not Allocate List\n");
        }
    }
}
void Insert_Node_Before(struct Node **List)
{
    struct Node *TempNode = NULL;
    struct Node *Node_c1 = *List;
    struct Node *Node_c2 = NULL;

    uint32 Position = 0, Counter = 1, Length = 0;

    printf("Enter Position: ");
    scanf("%i", &Position);

    Length = Get_Length(*List);

    if(Length < Position)
    {
        printf("Invalid Position, List Has (%i) Nodes", Length);
    }
    else
    {
        TempNode = (struct Node *)malloc(sizeof(struct Node));
        if (TempNode)
        {
            printf("Enter Data: ");
            scanf("%i", &(TempNode->NodeData));

            if (Position == 1)
            {
                TempNode->LeftNodeLink = NULL;
                (*List)->LeftNodeLink = TempNode->RightNodeLink;
                TempNode->RightNodeLink = *List;
                *List = TempNode;
            }
            else
            {
                while ((Position - 1) > Counter)
                {
                    Counter++;
                    Node_c1 = Node_c1->RightNodeLink;
                }
                Node_c2 = Node_c1->RightNodeLink;
                TempNode->RightNodeLink = Node_c2;
                Node_c2->LeftNodeLink = TempNode;
                TempNode->LeftNodeLink = Node_c1;
                Node_c1->RightNodeLink = TempNode;
            }
        }       
    }
}
void Delete_Node_At_Begining(struct Node **List)
{
    struct Node *Node_c1 = *List;

    if (!*List)
    {
        printf("List Is Empty, Nothing To Delete\n");
    }
    else
    {
        (*List) = Node_c1->RightNodeLink;
        Node_c1->RightNodeLink = NULL;
        free(Node_c1);
    }
     
}
void Delete_Node_At_End(struct Node *List)
{
    struct Node *Node_c1 = List;
    struct Node *Node_c2 = NULL;

    if (!List)
    {
        printf("List Is Empty, Nothing To Delete\n");
    }
    else
    {
        while ((Node_c1->RightNodeLink))
        {
            Node_c1 = Node_c1->RightNodeLink;
        }
        Node_c2 = Node_c1->LeftNodeLink;
        Node_c2->RightNodeLink = NULL;
        Node_c1->LeftNodeLink = NULL;
        free(Node_c1);
        Node_c1 = NULL;
    }
}
void Delete_Node_At_Intermediate(struct Node *List)
{
    struct Node  *Node_c1 = List;
    struct Node  *Node_c2 = NULL;
    uint32 Position = 0, Length = 0;

    Length = Get_Length(List);
    printf("Enter Position: ");
    scanf("%i", &Position);

    if ((Position > Length))
    {
        printf("Invalid Position, List Has (%i) Nodes", Length);
    }
    else if (1 == Position)
    {
        printf("Invalid Position, Please Use Delete_Node_At_Begining\n");
    }
    else
    {
        while (Position > 1)
        {
            Node_c1 = Node_c1->RightNodeLink;
            Position--;
        }
        Node_c2 = Node_c1->LeftNodeLink;
        Node_c2->RightNodeLink = Node_c1->RightNodeLink;
        if (Node_c1->RightNodeLink == NULL)
        {
            /*Nothing*/
        }
        else
        {
            Node_c1->RightNodeLink->LeftNodeLink = Node_c2;
        }
        
        Node_c1->LeftNodeLink = NULL;
        Node_c1->RightNodeLink = NULL;
        free(Node_c1);
        Node_c1 = NULL;   
    }
}
void Display_All_Nodes_Forward(struct Node *List)
{
    struct Node *Node_c = List;
    
    printf("List Data (Forward): ");
    if (!List)
    {
        printf("List Is Empty\n");
    }
    else
    {
        while (Node_c)
        {
            printf("(%i) =>", Node_c->NodeData);
            Node_c = Node_c->RightNodeLink;
        }
        if (!Node_c)
        {
            printf("NULL\n");
        }   
    }
}
void Display_All_Nodes_Reverse(struct Node *List)
{
    struct Node *Node_c = List;
    
    printf("List Data (Reverse): ");
    if (!List)
    {
        printf("List Is Empty\n");
    }
    else
    {
        while (Node_c->RightNodeLink)
        {
            Node_c = Node_c->RightNodeLink;
        }
        
        while (Node_c)
        {
            printf("(%i) =>", Node_c->NodeData);
            Node_c = Node_c->LeftNodeLink;
        }
        if (!Node_c)
        {
            printf("NULL\n");
        }   
    } 
}
uint32 Get_Length(struct Node *List)
{
    struct Node *Node_c = List;
    uint32 Counter = 0;

    if (!Node_c)
    {
        // printf("List is Empty, ");
        Counter = 0;
    }
    else
    {
        while (Node_c)
        {
            Counter++;
            Node_c = Node_c->RightNodeLink;
        }
    }
    return (Counter);
}
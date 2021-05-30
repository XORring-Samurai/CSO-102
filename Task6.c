#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *right, *left;
};

int search(struct node *root, char c)
{
    if(root==NULL)
    return 1;
    
    if(root->data==c)
    return 0;
    
    else if(c>root->data)
    return search(root->right, c);
    
    else
    return search(root->left, c);
}

struct node* insert(struct node *root, char c)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=c;
    newnode->right=newnode->left=NULL;
    
    if(root==NULL)
    root=newnode;
    
    else if(c>root->data)
    root->right = insert(root->right, c);
    
    else
    root->left = insert(root->left, c);
    
    return root;
}

void preorder(struct node *root)
{
    struct node *temp = root;
    if(temp!=NULL)
    {
        printf("%c ", temp->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    struct node *temp = root;
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%c ", temp->data);
    }
}

void inorder(struct node *root)
{
    struct node *temp = root;
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%c ", temp->data);
        inorder(temp->right);
    }
}


void display(struct node *root)
{
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct node *root=NULL;
    while(n!=0)
    {
        char s[10];
        scanf("%s", s);
        if(!strcmp(s, "DECLARE"))
        {
            char y, x;
            scanf("%c %c", &y, &x);
            if(search(root, x))
            root = insert(root, x);
            else
            printf("variable already exists!\n");
        }
        else if(!strcmp(s, "DISPLAY"))
        display(root);
        else if(!strcmp(s, "DEL"))
        {
            char y, x;
            scanf("%c %c", &y, &x);
            del(root, x);
        }
        n--;
    }
    return 0;
    
}

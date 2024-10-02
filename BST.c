#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
/*
sabse pehle "5" aayega 
then kyuki vo "NULL" nahi hai 
toh it will go to "if(!isBST)"
"if(!isBST)" ki vjaah se "root ka left i.e 3" will go to "isBST"
then kyuki "3" "NULL" nahi hai toh it will go to "(!isBST)"
due to "(!isBST(root->left))" it will now go to "1"
since "1"!= "NULL" toh it will go to "!isBST(root->left)"
since "1" ke left mein kuchh nahi toh i.e "NULL"
it will fail "root!=NULL" waali condition and print zzzz
then compiler will return back to "1" and check the if(prev!=NULL...) condition
it will fail this condition since "prev=NULL"
now "prev=root"
and will retrun "isBST(root->right)" i.e "root ka right" check hoga "isBST" se
since it is "NULL" it will return zzzzz
 it first makes recursive calls for its left subtree (if any), completes those checks, and then moves to the right subtree. Once the left and right subtrees are processed, the function "returns" to the calling function to
 continue execution.(this is how recursion works)
At this point, Node 1 is fully processed, so the function returns to its parent node, Node 3.
now the compiler will again comeback to 3
it will now check "if(prev!=NULL) waali condition " it will fail it since 1<3
thus now "prev=3"
and it will check "root->right i.e 4"
since "4"!= NULL it will check "!isBST" waali condition 
since "4" ke left mein kuchh hai nahi i.e "NULL"
it will fail "if (root!=NULL)" waali condition 
and hence print zzzz
after completely processing 3
it will again comeback to 5 and will carry on the process
*/
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            printf("hehe\n");
        }
        if (prev != NULL && root->data <= prev->data)
        {
        printf("HEHE\n");
            // root node of the current subtree, is smaller than or equal to the prev node, then we would return 0. Since this violates the increasing orderliness.
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        printf("zzzz\n");   
    }
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4


    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    printf("\n");
    printf("%d\n", isBST(p));
    if (isBST(p))
    {
        printf("This is a bst");
    }
    else
    {
        printf("This is not a bst");
    }
    return 0;
}

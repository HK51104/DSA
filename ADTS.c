#include<stdio.h>
#include<stdlib.h>
struct ADTS
{
    int total_size;
    int used_size;
    int* ptr;
};

void createarray(struct ADTS*a,int tSize,int uSize)
{
    (*a).total_size=tSize;
    /*As "a" was storing the address of marks 
    now dereferencing it using "*"a means that we will get the value of marks 
    therefore humne marks ka total size equal kardiya tSize ke (10) */
    (*a).used_size=uSize;
    // similarly used size equal kardiya uSize ke 2
    (*a).ptr=(int *) malloc (tSize*sizeof(int));
    /* jo humne structure banaya hai "ADTS" uske andar jo member banaya hai "marks"
    uss member ke andar hi hum ek "ptr" naam ke variable se space create karre hai*/
}

void showfunction(struct ADTS* a)
// "struct ADTS" data type ka pointer jiska variable hai "a" 
{
    for (int i = 0; i < a->used_size; i++)
    // "->" simply means ki "a" naam ka variable ke andar jo humne "used_size" naam ka variable banaya hai 
    // basically "used_size" yahan par defined nhi hai therefore humne ek reference dedi uss varibe se jo ki yahan par defined hai 
    // which in this case is "a"
    // "a" ke andar jo "used size" hai uski baat hori hai 
    {
        printf("%d\n",(a->ptr)[i]);
    }
    
}
void setfunction(struct ADTS* a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
    
}
int main(int argc, char const *argv[])
{
    struct ADTS marks;
    createarray(&marks,10,2);
    setfunction(&marks);
    showfunction(&marks);
    return 0;
}

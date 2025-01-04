#include <stdio.h>
#include <stdlib.h>
#define Max_Element 200

typedef struct Treenode{
    int weight;
    char ch;
    struct Treenode* left;
    struct Treenode* right;
}Treenode;

typedef struct element{
    int key;
    char ch;
    Treenode* ptree;
}element;

typedef struct Heaptype{
    element heap[Max_Element];
    int heap_size;
}Heaptype;

Heaptype* create()
{
    return (Heaptype*)malloc(sizeof(Heaptype));
}

void init(Heaptype* h)
{
    h->heap_size = 0;
}

void insert_min_heap(Heaptype *h, element item)
{
    int i;
    i = ++(h->heap_size);

    while((i != 1) && (item.key < h->heap[i/2].key))
    {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_min_heap(Heaptype *h)
{
    int parent, child;
    element tmp, item;

    item = h->heap[1];
    tmp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while(child <= h->heap_size)
    {
        if((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
            child++;
        if(tmp.key < h->heap[child].key)
            break;
        h->heap[parent] =h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = tmp;
    return item;
}

Treenode* make_tree(Treenode *left, Treenode* right)
{
    Treenode* node = (Treenode*)malloc(sizeof(Treenode));
    node->left = left;
    node->right = right;
    return node;
}

void destroy_tree(Treenode* root)
{
    if(root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

int is_leaf(Treenode* root)
{
    return (!(root->left) && !(root->right));
}

void print_array(int codes[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d", codes[i]);
    printf("\n");
}

void print_codes(Treenode* root, int codes[], int top)
{
    if(root->left)
    {
        codes[top] = 1;
        print_codes(root->left, codes, top + 1);
    }
    if(root->right)
    {
        codes[top] = 0;
        print_codes(root->right, codes, top + 1);
    }
    if(is_leaf(root))
    {
        printf("%c: ", root->ch);
        print_array(codes, top);
    }
}

void Huffman_tree(int freq[], char ch_list[], int n)
{
    Treenode *node, *x;
    Heaptype *heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;

    heap = create();
    init(heap);
    for(int i = 0; i < n; i++)
    {
        node = make_tree(NULL, NULL);
        e.ch = node->ch = ch_list[i];
        e.key = node->weight = freq[i];
        e.ptree = node;
        insert_min_heap(heap, e);
    }
    for(int i = 1; i < n; i++)
    {
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);
        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        printf("%d+%d->%d \n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e);
    }
    e = delete_min_heap(heap);
    print_codes(e.ptree, codes, top);
    destroy_tree(e.ptree);
    free(heap);
}

int main()
{
    char ch_list[] = {'s', 'i', 'n', 't', 'e'};
    int freq[] = {4, 6, 8, 12, 15};
    Huffman_tree(freq, ch_list, 5);
    return 0;
}
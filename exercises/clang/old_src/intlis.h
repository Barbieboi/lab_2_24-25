#define MAX 300

typedef struct list{
    int val ;
    struct list* next;
}int_list;

int_list* create_node(int val);

void ins_list(int_list** head_ref, int_list* in);

int_list* create_list(int len);

void reverse_list(int_list** head_ref);

void delete_lis(int_list**head , bool(*f)(int) );

void free_list(int_list* list);

void print_list(int_list* list);

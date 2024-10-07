
typedef struct stack{
    int val ;
    struct stack* next;
}stack_t ;
void push(stack_t** pila_ref, int n); 
int pop(stack_t** pila_ref);
int peek(const stack_t* pila);
int length(const stack_t* pila);
void print_stack(const stack_t* pila, FILE* stream);


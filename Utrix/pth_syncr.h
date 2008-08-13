#include"pthread_lib.h"
#define PTHREAD_MUTEX_INITIALIZER {NULL,1}
#define NOT_INIT 0
#define INIT 1
#define LOCK 2
#define DESTROY 3



/*Struttura del mutex*/
typedef struct mutex{
unsigned char state;
unsigned int val;
pthread_t own;/*Tid di chi possiede il mutex*/
struct mutex* next;
struct mutex* prev;
} pth_mutex_t;


/*Struttura più esterna del mutex, è un semplice contenitore*/
struct pthread_mutex_s{
pth_mutex_t* mux;
int init;
};




typedef struct cond{

struct cond* next;
struct cond* prev;
} pth_cond_t;

struct pthread_cond_s{
pth_cond_t* mux;
int init;
};




/*Lista dei mutex attivi*/
extern pth_mutex_t* list_mux;



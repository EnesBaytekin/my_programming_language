#include <stdio.h>
#include <stdlib.h>

#define MAX_VAR_COUNT 2048
#define MAX_VAR_NAME_LENGTH 16
#define MAX_STRING_LENGTH 128

typedef enum {
    tINTEGER,
    tFLOAT,
    tCHARACTER,
    tSTRING,
    tLIST,
    tVARIABLE,
    tOPERATION,
    tNULL,
} types_enum;

typedef struct {
    types_enum type;
    union {
        int ival;
        float fval;
        char cval;
        char *sval;
        struct list_node_tag *lval;
    };
} data_type;

typedef struct {
    types_enum type;
    union {
        int *ival;
        float *fval;
        char *cval;
        char *sval[1];
        struct list_node_tag *lval[1];
    };
} data_type_pointers;

typedef struct {
    int value;
} int_node_type;

typedef struct {
    float value;
} flt_node_type;

typedef struct {
    char value;
} chr_node_type;

typedef struct {
    char *value;
} str_node_type;

typedef struct {
    struct list_node_tag *value;
} lst_node_type;

typedef struct {
    int index;
} var_node_type;

typedef struct {
    int operation;
    int operand_count;
    struct node_type_tag **operands;
} opr_node_type;

typedef struct node_type_tag {
    types_enum type;
    union {
        int_node_type int_node;
        flt_node_type flt_node;
        chr_node_type chr_node;
        str_node_type str_node;
        lst_node_type lst_node;
        var_node_type var_node;
        opr_node_type opr_node;
    };
} node_type;

/************************
 *     LINKED LISTS     *
 ************************/

typedef struct list_node_tag {
    data_type *data;
    struct list_node_tag *next;
} list_node;


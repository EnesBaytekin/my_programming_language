%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void list_add_item(list_node **head, data_type *data);
void list_insert_item(list_node **head, int index, data_type *data);
void list_delete_item(list_node **head, int index);
data_type *list_get_item(list_node *head, int index);
int list_get_length(list_node *head);
void list_print(list_node *head, int level);
list_node *list_copy(list_node *head);

data_type_pointers *var_values[MAX_VAR_COUNT];
char var_names[MAX_VAR_COUNT][MAX_VAR_NAME_LENGTH];
int var_count = 0;

void yyerror(char *error_message);
int yylex(void);

int get_index_of_var(char *var_name);
node_type *get_node_from_int(int value);
node_type *get_node_from_flt(float value);
node_type *get_node_from_chr(char value);
node_type *get_node_from_str(char *value);
node_type *get_node_from_lst();
node_type *get_node_from_var(int index);
node_type *get_node_from_opr(int operation, int operand_count, node_type *operand1, node_type *operand2, node_type *operand3, node_type *operand4);
void free_node(node_type *p);
data_type *ex(node_type *p);

%}

%union {
    int ival;
    float fval;
    char cval;
    char *sval;
    struct list_node_tag *lval;
    int index;
    node_type *node;
}

%token <ival> INT
%token <cval> CHR
%token <fval> FLT
%token <sval> STR
%token <index> VAR
%token IF
%token WHILE
%token FOR
%token PRINT
%token TO_INT
%token TO_FLT
%token TO_CHR
%token TO_STR
%token TYPE
%token LENGTH
%nonassoc IFX
%nonassoc ELSE

%type <node> expression
%type <node> statement
%type <node> statement_list

%nonassoc GET_ITEM
%left AND OR
%nonassoc NOT
%left EQ NE GE LE '<' '>'
%left '+' '-'
%left '*' '/'
%nonassoc MINUS

%%

program:
        function                                                        { printf("OK"); exit(0); }
        ;

function:
        function statement                                              { free(ex($2)); free_node($2); }
        |
        ;

statement:
        ';'                                                             { $$ = get_node_from_opr(';', 2, NULL, NULL, NULL, NULL); }
        | expression ';'                                                { $$ = $1; }
        | PRINT '(' expression ')' ';'                                  { $$ = get_node_from_opr(PRINT, 1, $3, NULL, NULL, NULL); }
        | WHILE '(' expression ')' statement                            { $$ = get_node_from_opr(WHILE, 2, $3, $5, NULL, NULL); }
        | VAR '=' expression ';'                                        { $$ = get_node_from_opr('=', 2, get_node_from_var($1), $3, NULL, NULL); }
        | FOR '(' VAR '=' expression ':' expression ')' statement       { $$ = get_node_from_opr(FOR, 4, get_node_from_var($3), $5, $7, $9); }
        | IF '(' expression ')' statement %prec IFX                     { $$ = get_node_from_opr(IF, 2, $3, $5, NULL, NULL); }
        | IF '(' expression ')' statement ELSE statement                { $$ = get_node_from_opr(IF, 3, $3, $5, $7, NULL); }
        | '{' statement_list '}'                                        { $$ = $2; }
        ;

statement_list:
        statement                                                       { $$ = $1; }
        | statement_list statement                                      { $$ = get_node_from_opr(';', 2, $1, $2, NULL, NULL); }
        ;

expression:
        INT                                                             { $$ = get_node_from_int($1); }
        | FLT                                                           { $$ = get_node_from_flt($1); }
        | CHR                                                           { $$ = get_node_from_chr($1); }
        | STR                                                           { $$ = get_node_from_str($1); }
        | VAR                                                           { $$ = get_node_from_var($1); }
        | '#'                                                           { $$ = get_node_from_lst(); }
        | VAR '[' expression ']' %prec GET_ITEM                         { $$ = get_node_from_opr(GET_ITEM, 2, get_node_from_var($1), $3, NULL, NULL); }
        | TO_INT '(' expression ')'                                     { $$ = get_node_from_opr(TO_INT, 1, $3, NULL, NULL, NULL); }
        | TO_FLT '(' expression ')'                                     { $$ = get_node_from_opr(TO_FLT, 1, $3, NULL, NULL, NULL); }
        | TO_CHR '(' expression ')'                                     { $$ = get_node_from_opr(TO_CHR, 1, $3, NULL, NULL, NULL); }
        | TO_STR '(' expression ')'                                     { $$ = get_node_from_opr(TO_STR, 1, $3, NULL, NULL, NULL); }
        | TYPE '(' expression ')'                                       { $$ = get_node_from_opr(TYPE,   1, $3, NULL, NULL, NULL); }
        | LENGTH '(' expression ')'                                     { $$ = get_node_from_opr(LENGTH, 1, $3, NULL, NULL, NULL); }
        | NOT expression %prec NOT                                      { $$ = get_node_from_opr(NOT, 2, $2, NULL, NULL, NULL); }
        | '-' expression %prec MINUS                                    { $$ = get_node_from_opr(MINUS,  1, $2, NULL, NULL, NULL); }
        | expression OR expression                                      { $$ = get_node_from_opr(OR,  2, $1, $3, NULL, NULL); }
        | expression AND expression                                     { $$ = get_node_from_opr(AND, 2, $1, $3, NULL, NULL); }
        | expression '+' expression                                     { $$ = get_node_from_opr('+', 2, $1, $3, NULL, NULL); }
        | expression '-' expression                                     { $$ = get_node_from_opr('-', 2, $1, $3, NULL, NULL); }
        | expression '*' expression                                     { $$ = get_node_from_opr('*', 2, $1, $3, NULL, NULL); }
        | expression '/' expression                                     { $$ = get_node_from_opr('/', 2, $1, $3, NULL, NULL); }
        | expression '<' expression                                     { $$ = get_node_from_opr('<', 2, $1, $3, NULL, NULL); }
        | expression '>' expression                                     { $$ = get_node_from_opr('>', 2, $1, $3, NULL, NULL); }
        | expression EQ expression                                      { $$ = get_node_from_opr(EQ,  2, $1, $3, NULL, NULL); }
        | expression NE expression                                      { $$ = get_node_from_opr(NE,  2, $1, $3, NULL, NULL); }
        | expression GE expression                                      { $$ = get_node_from_opr(GE,  2, $1, $3, NULL, NULL); }
        | expression LE expression                                      { $$ = get_node_from_opr(LE,  2, $1, $3, NULL, NULL); }
        | '(' expression ')'                                            { $$ = $2; }
        ;

%%

void yyerror(char *error_message) {
    fprintf(stderr, "%s", error_message);
    exit(1);
}

int main(void) {
    yyparse();
    return 0;
}

int get_index_of_var(char *var_name) {
    for (int i=0; i<MAX_VAR_COUNT; ++i) {
        if (i < var_count && strcmp(var_names[i], var_name) == 0)
            return i;
    }
    strcpy(var_names[var_count], var_name);
    var_count += 1;
    return var_count-1;
}

node_type *get_node_from_int(int value) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tINTEGER;
    p->int_node.value = value;
    return p;
}

node_type *get_node_from_flt(float value) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tFLOAT;
    p->flt_node.value = value;
    return p;
}

node_type *get_node_from_chr(char value) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tCHARACTER;
    p->chr_node.value = value;
    return p;
}

node_type *get_node_from_str(char *value) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tSTRING;
    char *new_str = (char *)malloc(sizeof(char)*(strlen(value)+1));
    if (new_str == NULL) yyerror("out of memory");
    new_str[0] = '\0';
    strcat(new_str, value);
    p->str_node.value = new_str;
    return p;
}

node_type *get_node_from_lst() {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tLIST;
        // list_node *new_list = (list_node *)malloc(sizeof(list_node));
        // if (new_list == NULL) yyerror("out of memory");
    list_node *new_list = NULL;
    p->lst_node.value = new_list;
    return p;
}

node_type *get_node_from_var(int index) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tVARIABLE;
    p->var_node.index = index;
    return p;
}

node_type *get_node_from_opr(int operation, int operand_count, node_type *operand1, node_type *operand2, node_type *operand3, node_type *operand4) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tOPERATION;
    p->opr_node.operation = operation;
    p->opr_node.operand_count = operand_count;
    p->opr_node.operands = (node_type **)malloc(operand_count*sizeof(node_type *));
    if (operand_count >= 1) p->opr_node.operands[0] = operand1;
    if (operand_count >= 2) p->opr_node.operands[1] = operand2;
    if (operand_count >= 3) p->opr_node.operands[2] = operand3;
    if (operand_count >= 4) p->opr_node.operands[3] = operand4;
    return p;
}

void free_node(node_type *p) {
    if (p == NULL) return;
    if (p->type == tOPERATION) {
        for (int i=0; i<p->opr_node.operand_count; ++i) 
            free_node(p->opr_node.operands[i]);
        free(p->opr_node.operands);
    }
    free(p);
}

int is_number(char *text) {
    int is_a_number = 1;
    int digits_started = 0;
    int digits_finished = 0;
    for (int i=0; text[i] != '\0'; ++i) {
        if (48 <= text[i] && text[i] < 58) {
            digits_started = 1;
            if (digits_finished) is_a_number = 0;
        } else if (
            (text[i] == '\n') ||
            (text[i] == '\t') ||
            (text[i] == ' ')
            ) {
            if (digits_started) digits_finished = 1;
        } else {
            is_a_number = 0;
        }
    }
    return is_a_number;
}

int is_float(char *text) {
    int is_a_number = 1;
    int digits_started = 0;
    int digits_finished = 0;
    int dot_found = 0;
    for (int i=0; text[i] != '\0'; ++i) {
        if (text[i] == '.') {
            if (dot_found) is_a_number = 0;
            else dot_found = 1;
        } else if (48 <= text[i] && text[i] < 58) {
            digits_started = 1;
            if (digits_finished) is_a_number = 0;
        } else if (
            (text[i] == '\n') ||
            (text[i] == '\t') ||
            (text[i] == ' ')
            ) {
            if (digits_started) digits_finished = 1;
        } else {
            is_a_number = 0;
        }
    }
    return is_a_number;
}

data_type *ex(node_type *p) {
    data_type *new_data = (data_type *)malloc(sizeof(data_type));
    if (new_data == NULL) yyerror("out of memory");
    new_data->type = tNULL;
    new_data->ival = 0;
    if (p == NULL) return new_data;
    switch (p->type) {
        case tINTEGER: {
            new_data->type = tINTEGER;
            new_data->ival = p->int_node.value;
        } break;
        case tFLOAT: {
            new_data->type = tFLOAT;
            new_data->fval = p->flt_node.value;
        } break;
        case tCHARACTER: {
            new_data->type = tCHARACTER;
            new_data->cval = p->chr_node.value;
        } break;
        case tSTRING: {
            new_data->type = tSTRING;
            new_data->sval = p->str_node.value;
        } break;
        case tLIST: {
            new_data->type = tLIST;
            new_data->lval = p->lst_node.value;
        } break;
        case tVARIABLE: {
            data_type_pointers *var_data = var_values[p->var_node.index];
            new_data->type = var_data->type;
            if      (var_data->type == tINTEGER)   new_data->ival = *var_data->ival;
            else if (var_data->type == tFLOAT)     new_data->fval = *var_data->fval;
            else if (var_data->type == tCHARACTER) new_data->cval = *var_data->cval;
            else if (var_data->type == tLIST)      new_data->lval = *var_data->lval;
            else if (var_data->type == tSTRING)    new_data->sval = *var_data->sval;
        } break;
        case tOPERATION: {
            switch (p->opr_node.operation) {
                case IF: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if ( (data->type == tINTEGER   && data->ival    != 0) || 
                         (data->type == tFLOAT     && data->fval    != 0) || 
                         (data->type == tCHARACTER && data->cval    != 0) || 
                         (data->type == tSTRING    && data->sval[0] != 0) ) {
                        free(ex(p->opr_node.operands[1]));
                    } else if (p->opr_node.operand_count > 2) {
                        free(ex(p->opr_node.operands[2]));
                    }
                    free(data);
                } break;
                case WHILE: {
                    while (1) {
                        data_type *data = ex(p->opr_node.operands[0]);
                        if ( (data->type == tINTEGER   && data->ival    != 0) || 
                             (data->type == tCHARACTER && data->cval    != 0) || 
                             (data->type == tFLOAT     && data->fval    != 0) || 
                             (data->type == tSTRING    && data->sval[0] != 0) ) {
                            free(ex(p->opr_node.operands[1]));
                        } else {
                            free(data);
                            break;
                        }
                        free(data);
                    }
                } break;
                case FOR: {
                    data_type *data_from = ex(p->opr_node.operands[1]);
                    data_type *data_to   = ex(p->opr_node.operands[2]);
                    int do_for = 1;
                    int ifrom = 0;                    
                    int ito   = 0;
                    if (data_from->type == tINTEGER) ifrom = data_from->ival; else do_for = 0;
                    if (data_to->type   == tINTEGER) ito   = data_to->ival;   else do_for = 0;
                    if (ifrom >= ito) do_for = 0;
                    if (do_for) {
                        data_type_pointers *var_data = (data_type_pointers *)malloc(sizeof(data_type_pointers));
                        if (var_data == NULL) yyerror("out of memory");
                        var_data->type = tINTEGER;
                        var_data->ival = &ifrom;
                        free(var_values[p->opr_node.operands[0]->var_node.index]);
                        var_values[p->opr_node.operands[0]->var_node.index] = var_data;

                        while (ifrom < ito) {
                            free(ex(p->opr_node.operands[3]));
                            ifrom += 1;

                            var_data = (data_type_pointers *)malloc(sizeof(data_type_pointers));
                            if (var_data == NULL) yyerror("out of memory");
                            var_data->type = tINTEGER;
                            var_data->ival = &ifrom;
                            free(var_values[p->opr_node.operands[0]->var_node.index]);
                            var_values[p->opr_node.operands[0]->var_node.index] = var_data;
                        } 
                        var_data = (data_type_pointers *)malloc(sizeof(data_type_pointers));
                        if (var_data == NULL) yyerror("out of memory");
                        var_data->type = tINTEGER;
                        var_data->ival = &ifrom;
                        free(var_values[p->opr_node.operands[0]->var_node.index]);
                        var_values[p->opr_node.operands[0]->var_node.index] = var_data;
                    }
                    free(data_from);
                    free(data_to);
                } break;
                case PRINT: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if      (data->type == tINTEGER)   printf("%d\n", data->ival);
                    else if (data->type == tFLOAT)     printf("%f\n", data->fval);
                    else if (data->type == tCHARACTER) printf("%c\n", data->cval);
                    else if (data->type == tSTRING)    printf("%s\n", data->sval);
                    else if (data->type == tLIST)      list_print(data->lval, 0);
                    else if (data->type == tNULL)      printf("<NaT>\n");
                    free(data);
                } break;
                case TYPE: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    char *new_str = (char *)malloc(sizeof(char)*6);
                    if (new_str == NULL) yyerror("out of memory");
                    if      (data->type == tINTEGER)   sprintf(new_str, "<INT>");
                    else if (data->type == tCHARACTER) sprintf(new_str, "<CHR>");
                    else if (data->type == tFLOAT)     sprintf(new_str, "<FLT>");
                    else if (data->type == tSTRING)    sprintf(new_str, "<STR>");
                    else if (data->type == tLIST)      sprintf(new_str, "<LST>");
                    else if (data->type == tNULL)      sprintf(new_str, "<NaT>");
                    new_data->type = tSTRING;
                    new_data->sval = new_str;
                    free(data);
                } break;
                case TO_INT: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data->ival;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tINTEGER;
                        new_data->ival = (int)data->fval;
                    }
                    else if (data->type == tCHARACTER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data->cval;
                    }
                    else if (data->type == tSTRING) {
                        if (is_number(data->sval)) {
                            new_data->type = tINTEGER;
                            new_data->ival = atoi(data->sval);
                        }
                    }
                    free(data);
                } break;
                case TO_FLT: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data->ival;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data->fval;
                    }
                    else if (data->type == tCHARACTER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data->cval;
                    }
                    else if (data->type == tSTRING) {
                        if (is_float(data->sval)) {
                            new_data->type = tFLOAT;
                            new_data->fval = atof(data->sval);
                        }
                    }
                    free(data);
                } break;
                case TO_CHR: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tCHARACTER;
                        new_data->cval = data->ival;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tCHARACTER;
                        new_data->cval = (int)data->fval;
                    }
                    else if (data->type == tCHARACTER) {
                        new_data->type = tCHARACTER;
                        new_data->cval = data->cval;
                    }
                    else if (data->type == tSTRING) {
                        new_data->type = tCHARACTER;
                        new_data->cval = data->sval[0];
                    }
                    free(data);
                } break;
                case TO_STR: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tSTRING;

                        int digit_count = 0;
                        int number = data->ival;
                        while (number != 0) {
                            number /= 10;
                            digit_count += 1;
                        }

                        char *new_str = (char *)malloc(sizeof(char)*(digit_count+1));
                        if (new_str == NULL) yyerror("out of memory");
                        sprintf(new_str, "%d", data->ival);
                        new_data->sval = new_str;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tSTRING;

                        int digit_count = 0;
                        int number = (int)data->fval;
                        while (number != 0) {
                            number /= 10;
                            digit_count += 1;
                        }

                        char *new_str = (char *)malloc(sizeof(char)*(digit_count+8));
                        if (new_str == NULL) yyerror("out of memory");
                        sprintf(new_str, "%f", data->fval);
                        new_data->sval = new_str;
                    }
                    else if (data->type == tCHARACTER) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*2);
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = data->cval;
                        new_str[1] = '\0';
                        new_data->sval = new_str;
                    }
                    else if (data->type == tSTRING) {
                        new_data->type = tSTRING;
                        new_data->sval = data->sval;
                    }
                    free(data);
                } break;
                case ';': {
                    free(ex(p->opr_node.operands[0]));
                    data_type *data = ex(p->opr_node.operands[1]);
                    if      (data->type == tINTEGER)   new_data->ival == data->ival;
                    else if (data->type == tFLOAT)     new_data->fval == data->fval;
                    else if (data->type == tCHARACTER) new_data->cval == data->cval;
                    else if (data->type == tSTRING)    new_data->sval == data->sval;
                    free(data);
                } break;
                case '=': {
                    data_type *data = ex(p->opr_node.operands[1]);
                    data_type_pointers *var_data = (data_type_pointers *)malloc(sizeof(data_type_pointers));
                    if (var_data == NULL) yyerror("out of memory");
                    var_data->type = data->type;
                    if      (data->type == tINTEGER)   var_data->ival = &data->ival;
                    else if (data->type == tFLOAT)     var_data->fval = &data->fval;
                    else if (data->type == tCHARACTER) var_data->cval = &data->cval;
                    else if (data->type == tLIST)      *var_data->lval = data->lval;
                    else if (data->type == tSTRING)    *var_data->sval = data->sval;
                    free(var_values[p->opr_node.operands[0]->var_node.index]);
                    var_values[p->opr_node.operands[0]->var_node.index] = var_data;
                    // free(data);
                } break;
                case GET_ITEM: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tLIST && data2->type == tINTEGER) {
                        new_data = list_get_item(list_copy(data1->lval), data2->ival);
                    }
                    else if (data1->type == tSTRING && data2->type == tINTEGER) {
                        new_data->type = tCHARACTER;
                        new_data->cval = data1->sval[data2->ival];
                    }
                    free(data1);
                    free(data2);
                } break;
                case LENGTH: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tLIST) {
                        new_data->type = tINTEGER;
                        new_data->ival = list_get_length(data->lval);
                    } else if (data->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = strlen(data->sval);
                    }
                    free(data);
                } break;
                case MINUS: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = -data->ival;
                    } else if (data->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = -data->fval;
                    } else if (data->type == tSTRING) {
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data->sval)));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        strcat(new_str, data->sval+1);
                        new_data->type = tSTRING;
                        new_data->sval = new_str;
                    } else if (data->type == tLIST) {
                        list_node *new_list = list_copy(data->lval);
                        list_delete_item(&new_list, 0);
                        new_data->type = tLIST;
                        new_data->lval = new_list;
                    }
                    free(data);
                } break;
                case '+': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tLIST) {
                        list_node *new_list = list_copy(data1->lval);
                        list_add_item(&new_list, data2);
                        new_data->type = tLIST;
                        new_data->lval = new_list;
                    }
                    else if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival + data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival + data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval + data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval + data2->fval;
                    }
                    else if (data1->type == tSTRING && data2->type == tSTRING) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data1->sval)+strlen(data2->sval)+1));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        strcat(new_str, data1->sval);
                        strcat(new_str, data2->sval);
                        new_data->sval = new_str;
                    }
                    else if (data1->type == tSTRING && data2->type == tCHARACTER) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data1->sval)+2));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        strcat(new_str, data1->sval);
                        new_str[strlen(data1->sval)] = data2->cval;
                        new_str[strlen(data1->sval)+1] = '\0';
                        new_data->sval = new_str;
                    }
                    else if (data1->type == tCHARACTER && data2->type == tSTRING) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data2->sval)+2));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = data1->cval;
                        new_str[1] = '\0';
                        strcat(new_str, data2->sval);
                        new_str[strlen(data2->sval)+1] = '\0';
                        new_data->sval = new_str;
                    }
                    else if (data1->type == tCHARACTER && data2->type == tCHARACTER) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(3));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = data1->cval;
                        new_str[1] = data2->cval;
                        new_str[2] = '\0';
                        new_data->sval = new_str;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '-': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tLIST && data2->type == tINTEGER) {
                        list_node *new_list = list_copy(data1->lval);
                        list_delete_item(&new_list, data2->ival);
                        new_data->type = tLIST;
                        new_data->lval = new_list;
                    }
                    else if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival - data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival - data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval - data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval - data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '*': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival * data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival * data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval * data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval * data2->fval;
                    }
                    else if (data1->type == tSTRING && data2->type == tINTEGER) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data1->sval)*data2->ival+1));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        for (int i=0; i<data2->ival; ++i)
                            strcat(new_str, data1->sval);
                        new_data->sval = new_str;
                    }
                    else if (data1->type == tINTEGER && data2->type == tSTRING) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data2->sval)*data1->ival+1));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        for (int i=0; i<data1->ival; ++i)
                            strcat(new_str, data2->sval);
                        new_data->sval = new_str;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '/': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival / data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival / data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval / data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval / data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '<': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival < data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival < data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval < data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval < data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '>': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival > data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival > data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval > data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval > data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case LE: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival <= data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival <= data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval <= data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval <= data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case GE: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival >= data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival >= data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval >= data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval >= data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case EQ: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival == data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival == data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval == data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval == data2->fval;
                    }
                    else if (data1->type == tCHARACTER && data2->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->cval == data2->cval;
                    }
                    else if (data1->type == tSTRING && data2->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = (strcmp(data1->sval, data2->sval) == 0);
                    }
                    free(data1);
                    free(data2);
                } break;
                case NE: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival != data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival != data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval != data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval != data2->fval;
                    }
                    else if (data1->type == tCHARACTER && data2->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->cval != data2->cval;
                    }
                    else if (data1->type == tSTRING && data2->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = (strcmp(data1->sval, data2->sval) != 0);
                    }
                    free(data1);
                    free(data2);
                } break;
                case AND: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival && data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival && data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval && data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval && data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case OR: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival || data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival || data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval || data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval || data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case NOT: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = !data->ival;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = !data->fval;
                    }
                    free(data);
                } break;
            }
        } break;
    }
    return new_data;
}


/************************
 *     LINKED LISTS     *
 ************************/


void list_add_item(list_node **head, data_type *data) {
    list_node *p = *head;
    list_node *pre = NULL;
    data_type *new_data = (data_type *)malloc(sizeof(data_type));
    new_data->type = data->type;
    new_data->ival = data->ival;
    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    if (new_node == NULL) return;
    new_node->data = new_data;
    new_node->next = NULL;
    while (p != NULL) {
        pre = p;
        p = p->next;
    }
    if (pre == NULL)
        *head = new_node;
    else {
        pre->next = new_node;
    }
}

void list_insert_item(list_node **head, int index, data_type *data) {
    list_node *p = *head;
    list_node *pre = NULL;
    data_type *new_data = (data_type *)malloc(sizeof(data_type));
    new_data->type = data->type;
    new_data->ival = data->ival;
    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    if (new_node == NULL) return;
    new_node->data = new_data;
    new_node->next = NULL;
    while (p != NULL && index > 0) {
        pre = p;
        p = p->next;
        index -= 1;
    }
    if (pre == NULL) {
        *head = new_node;
    }
    else {
        pre->next = new_node;
    }
    new_node->next = p;
}

void list_delete_item(list_node **head, int index) {
    list_node *p = *head;
    list_node *pre = NULL;
    if (p == NULL) return;
    while (p != NULL && index > 0) {
        pre = p;
        p = p->next;
        index -= 1;
    }
    if (pre == NULL)
        *head = p->next;
    else
        pre->next = p->next;
    free(p->data);
    free(p);
}

data_type *list_get_item(list_node *head, int index) {
    list_node *p = head;
    while (p != NULL && index > 0) {
        p = p->next;
        index -= 1;
    }
    return p->data;
}

int list_get_length(list_node *head) {
    list_node *p = head;
    int length = 0;
    while (p != NULL) {
        p = p->next;
        length += 1;
    }
    return length;
}

void list_print(list_node *head, int level) {
    char tabs[level*4+1];
    for (int i=0; i<level*4; ++i)
        tabs[i] = ' ';
    tabs[level*4] = '\0';

    list_node *p = head;
    printf("[\n", tabs);
    while (p != NULL) {
        if      (p->data->type == tINTEGER)   printf("    %s<INT> %d\n", tabs, p->data->ival);
        else if (p->data->type == tFLOAT)     printf("    %s<FLT> %f\n", tabs, p->data->fval);
        else if (p->data->type == tCHARACTER) printf("    %s<CHR> '%c'\n", tabs, p->data->cval);
        else if (p->data->type == tSTRING)    printf("    %s<STR> \"%s\"\n", tabs, p->data->sval);
        else if (p->data->type == tLIST)      {
                                                printf("    %s<LST> ", tabs);
                                                list_print(p->data->lval, level+1);
                                              }
        else if (p->data->type == tNULL)      printf("    %s<NaT>\n", tabs);
        p = p->next;
    }
    printf("%s]\n", tabs);
}

list_node *list_copy(list_node *head) {
    if (head == NULL)
        return NULL;

    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    if (new_node == NULL) yyerror("out of memory");

    data_type *item = (data_type *)malloc(sizeof(data_type));
    if (item == NULL) yyerror("out of memory");
    item->type = head->data->type;
    if      (head->data->type == tINTEGER)   item->ival = head->data->ival;
    else if (head->data->type == tFLOAT)     item->fval = head->data->fval;
    else if (head->data->type == tCHARACTER) item->cval = head->data->cval;
    else if (head->data->type == tSTRING)    item->sval = head->data->sval;
    else if (head->data->type == tLIST)      item->lval = head->data->lval;
    
    new_node->data = item;
    new_node->next = list_copy(head->next);

    return new_node;
}

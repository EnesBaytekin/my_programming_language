%{

#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "mpl.tab.h"

void yyerror(char *error_message);
int get_index_of_var(char *var_name);

char buf[MAX_STRING_LENGTH];
char *s;

%}

%x STRING

%%

"::".*                          ;
\"                              { BEGIN STRING; s = buf; }
<STRING>\\n                     { *s++ = '\n'; }
<STRING>\\t                     { *s++ = '\t'; }
<STRING>\\\"                    { *s++ = '\"'; }
<STRING>\"                      { 
                                    *s = 0;
                                    BEGIN 0;
                                    yylval.sval = buf;
                                    return STR;
                                }
<STRING>\n                      { yyerror("invalid string"); }
<STRING>.                       { *s++ = *yytext; }
"and"                           return AND;
"or"                            return OR;
"not"                           return NOT;
"if"                            return IF;
"else"                          return ELSE;
"while"                         return WHILE;
"for"                           return FOR;
"print"                         return PRINT;
"to_int"                        return TO_INT;
"to_flt"                        return TO_FLT;
"to_chr"                        return TO_CHR;
"to_str"                        return TO_STR;
"type"                          return TYPE;
"length"                        return LENGTH;
"=="                            return EQ;
"!="                            return NE;
">="                            return GE;
"<="                            return LE;
[-+*/<>=(){};:,\[\]#]           return *yytext;
[0-9]+"."[0-9]+                 {
                                    yylval.fval = atof(yytext);
                                    return FLT;
                                }
[0-9]+                          {
                                    yylval.ival = atoi(yytext);
                                    return INT;
                                }
'.'                             {
                                    yylval.cval = yytext[1];
                                    return CHR;
                                }
[a-zA-Z_]([a-zA-Z_]|[0-9])*     {
                                    yylval.index = get_index_of_var(yytext);
                                    return VAR;
                                }
[ \t\n]                         ;
.                               yyerror("invalid character");

%%

int yywrap(void) {
    return 1;
}

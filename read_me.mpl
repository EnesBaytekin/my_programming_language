::::::::::::::::::::::::::::::::::::::::::::
::              MPL TUTORIAL              ::
::::::::::::::::::::::::::::::::::::::::::::

:: this is a comment line

:: there are 5 different data types
::   integer
::   float
::   character
::   string
::   list

:: we do not need to declare the type of the variables when assigning them
:: compiler will understand the type

:: i_var = 42;                     :: variable 'i_var' is an integer
:: f_var = 3.14;                   :: variable 'f_var' is a float
:: c_var = 'A';                    :: variable 'c_var' is a character
:: s_var = "Hello, World!";        :: variable 's_var' is a string
:: l_var = #;                      :: variable 'l_var' is an empty linked list which can hold data of any type

:: type() keyword converts an expression to a string that shows its type
:: type(var_name) returns the one of the following strings:
:: "<INT>"
:: "<FLT>"
:: "<CHR>"
:: "<STR>"
:: "<LST>"
:: "<NaT>"   (not a type)

:: some expressions may be converted to the other types
:: to_int() --> converts a str to int
::              converts a chr to int according to the ascii value
::              converts a flt to int like floor function
::
:: to_flt() --> converts a int to flt
::              converts a chr to flt according to the ascii value
::              converts a str to flt
::
:: to_chr() --> converts a int to chr according to the ascii value
::              converts a flt to chr according to the ascii value
::              converts a str to chr (just converts the first character of the string)
::
:: to_str() --> converts a int to str
::              converts a flt to str
::              converts a chr to str

:: print() keyword prints the value of the given string, character, integer or float
:: or prints the items of the given list (recursively for nested lists)

:: length() keyword returns the length of the given list or string

:: the following binary operators are possible for numbers (integer and float):
::   +    -
::   *    /
::
:: and the unary operator minus:
::   -
::
:: comparison operators:
::   ==   !=   >=   <=   <   >
::
::   ==   != operators can also compare strings and characters
::
:: logical operators:
::   and   or   not

:: expressions may be grouped by using paranthesis:
::   (   )

:: there are conditional statements:
::
::   if ( <condition> ) <statement>
:: statement is made if the condition is true
::
::   if ( <condition> ) <statement_1> else <statement_2>
:: statement_1 is made the condition is true, otherwise statement_2 is made

:: there are loop statements:
::
::   while ( <condition> ) <statement>
:: statement is made while condition is true
::
::   for ( <variable> = <start_value> : <end_value> ) <statement>
:: variable equals to the start_value at the beginning and increase 1 per loop
:: statement is made until the variable reaches to end_value
:: variable is in the range [start_value, end_value)

:: statements may be grouped by using paranthesis:
::   {   }

:: every statement must end with ; symbol

:: we can create a new empty list by # symbol:

:: my_list = #;
:: print(my_list);

:: output:
:: [
:: ]

:: we can add items to the end of a list by using + symbol:

:: list_1 = #;
:: list_2 = list_1 + 5;
:: print(list_2);

:: output:
:: [
::     <INT> 5
:: ]

:: we can also define list variables by adding the items just after creating the list:

:: list = # + 1 + ( 2*(10/5)+3 ) + "some text" + 'E' + 2.71;
:: print(list);

:: output:
:: [
::     <INT> 1
::     <INT> 7
::     <STR> "some text"
::     <CHR> 'E'
::     <FLT> 2.710000
:: ]

:: we can delete items from the list by - symbol and an index value:

:: L = #+1+2+3+4+5+6+7+8;
:: L = L-6;
:: L = L-2;
:: L = L-0;
:: print(L);

:: output:
:: [
::     <INT> 2
::     <INT> 4
::     <INT> 5
::     <INT> 6
::     <INT> 8
:: ]

:: we can delete the first item by unary minus - symbol:

:: list = #+'A'+'B'+'C'+'D';
:: print(-list);
:: print(---list);         :: delete first 3 items

:: output:
:: [
::     <CHR> 'B'
::     <CHR> 'C'
::     <CHR> 'D'
:: ]
:: [
::     <CHR> 'D'
:: ]

:: we can also use unary minus - operator with strings:

:: hello = "hello world";
:: print(-hello);
:: print(------hello);

:: output:
:: ello world
:: world

:: we can multiply the strings with * symbol and a number:

:: print("-"*20);
:: print("hello"*3);

:: output:
:: --------------------
:: hellohellohello

:: we can have nested list structures:

:: a = #+1+2+3+'a'+'b';
:: b = #+"some"+"text";
:: c = #+a+b+(#+#+2.22);
:: print(c);

:: output:
:: [
::     <LST> [
::         <INT> 1      
::         <INT> 2      
::         <INT> 3      
::         <CHR> 'a'    
::         <CHR> 'b'
::     ]
::     <LST> [
::         <STR> "some"
::         <STR> "text"
::     ]
::     <LST> [
::         <LST> [
::         ]
::         <FLT> 2.220000
::     ]
:: ]

:: we can get the items by using [ ] symbols and an index value:

:: items = #+"zeroth"+"first"+"second"+"third";
:: print(items[0]);
:: print(items[3]);

:: output:
:: zeroth
:: third

:: end of tutorial
::::::::::::::::::::::::::::::::::::::::::::

:: I learned a lot in this project. Especially, about c programming. 
:: For example, we can store different types of data in only one kind of structure type, like this:
::
:: typedef struct {
::     types_enum type;
::     union {
::         int ival;
::         float fval;
::         char cval;
::         char *sval;
::         struct list_node_tag *lval;
::     };
:: } data_type;
::
:: 'type' variable shows the current type of the union and we can check the 'type' before using the value.
::
:: I used this structure in the project in order to return all different types of values (integer,
:: float, character, string, list) from the ex() function for example. Or in order to store the different
:: types of variables in only one array: var_values.
:: I used (char *) array named var_names to store the names of the variables
:: I also added linked lists as containers. I was inspired by python's list structure when adding this.
:: And, because data_type may store a list, we can have nested list structures.

:: I made the project in windows and used 'makecompiler.bat' in order to make the compiler 'mpl.exe'.
:: 'mpl.l' and 'mpl.y' files also use 'structs.h' header file to use structures I defined.

print("\nThis file is not for running, please read the comment lines in the file.\n");

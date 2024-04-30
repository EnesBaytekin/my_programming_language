var_1 = "some variable";
var_2 = 42;

list = #;
if (var_2 == var_1) {
    list = list+(-5);
} else {
    list = list+0;
}

for (i=0 : 4) {
    list = list + i;
}

b = list[0];
len = length(list);

while (not (length(list) == 0)) {
    list = -list;
    b = b+1;
}

if (b == len)
    a = "EVET";

b = -a;

:: This program does not print anything it just says OK by default if there is no syntax error.


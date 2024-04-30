text = "hello world";

list = #;
sub_list = #;
for (i=0: length(text)) {
    c = text[i];
    if (to_int(c) == 32) {
        list = list+sub_list;
        sub_list = #;
    } else {
        sub_list = sub_list+c;
    }
}
list = list+sub_list;
print(list);

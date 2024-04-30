list = #+'F'+'E'+'A'+'G'+'B'+'C'+'D';
sorted = list;

:: bubble sort

for (i=0 : length(sorted)) {
    for (j=0 : length(sorted)-1-i) {
        if (to_int(sorted[j]) > to_int(sorted[j+1])) {

            :: switch sorted[j] and sorted[j+1]
            
            :: create empty list
            switched = #;
            
            :: add the items until j
            for (k = 0 : j) {
                switched = switched+sorted[0];
                sorted = -sorted;
            }
            
            :: add 2 items in reverse order
            switched = switched+sorted[1];
            switched = switched+sorted[0];
            sorted = --sorted;

            :: add the items after j+1
            for (k = j+2 : length(list)) {
                switched = switched+sorted[0];
                sorted = -sorted;
            }

            :: update sorted
            sorted = switched;
        }
    }
}

original_string = "original list: ";
for (i = 0 : length(list))
    original_string = original_string + list[i] + " ";

sorted_string = "sorted list  : ";
for (i = 0 : length(sorted))
    sorted_string = sorted_string + sorted[i] + " ";

print(original_string);
print(sorted_string);

numbers = #+5+2+9+4+6+1+3+16+7+12+8;
numbers_copy = numbers;

max = 0;
min = 100;
while (not (length(numbers_copy) == 0)) {
    item = numbers_copy[0];
    if (item > max)
        max = item;
    else if (item < min)
        min = item;
    numbers_copy = -numbers_copy;
}

list_string = "list: ";
for (i = 0 : length(numbers))
    list_string = list_string + to_str(numbers[i]) + "  ";

print(list_string);
print("The maximum number is: "+to_str(max));
print("The minimum number is: "+to_str(min));
print("The maximum different is: "+to_str(max-min));

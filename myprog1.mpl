number_1 = 1;
number_2 = 1;

step_count = 15;

print("Fibonacci Sequence:");
print("-" * 25);

for (i=0 : step_count) {
    print("Step " + to_str(i+1) + ": \t" + to_str(number_1));
    next_value = number_1+number_2;
    number_1 = number_2;
    number_2 = next_value;
}



# Push_Swap
In this project we had to create a **Sorting Algorithm** to sort a given list of random integers (No duplicates), with the least amount of operations<br />

**For this project the following restrictions apply:**<br /><br />
-We can only use 2 Stacks for sorting<br />
-Operations are restricted to:<br />
*sa: swaps the first 2 elements in stack A*<br />
*sb: swaps the first 2 elements in stack B*<br />
*ra: rotate stack A*<br />
*rb: rotate stack B*<br />
*rab: rotate stack A and B*<br />
*rra: reverse rotate stack A*<br />
*rrb: reverse rotate stack B*<br />
*rrab: reverse rotate stack A and B*<br />
*pa: pushes the top of stack B to the top of stack A*<br />
*pb: pushes the top of stack A to the top of stack B*<br /><br />

-run the **make** rule to generate the program **push_swap**<br />
-to check the amount of operations, run:<br />
*$ARG="a set of numbers"; ./push_swap $ARG | wc -l<br />*
-to check if the program sorts properly, run:<br />
*$ARG="a set of numbers"; ./push_swap $ARG | ./checker_Mac $ARG<br />*

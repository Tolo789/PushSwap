# PushSwap
42 project: Push_swap

Objecive: This program sorts, from lower to bigger, the integers given as parameters.
The parameters given are saved as a pile (called pile A), where the first parameter given is on the top of it and the last one is on the bottom, and it is possible to use a second pile (called pile B) to help the sorting.


Only the following movements are allowed:
- sa: swap A, swaps the top two elements of the pile A;
- sb: swap B, swaps the top two elements of the pile B;
- ss: sa and sb at the same time;
- pa: push A, pushes the top element from B and puts it onto A (does nothing if B is empty);
- pb: push B, pushes the top element from A and puts it onto B (does nothing if A is empty);
- ra: rotate A, takes the top element of pile A puts it onto the bottom;
- rb: rotate B, takes the top element of pile B puts it onto the bottom;
- rr: ra and rb at the same time;
- rra: reverse rotate A, takes the element at the bottom of A and puts it onto the top;
- rrb: reverse rotate B, takes the element;at the bottom of B and puts it onto the top;
- rrr: rra and rrb at the same time.


The program will print out the moves needed to sort the given numbers.
However it is possible to enable some options (seprated by a space) by putting the following flags before giving the nubers:
- -p: prints the piles state at before starting and at the end of the sorting algorithm;
- -d: for each move printed the programs waits the user to tap "enter" before displaying the curent pile state and proceeding with the algorithm;
- -rp: prints the initial and final state plus the -d option (if enabled) putting the numbers from the bottom to the top instead of the other way round (as with -p or -d defeault);
- -t: prints the total moves done in order to sort the pile.


Between the above options and the numbers to sort, it is possible to choose wich one of the following sorting algorithm to execute:
- -a0: the first algorithm I've implemented for this project, it's an adaptation of the bubble-sort and does not need the pile B to do the sorting;
- -a1: it's an improvement of the previous algorithm, achieved by using the pile B;
- -a2: a further evolution of the previous algorithm, this time it pushes to B choosing the lower value between the top number of pile A and the bottom one;
- -a3: an adaptation of the insertion sort: takes the lower number into pile A and pushes it into pile B until either pile A is ordered or only two values are left. Then repushes all back to A;
- -a4: an adaptation of the quicksort: the pivot is the median and the 1/2 (1/7 if there are more than 400 elements on pile A) lowest numbers are pushed to B and sorted. Then they are all repushed to A.


NOTES:
- numbers lower than or bigger than an integer will not be accepted;
- the program does not accept the same number to be given more than once;
- -p, -d -rp and -t can be written as many times as you like (as long as they are put at the right position) but they behaviour will only be executed once. Moreover only -p and -rp options are not compatible and the -rp will not be considered, all others combinations will not cause problems;
- only one sorting algorithm can be selected, if not specified the -a4 option is taken as defeault;
- you can find a python script (taken from https://github.com/mokolodi1/push-swap/blob/master/tester.py) which checks the basic functionalities of the program if both put on the same folder.

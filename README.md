# Project 6

A Les Mills BODYPUMP instructor has a list of the weight plates for her classes and saved in a file. Each weight plate was stored with the weight (kg), color, and quantity. Write a program that reads in the data (a list of weight plates) from a file, and sort the plates by weight, and write the ordered list to the output file.
Assume the input file plates.txt has the format of weight (double), color (one word string), followed by quantity (int) with in the following format:

10 blue 16
1.25 purple 20
…

1. Name your program weight_plates.c.
2. Declare a plate structure containing information of a weight plate’s weight, color, and quantity. Assume that there are no more than 100 plates in the file. Assume that color is one word, and no more than 100 characters.
3. Use fscanf and fprintf to read and write data. The list of plates should be stored in an array of struct plate.
4. Modify the selection_sort function provided so that it sorts an array of plate struct. The plates should be sorted by weight in ascending order. The function should have the following prototype:
void selection_sort(struct plate array_plates[], int n);
5. Output the ordered plates in a text file called ordered_plates.txt, in the same format as the input file (with two decimal digits for weight).

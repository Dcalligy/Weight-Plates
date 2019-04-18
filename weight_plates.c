#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct plate{

    char color[MAX_LEN + 1];
    double weight;
    int quantity;
};

void selection_sort(struct plate array_plates[], int n);

int main(){

    FILE *fp;
    FILE *wfp;
    char buffer[MAX_LEN + 1]; // Buffer used to read in file
    int i, count = 0;
    struct plate plates[MAX_LEN + 1]; // Array of plates

    fp = fopen("plates.txt", "r");
    wfp = fopen("ordered_plates.txt", "w");

    if(fp == NULL){
        printf("ERROR: Cannot open file\n");
        return 1;
    }

    while(fscanf(fp, "%s", buffer) != EOF){
        // Read the weight, color and quantity
        plates[count].weight = atof(buffer);
        fscanf(fp, "%s", buffer);
        strcpy(plates[count].color, buffer);
        fscanf(fp, "%s", buffer);
        plates[count].quantity = atoi(buffer);
        count++;
    }
    
    selection_sort(plates, count);
    printf("\n\nInformation in data file in ascending order: \n\n");
    for(i = 0; i < count; i++){
       printf("%0.2f\t", plates[i].weight);
       printf("%s\t", plates[i].color);
       printf(" %d\n", plates[i].quantity);
    }
    
    // Write the data to new txt file ordered_plates.txt
    for(i = 0; i < count; i++){
        fprintf(wfp, "%0.2f\t", plates[i].weight);
        fprintf(wfp, "%s\t", plates[i].color);
        fprintf(wfp," %d\n", plates[i].quantity);
    }

    printf("\n\nFile ordered_plates.txt was written\n\n");
    fclose(fp); // Close plates.txt
    fclose(wfp); // Close the written file
    return 0;
}

void selection_sort(struct plate array_plates[], int n){

    int i, j, pos;
    struct plate temp;
    
    // Move through the unsorted array structure one by one
    for(i = 0; i < n - 1; i++){
        // Find the mininum element in the unsorted array structure
        pos = i;
        for(j = i + 1; j < n; j++){ 
            if(array_plates[pos].weight > array_plates[j].weight){
                pos = j;
            }
        }
        // Swap the found minimum element with the first element
        if(pos != i){
            temp = array_plates[i];
            array_plates[i] = array_plates[pos];
            array_plates[pos] = temp;
        }
    }
}

#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>

void writeFile (Record *records, int count) {

    FILE *outputFile = fopen("sorted.txt", "w");;

    if (outputFile == NULL) 
        return;


    fprintf(outputFile, "%d\n", count);

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d %s\n", records[i].idNumber, records[i].name);
    }

    fclose(outputFile);
    printf("Successfully saved to sorted.txt\n");

}

int main()
{
    int count, recchoice, sortchoice;
    char filename[500];

    do {

        printf("Select the record to sort:\n");
        printf("1. almostsorted.txt\n");
        printf("2. random100.txt\n");
        printf("3. random25000.txt\n");
        printf("4. random50000.txt\n");
        printf("5. random75000.txt\n");
        printf("6. random100000.txt\n");
        printf("7. totallyreversed.txt\n");
        
        printf("Input number (1-7): ");
        scanf("%d", &recchoice);

        switch (recchoice) {
            case 1:
                strcpy(filename, "data/almostsorted.txt"); 
                break;
            case 2:
                strcpy(filename, "data/random100.txt");    
                break;
            case 3:
                strcpy(filename, "data/random25000.txt");  
                break;
            case 4: 
                strcpy(filename, "data/random50000.txt");  
                break;
            case 5:
                strcpy(filename, "data/random75000.txt");  
                break;
            case 6:
                strcpy(filename, "data/random100000.txt"); 
                break;
            case 7: 
                strcpy(filename, "data/totallyreversed.txt"); 
                break;
            default:
                printf("Invalid choice.");
                recchoice = 0;
        }

    } while (recchoice < 1 || recchoice > 7);

    FILE *inputFile = fopen(filename, "r");

    if (inputFile == NULL) {
        printf("Error: Could not open %s.\n", filename);
        return 1;
    }
    fscanf(inputFile, "%d", &count);
    fclose(inputFile);

    static Record myRecords[100001];

    readFile(myRecords, filename);

    do {

        printf("Select method of sorting:\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Merge Sort\n");
        printf("4. Quick Sort\n");

        printf("Input number (1-7): ");
        scanf("%d", &sortchoice);

        long start, end;

        switch (sortchoice) {
            case 1:
                start = currentTimeMillis();
                insertionSort(myRecords, count);  
                end = currentTimeMillis();

                printf("Insertion Sort took %ld ms\n", end - start);
                writeFile(myRecords, count);
                break;
            case 2:
                start = currentTimeMillis();
                selectionSort(myRecords, count);  
                end = currentTimeMillis();

                printf("Selection Sort took %ld ms\n", end - start);
                writeFile(myRecords, count);
                break;
            case 3:
                // add part 
                break;
            case 4: 
                start = currentTimeMillis();
                quickSort (myRecords, 0, count - 1);
                end = currentTimeMillis();

                printf("Quick Sort took %ld ms\n", end - start);
                writeFile(myRecords, count);
                break;
            default:
                printf("Invalid choice.");
                sortchoice = 0;
        }

    } while (sortchoice < 1 || sortchoice > 4);


    return 0;
}
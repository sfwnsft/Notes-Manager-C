#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000000
#define FILENAME "notes.txt"

// Add a note
void addNote() {
    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char *note = (char *)malloc(MAX * sizeof(char));
    if (note == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return;
    }

    printf("Enter your note (max %d chars):\n", MAX - 1);
    getchar();
    fgets(note, MAX, stdin);

    fprintf(fp, "%s\n", note);
    fclose(fp);
    free(note);
    printf("\nNote added successfully!\n");
}

// View notes
void viewNotes() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No notes found.\n");
        return;
    }

    char *line = (char *)malloc(MAX * sizeof(char));
    if (line == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return;
    }

    printf("\nYour Notes:\n\n");
    while (fgets(line, MAX, fp)) {
        printf("%s", line);
        }
        fclose(fp);
        free(line);
}

// Search notes
void searchNotes() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No notes found.\n");
        return;
    }

    char keyword[1000];
    printf("Enter a keyword to search: ");
    scanf("%s", keyword);

    char *line = (char *)malloc(MAX * sizeof(char));
    if (line == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return;
    }

    int found = 0;
    while (fgets(line, MAX, fp)) {
        if (strstr(line, keyword)) {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found)
        printf("No matching notes found.\n");

    fclose(fp);
    free(line);
}

int main() {
    int choice;

    do {
        printf("\nNotes By Safwan Safat\n\n");
        printf("1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Search Notes\n");
        printf("4. Exit\n\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                searchNotes();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

int main() {
    char filename[] = "input.txt"; 
    char searchText[MAX_LINE];    
    char line[MAX_LINE];          

    
    printf("Enter the text to search for: ");
    fgets(searchText, sizeof(searchText), stdin);

    
    searchText[strcspn(searchText, "\n")] = '\0';

    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("File opening error");
        return 1;
    }

    printf("\nSentences that contain text \"%s\":\n", searchText);

    
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        
        line[strcspn(line, "\n")] = '\0';

        
        if (strstr(line, searchText)) {
            printf("%s\n", line);
            found = 1;
        }
    }

    if (!found) {
        printf("No sentences found.\n");
    }

    
    fclose(file);

    return 0;
}

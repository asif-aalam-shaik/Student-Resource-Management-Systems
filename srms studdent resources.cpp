#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define DEPT_LEN 30

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    float cgpa;
} Student;

typedef struct {
    Student *data;
    int top;
    int capacity;
} Stack;

void initStack(Stack *s, int capacity);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, Student st);
Student pop(Stack *s);
Student peek(Stack *s);
void displayStack(Stack *s);
void showStackState(Stack *s, const char *operationName);
void clearInputBuffer(void);
Student inputStudent(void);
void pauseScreen(void);

int main(void) {
    Stack s;
    int capacity;
    int choice;
    Student st, removed;
    int initialized = 0;

    printf("===========================================\n");
    printf("      ADVANCED STUDENT STACK SIMULATOR     \n");
    printf("===========================================\n\n");

    printf("Enter maximum number of students in stack: ");
    scanf("%d", &capacity);
    clearInputBuffer();

    if (capacity <= 0) {
        printf("Invalid capacity. Using default capacity = 5\n");
        capacity = 5;
    }

    initStack(&s, capacity);
    initialized = 1;

    while (1) {
        printf("\n-------------------------------------------\n");
        printf("                 MAIN MENU                 \n");
        printf("-------------------------------------------\n");
        printf("1. PUSH  (Insert new student)\n");
        printf("2. POP   (Remove top student)\n");
        printf("3. PEEK  (View top student)\n");
        printf("4. DISPLAY (Show all students)\n");
        printf("5. SHOW INTERNAL STATE ONLY\n");
        printf("6. EXIT\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        if (!initialized) {
            printf("Error: Stack not initialized!\n");
            break;
        }

        switch (choice) {
        case 1:
            if (isFull(&s)) {
                printf("\n[PUSH] Operation Failed: Stack OVERFLOW\n");
                showStackState(&s, "PUSH (FAILED - OVERFLOW)");
            } else {
                printf("\n--- Enter Student Details ---\n");
                st = inputStudent();
                push(&s, st);
                printf("\n[PUSH] Student with ID %d pushed on stack.\n", st.id);
                showStackState(&s, "PUSH");
            }
            pauseScreen();
            break;

        case 2:
            if (isEmpty(&s)) {
                printf("\n[POP] Operation Failed: Stack UNDERFLOW\n");
                showStackState(&s, "POP (FAILED - UNDERFLOW)");
            } else {
                removed = pop(&s);
                printf("\n[POP] Removed Student:\n");
                printf("ID        : %d\n", removed.id);
                printf("Name      : %s\n", removed.name);
                printf("Dept      : %s\n", removed.department);
                printf("CGPA      : %.2f\n", removed.cgpa);
                showStackState(&s, "POP");
            }
            pauseScreen();
            break;

        case 3:
            if (isEmpty(&s)) {
                printf("\n[PEEK] Operation Failed: Stack is EMPTY\n");
            } else {
                st = peek(&s);
                printf("\n[PEEK] Top Student Details:\n");
                printf("ID        : %d\n", st.id);
                printf("Name      : %s\n", st.name);
                printf("Dept      : %s\n", st.department);
                printf("CGPA      : %.2f\n", st.cgpa);
            }
            showStackState(&s, "PEEK");
            pauseScreen();
            break;

        case 4:
            displayStack(&s);
            showStackState(&s, "DISPLAY");
            pauseScreen();
            break;

        case 5:
            showStackState(&s, "NO OPERATION");
            pauseScreen();
            break;

        case 6:
            printf("\nExiting Advanced Student Stack Simulator. Goodbye!\n");
            free(s.data);
            return 0;

        default:
            printf("\nInvalid choice. Please try again.\n");
            pauseScreen();
            break;
        }
    }

    if (initialized) {
        free(s.data);
    }

    return 0;
}

void initStack(Stack *s, int capacity) {
    s->capacity = capacity;
    s->top = -1;
    s->data = (Student *) malloc(sizeof(Student) * capacity);

    if (s->data == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == s->capacity - 1);
}

void push(Stack *s, Student st) {
    if (isFull(s)) return;
    s->top++;
    s->data[s->top] = st;
}

Student pop(Stack *s) {
    Student dummy;
    if (isEmpty(s)) {
        dummy.id = -1;
        strcpy(dummy.name, "N/A");
        strcpy(dummy.department, "N/A");
        dummy.cgpa = 0.0f;
        return dummy;
    }
    return s->data[s->top--];
}

Student peek(Stack *s) {
    Student dummy;
    if (isEmpty(s)) {
        dummy.id = -1;
        strcpy(dummy.name, "N/A");
        strcpy(dummy.department, "N/A");
        dummy.cgpa = 0.0f;
        return dummy;
    }
    return s->data[s->top];
}

void displayStack(Stack *s) {
    int i;

    if (isEmpty(s)) {
        printf("\n[DISPLAY] Stack is EMPTY. No students to show.\n");
        return;
    }

    printf("\n[DISPLAY] Students in Stack (Top to Bottom):\n");
    printf("--------------------------------------------------------------\n");
    printf("| %-3s | %-10s | %-20s | %-6s |\n", "Pos", "ID", "Name", "CGPA");
    printf("--------------------------------------------------------------\n");

    for (i = s->top; i >= 0; i--) {
        printf("| %-3d | %-10d | %-20s | %-6.2f |\n",
               i,
               s->data[i].id,
               s->data[i].name,
               s->data[i].cgpa);
    }
    printf("--------------------------------------------------------------\n");
}

void showStackState(Stack *s, const char *operationName) {
    int i;
    int usedSlots = s->top + 1;
    int freeSlots = s->capacity - usedSlots;

    printf("\n================= INTERNAL STACK STATE =================\n");
    printf("After Operation : %s\n", operationName);
    printf("Capacity        : %d\n", s->capacity);
    printf("Current Top     : %d\n", s->top);
    printf("Used Slots      : %d\n", usedSlots);
    printf("Free Slots      : %d\n", freeSlots);

    printf("\nVisual Representation (Top at Highest Index):\n");
    printf("--------------------------------------------------------------\n");

    for (i = s->capacity - 1; i >= 0; i--) {
        if (i <= s->top) {
            printf("[Index %2d] -> ID: %-5d | Name: %-15s\n",
                   i,
                   s->data[i].id,
                   s->data[i].name);
        } else {
            printf("[Index %2d] -> (empty)\n", i);
        }
    }
    printf("--------------------------------------------------------------\n");
    printf("==============================================================\n");
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

Student inputStudent(void) {
    Student st;

    printf("Enter ID           : ");
    scanf("%d", &st.id);
    clearInputBuffer();

    printf("Enter Name         : ");
    fgets(st.name, NAME_LEN, stdin);
    st.name[strcspn(st.name, "\n")] = '\0';

    printf("Enter Department   : ");
    fgets(st.department, DEPT_LEN, stdin);
    st.department[strcspn(st.department, "\n")] = '\0';

    printf("Enter CGPA         : ");
    scanf("%f", &st.cgpa);
    clearInputBuffer();

    return st;
}

void pauseScreen(void) {
    printf("\nPress ENTER to continue...");
    getchar();
}

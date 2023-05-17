/*
 * Define a structure to represent a course with two data: the course name and the number of
participants.
 Write a program that appends to a binary file information about one course given by the user.
 In order to check the content of the created binary file,
 read all the courses from the file and then display all courses on the screen.

 Define and call a function that calculates the sum of all course participants.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIVIDER "- - - - - - - - - - - - -"
#define MAX_COURSE_NAME 101
#define COURSE_FILE "courses.dat"

struct Course {
    char name[MAX_COURSE_NAME];
    int participants;
};

void write_course_to_file(struct Course course) {
    FILE *file = fopen(COURSE_FILE, "ab");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(&course,sizeof(course),1,file);
    fclose(file);
}

int sumOfParticipants(struct Course course) {
    FILE *file = fopen(COURSE_FILE, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int sum_participants = 0;
    while(fread(&course,sizeof(course),1,file)==1){
        sum_participants += course.participants;
    }

    fclose(file);
    return sum_participants;
}

void readFromBinary(struct Course course) {
    FILE *file = fopen(COURSE_FILE, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int counter = 0;
    while(fread(&course,sizeof(course),1,file)==1){
        ++counter;
        printf("%d. %s %d\n", counter, course.name, course.participants);
    }

    fclose(file);
}


int main() {
    struct Course course;
    do {
        printf("What you want to do?\n");
        printf("(1) Add new course\n");
        printf("(2) Read all courses\n");
        printf("(3) Count the sum of participants\n");
        printf("(0) Exit program\n");

        printf("Input: ");
        int input;
        scanf("%d", &input);
        puts(DIVIDER);
        fflush(stdin);

        switch (input) {
            case 1: {
                printf("Enter course name: ");
                scanf("%100[^\n]", course.name);
                printf("Enter number of participants: ");
                scanf("%d", &course.participants);
                write_course_to_file(course);
                puts(DIVIDER);
                continue;
            }
            case 2: {
                readFromBinary(course);
                puts(DIVIDER);
                break;
            }
            case 3: {
                int sum_of = 0;
                sum_of = sumOfParticipants(course);
                printf("The total number of participants: %d\n", sum_of);
                puts(DIVIDER);
                break;
            }
            case 0: {
                printf("Bye bye!");
                puts(DIVIDER);
                exit(0);
            }

            default:
                continue;
        }

    } while (1);
}

#include <stdio.h>

// Maximum number of users, courses, and enrollments
#define MAX_USERS 100
#define MAX_COURSES 100
#define MAX_ENROLLMENTS 100

// Structs
// User struct to store user information
typedef struct {
  char name[50];
  char email[50];
  char password[20];
  char role[15]; // student/instructor
} User;

typedef struct {
  int id;
  char title[50];
  char instructorEmail[50];
} Course;

typedef struct {
  char studentEmail[50];
  int courseId;
} Enrollment;

void showMainMenu() {
  int choice;
  do {
    printf("welcome to CourseMate!\n1. Register\n2. Login\n3. Exit\n Choice:");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      // TODO: register user
      break;
    case 2:
      // TODO: login user
      break;

    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 0);
}

int main() { showMainMenu(); }
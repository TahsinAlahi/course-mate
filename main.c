#include <stdio.h>
#include <stdlib.h>

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

// Global pointers
User *users = NULL;
Course *courses = NULL;
Enrollment *enrollments = NULL;

// Global variables
int userCount = 0;

void loadUsers() {
  FILE *fp = fopen("users.txt", "r");

  if (fp == NULL) {
    printf("File not found\n");
    return;
  }

  while (fscanf(fp, "%s %s %s %s", users[userCount].name,
                users[userCount].email, users[userCount].password,
                users[userCount].role) != EOF) {
    userCount++;
    if (userCount >= MAX_USERS)
      break;
  }
  fclose(fp);
}

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

int main() {
  users = (User *)malloc(sizeof(User) * MAX_USERS);
  courses = (Course *)malloc(sizeof(Course) * MAX_COURSES);
  enrollments = (Enrollment *)malloc(sizeof(Enrollment) * MAX_ENROLLMENTS);

  if (!users || !courses || !enrollments) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // showMainMenu();

  loadUsers();

  free(users);
  free(courses);
  free(enrollments);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int courseCount = 0;
int enrollmentCount = 0;
User *currentUser = NULL;

// Utils
void clearScreen() { system("cls||clear"); }

void pause() {
  printf("\nPress Enter to continue...");
  getchar();
  getchar();
}

// Load users from file into memory
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

// Load courses from file into memory
void loadCourses() {
  FILE *fp = fopen("courses.txt", "r");

  if (fp == NULL) {
    printf("File not found.\n");
    return;
  }

  while (fscanf(fp, "%d|%49[^|]|%49[^\n]\n", &courses[courseCount].id,
                courses[courseCount].title,
                courses[courseCount].instructorEmail) != EOF) {
    courseCount++;
    if (courseCount >= MAX_COURSES)
      break;
  }

  fclose(fp);
}

// Load enrollments from file into memory
void loadEnrollments() {
  FILE *fp = fopen("enrollments.txt", "r");

  if (fp == NULL) {
    printf("File not found\n");
    return;
  }

  while (fscanf(fp, "%49[^|]|%d\n", enrollments[enrollmentCount].studentEmail,
                &enrollments[enrollmentCount].courseId) != EOF) {
    enrollmentCount++;
    if (enrollmentCount >= MAX_ENROLLMENTS)
      break;
  }

  fclose(fp);
}

// Save user to file
void saveUserToFile(User user) {
  FILE *fp = fopen("users.txt", "a");
  if (fp == NULL) {
    printf("File not found\n");
    return;
  }

  fprintf(fp, "%s %s %s %s\n", user.name, user.email, user.password, user.role);
  fclose(fp);
}

// Save course to file
void saveCourseToFile(Course course) {
  FILE *fp = fopen("courses.txt", "a");
  if (fp == NULL) {
    printf("Could not open courses.txt for appending.\n");
    return;
  }
  fprintf(fp, "%d|%s|%s\n", course.id, course.title, course.instructorEmail);
  fclose(fp);
}

// Save enrollment to file
void saveEnrollmentToFile(Enrollment enrollment) {
  FILE *fp = fopen("enrollments.txt", "a");
  if (fp == NULL) {
    printf("Could not open enrollments.txt for appending.\n");
    return;
  }
  fprintf(fp, "%s|%d\n", enrollment.studentEmail, enrollment.courseId);
  fclose(fp);
}

// Register a new user
void registerUser() {
  clearScreen();
  User user;
  printf("Enter name: ");
  scanf("%s", user.name);
  printf("Enter email: ");
  scanf("%s", user.email);
  // TODO: Check if the email is unique
  printf("Enter password: ");
  scanf("%s", user.password);
  do {
    printf("Enter role (student/instructor): ");
    scanf("%s", user.role);
  } while (strcmp(user.role, "student") != 0 &&
           strcmp(user.role, "instructor") != 0);

  users[userCount++] = user;
  saveUserToFile(user);
  printf("Register Successfully!\n");
  pause();
}

// Login a user
int loginUser() {
  clearScreen();
  char email[50], password[30];
  printf("Email: ");
  scanf("%s", email);
  printf("Password: ");
  scanf("%s", password);

  for (int i = 0; i < userCount; i++) {
    if (strcmp(users[i].email, email) && strcmp(users[i].password, password)) {
      currentUser = &users[i];
      return 1;
    } else {
      printf("Invalid email or password\n");
      return 0;
    }
  }
}

// View all courses
void viewAllCourses() {
  clearScreen();
  for (int i = 0; i < courseCount; i++) {
    printf("ID: %d | Title: %s | Instructor: %s\n", courses[i].id,
           courses[i].title, courses[i].instructorEmail);
  }
  pause();
}

// Enroll in a course
// TODO: Check this again
void enrollInCourse() {
  clearScreen();
  int id;
  viewAllCourses();
  printf("\nEnter Course ID to enroll: ");
  scanf("%d", &id);

  // Check if already enrolled
  for (int i = 0; i < enrollmentCount; i++) {
    if (strcmp(enrollments[i].studentEmail, currentUser->email) == 0 &&
        enrollments[i].courseId == id) {
      printf("Already enrolled in this course.\n");
      pause();
      return;
    }
  }

  // Enroll
  for (int i = 0; i < courseCount; i++) {
    if (courses[i].id == id) {
      Enrollment e;
      strcpy(e.studentEmail, currentUser->email);
      e.courseId = id;
      enrollments[enrollmentCount++] = e;
      printf("Enrolled successfully!\n");
      pause();
      return;
    }
  }
  printf("Invalid Course ID\n");
  pause();
}

// View student enrollments
// TODO: recheck this function
void viewStudentEnrollments() {
  clearScreen();
  printf("Your Enrollments:\n");
  for (int i = 0; i < enrollmentCount; i++) {
    if (strcmp(enrollments[i].studentEmail, currentUser->email) == 0) {
      for (int j = 0; j < courseCount; j++) {
        if (courses[j].id == enrollments[i].courseId) {
          printf("%s\n", courses[j].title);
        }
      }
    }
  }
  pause();
}

// Show student menu
void showStudentMenu() {
  int choice;
  do {
    clearScreen();
    printf("1. View Courses\n2. Enroll in Course\n3. My Enrollments\n0. "
           "Logout\nChoice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      viewAllCourses();
      break;
    case 2:
      enrollInCourse();
      break;
    case 3:
      viewStudentEnrollments();
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 0);
}

// Create a course
void createCourse() {
  clearScreen();

  if (courseCount >= MAX_COURSES) {
    printf("Maximum number of courses reached.\n");
    pause();
    return;
  }

  Course course;
  course.id = courseCount + 1;

  getchar(); // to consume leftover newline
  printf("Enter course title: ");
  fgets(course.title, sizeof(course.title), stdin);
  course.title[strcspn(course.title, "\n")] = '\0'; // Remove trailing newline
  strcpy(course.instructorEmail, currentUser->email);

  courses[courseCount++] = course;
  saveCourseToFile(course);
  printf("Course created successfully!\n");
  pause();
}

// Show instructor menu
void showInstructorMenu() {
  int choice;
  do {
    clearScreen();
    printf("Instructor Menu:\n");
    printf("1. Create Course\n2. View Courses\n0. Logout\nChoice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      createCourse();
      break;
    case 2:
      viewAllCourses();
      break;
    case 0:
      printf("Logging out...\n");
      break;
    default:
      printf("Invalid choice. Try again.\n");
      pause();
    }
  } while (choice != 0);
}

// Show main menu
void showMainMenu() {
  int choice;
  do {
    clearScreen();
    printf("Welcome to CourseMate!\n");
    printf("1. Register\n2. Login\n3. Exit\nChoice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      registerUser();
      break;
    case 2: {
      int loggedInUser = loginUser();
      if (loggedInUser) {
        if (strcmp(currentUser->role, "student") == 0) {
          showStudentMenu();
        } else {
          showInstructorMenu();
        }
      }
      break;
    }
    case 3:
      printf("Thank you for using CourseMate!\n");
      break;
    default:
      printf("Invalid choice. Try again.\n");
      pause();
    }
  } while (choice != 3);
}

int main() {
  users = (User *)malloc(sizeof(User) * MAX_USERS);
  courses = (Course *)malloc(sizeof(Course) * MAX_COURSES);
  enrollments = (Enrollment *)malloc(sizeof(Enrollment) * MAX_ENROLLMENTS);

  if (!users || !courses || !enrollments) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  loadUsers();
  loadCourses();
  loadEnrollments();

  showMainMenu();

  free(users);
  free(courses);
  free(enrollments);

  return 0;
}
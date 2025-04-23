#include <stdio.h>

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
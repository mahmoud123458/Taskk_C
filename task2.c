#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

typedef struct {
    int active;
    int flag;
} UserFlags;

int registerUser(User users[], UserFlags flags[], int numUsers) {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return numUsers;
    }

    User newUser;
    UserFlags newFlags;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    // Check if the username is already taken
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already taken. Please choose a different one.\n");
            return numUsers;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);

    printf("Enter active flag (0 or 1): ");
    scanf("%d", &newFlags.active);

    if (newFlags.active != 0 && newFlags.active != 1) {
        printf("Invalid active flag. Please enter 0 or 1.\n");
        return numUsers;
    }

    if (newFlags.active) {
        printf("Enter flag value: ");
        scanf("%d", &newFlags.flag);
    }

    users[numUsers] = newUser;
    flags[numUsers] = newFlags;
    printf("Registration successful.\n");

    return numUsers + 1;
}

int loginUser(User users[], UserFlags flags[], int numUsers) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (flags[i].active) {
                printf("Login successful. Welcome, %s!\n", users[i].username);
                return 1;
            } else {
                printf("Account is inactive. Please contact support.\n");
                return 0;
            }
        }
    }

    printf("Invalid username or password. Please try again.\n");
    return 0;
}

int main() {
    User users[MAX_USERS];
    UserFlags flags[MAX_USERS];
    int numUsers = 0;
    int loggedIn = 0;

    while (1) {
        int choice;

        printf("\n--- Menu ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numUsers = registerUser(users, flags, numUsers);
                break;
            case 2:
                loggedIn = loginUser(users, flags, numUsers);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        if (loggedIn) {
            // Perform actions for logged-in users
            // ...
            break;
        }
    }

    return 0;
}
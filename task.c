#include <stdio.h>
#include <string.h>

// Maximum number of users
#define MAX_USERS 100

// User structure
typedef struct {
    char username[20];
    char password[20];
} User;

// Array to store registered users
User users[MAX_USERS];

// Current number of registered users
int numUsers = 0;

// Function to register a new user
void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("😞 Sorry, maximum number of users reached.\n");
        return;
    }

    User newUser;
    printf("📝 Registration\n");

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[numUsers++] = newUser;

    printf("✅ Registration successful!\n");
}

// Function to login
void login() {
    char username[20];
    char password[20];
    printf("🔑 Login\n");

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("🎉 Login successful!\n");
            return;
        }
    }

    printf("❌ Invalid username or password!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n🏠 Welcome to the system!\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("👋 Exiting...\n");
                return 0;
            default:
                printf("❗ Invalid choice!\n");
                break;
        }
    }
}
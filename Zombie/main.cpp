#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Створення процесу зомбі
    pid_t child_pid = fork();

    if (child_pid < 0) {
        // Помилка у випадку невдалого fork()
        std::cerr << "Помилка створення процесу\n";
        return 1;
    } else if (child_pid == 0) {
        // Дочірній процес (зомбі)
        exit(0);
    } else {
        // Батьківський процес
        // Затримка, щоб забезпечити існування зомбі-процесу
        sleep(2);

        // Виконання команди ps для виведення інформації про процес
        std::cout << "Інформація про зомбі-процес:\n";
        std::string command = "ps -p " + std::to_string(child_pid);
        system(command.c_str());

        // Очікування завершення дочірнього процесу
        wait(nullptr);
    }

    return 0;
}

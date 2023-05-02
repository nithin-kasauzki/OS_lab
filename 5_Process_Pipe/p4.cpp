// #include <iostream>
// #include <unistd.h>
// #include <sys/wait.h>

// #define PIPE_READ_END 0
// #define PIPE_WRITE_END 1

// bool is_prime(int n) {
//     if (n <= 1)
//         return false;
//     for (int i = 2; i * i <= n; ++i)
//         if (n % i == 0)
//             return false;
//     return true;
// }

// int main() {
//     int pipe1[2], pipe2[2];
//     if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
//         std::cerr << "Pipe creation failed\n";
//         return 1;
//     }

//     pid_t child_pid = fork();
//     if (child_pid == 0) {
//         // child process
//         close(pipe1[PIPE_READ_END]);
//         close(pipe2[PIPE_WRITE_END]);

//         std::cout << "Enter N: ";
//         int N;
//         std::cin >> N;

//         for (int i = 0; i < N; ++i) {
//             int x;
//             std::cin >> x;
//             write(pipe1[PIPE_WRITE_END], &x, sizeof(x));
//             if (x % 2 == 1)
//                 write(pipe2[PIPE_WRITE_END], &x, sizeof(x));
//         }

//         close(pipe1[PIPE_WRITE_END]);
//         close(pipe2[PIPE_READ_END]);
//         return 0;
//     } else if (child_pid > 0) {
//         // parent process
//         close(pipe1[PIPE_WRITE_END]);
//         close(pipe2[PIPE_WRITE_END]);

//         int x;
//         while (read(pipe1[PIPE_READ_END], &x, sizeof(x)) > 0) {
//             if (is_prime(x)) {
//                 std::cout << x << " is prime\n";
//             }
//         }

//         close(pipe1[PIPE_READ_END]);

//         int sum = 0;
//         while (read(pipe2[PIPE_READ_END], &x, sizeof(x)) > 0) {
//             sum += x;
//         }
//         std::cout << "The sum of odd numbers is " << sum << '\n';

//         close(pipe2[PIPE_READ_END]);
//         wait(NULL);
//         return 0;
//     } else {
//         std::cerr << "Fork failed\n";
//         return 1;
//     }
// }
#include<iostream>
using namespace std;

int main(){
    system("ls");
}
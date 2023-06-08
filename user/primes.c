#include "kernel/types.h"
#include "user/user.h"

#define READ
#define WRITE

int main(int argc, char** argv) {
  for (int i = 2; i <= 35; ++i) {
    int fds[2];
    pipe(first_fds);
    close(first_fds[READ]);
    write(first_fds[WRITE], &i, 4);
    int pid = fork();
    if (pid == 0) {
      // child
    } else {

    }
  }
  exit(0);
}
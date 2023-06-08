#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv) {
  int p2c_fds[2];
  int c2p_fds[2];

  fprintf(1, "start pingpong\n");
  pipe(p2c_fds);
  pipe(c2p_fds);
  char buf[10] = {0};
  int pid = fork();
  if (pid == 0) {
    // child
    read(p2c_fds[1], buf, 1);
    fprintf(1, "%d: received ping\n", getpid());
    write(c2p_fds[0], "b", 1);
  } else {
    write(p2c_fds[0], "b", 1);
    wait(0); // need this, otherwise the output might mix up
    fprintf(1, "%d: received pong\n", getpid());
    read(c2p_fds[1], buf, 1);
  }
  exit(0);
}
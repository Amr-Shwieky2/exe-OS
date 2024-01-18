#include <signal.h>
#include <stdio.h>
#include <unistd.h>



void signal_handler(int signum) {
    sigset_t block_set;

    // Initialize the set to be empty
    sigemptyset(&block_set);
    
    sigaddset(&block_set, SIGINT);
    
    sigprocmask(SIG_BLOCK, &block_set, NULL);
    
    int i =0;
    for(i; i < 5; i++){
        puts("sh");
        sleep(1);
    }
    
    sigprocmask(SIG_UNBLOCK, &block_set, NULL);
}

int main()
{
    signal(SIGQUIT, signal_handler);
    
    int i =0;
    for(i; i < 5; i++){
        puts("main");
        
        sleep(1);    
    }
}

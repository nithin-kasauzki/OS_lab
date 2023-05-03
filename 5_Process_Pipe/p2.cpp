#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){
    pid_t p2,p3,p4,p5,p6;
    cout<<"\nProcess 1 "<<getpid()<<"  "<<getppid();
    p2 = fork();
    if(p2==0){
        //child
        cout<<"\nProcess 2 "<<getpid()<<"  "<<getppid();
        p6=fork();
        if(p6==0){
            //child
            cout<<"\nProcess 6( "<<getpid()<<"  "<<getppid();
            exit(0);

        }
        else{
            wait(NULL);
            p5 = fork();
                if(p5==0){
            //child
                cout<<"\nProcess 5( "<<getpid()<<"  "<<getppid();
                exit(0);

                 }
                 else{
                    wait(NULL);
                    wait(NULL);
                 }
                 exit(0);
        }

    }
    else{
        wait(NULL);
        p3 = fork();
        if(p3==0){
        //child
            cout<<"\nProcess 3 "<<getpid()<<"  "<<getppid();
            p4 = fork();
            if(p4==0){
            //child
                cout<<"\nProcess 4( "<<getpid()<<"  "<<getppid();
                exit(0);

            }
            else{
                wait(NULL);
                wait(NULL);
                exit(0);
            }

        }
        else{
            wait(NULL);
            wait(NULL);
            exit(0);
        }
    }
    
}

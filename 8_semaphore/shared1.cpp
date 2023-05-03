#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
    key_t key = ftok("shmfile",'A');
    int shmid = shmget(key,sizeof(int),0666);
    int *n = (int *)shmat(shmid,nullptr,0);

}
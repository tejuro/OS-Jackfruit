#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
pid_t pid1 = fork();

if (pid1 == 0){
chdir("Cotainer1");
execl("../cpu_hog","cpu_hog",NULL);
}
else{
pid_t pid2 = fork();

if (pid2 == 0){
chdir("Container3");
execl("../memory_hog", "memory_hog", NULL);
}
else{
printf("Containers running...\n");
}
}
return 0;
}
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sys/wait.h>
#include <fstream>
#include <algorithm>
using namespace std;

void setOwner() {
    execlp("chown","chown","-r","www-data:www-data","/var/www/",NULL);
    cout << "Fallo al ejecutar thread de chown" << endl;
}

void setPermissionsFolder() {
    execlp("find","find","/var/www","-type","d","-exec","chmod","755","{}","+",NULL);
    cout << "Fallo al ejecutar thread de directorios" << endl;
}

void setPermissionsFiles() {
    execlp("find","find","/var/www","-type","f","-exec","chmod","644","{}","+",NULL);
    cout << "Fallo al ejecutar thread de directorios" << endl;
}

int main() {
    int pid,pid2,pid3;
    pid = fork();
    if(pid == 0) {
        setPermissionsFiles();
        exit(0);
    } else {
        pid2 = fork();
        if(pid2 == 0) {
            setPermissionsFolder();
            exit(0);
        } else {
            pid3 = fork();
            if(pid3 == 0) {
                setOwner();
                exit(0);
            }
        }
    }
    while(waitpid(-1,NULL,WNOHANG) == 0);
    cout << "Script finalizado correctamente " << endl;
}
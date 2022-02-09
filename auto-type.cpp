#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <istream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

void prdr(int num){
    keybd_event(num,0,0,0);
    keybd_event(num,0,2,0);
    return ;
}

void shprdr(int num){
    keybd_event(16,0,0,0);
    keybd_event(num,0,0,0);
    keybd_event(num,0,2,0);
    keybd_event(16,0,2,0);
    return ;
}

FILE *find_file;
char ch;
int length;
string str,file_name("",2001);

int main(){
    printf("Please input the path of the file(at most 2000 characters) you want to type and press the [enter].\nAfter that, please wait 3 seconds, and it will start to type.\n");
    scanf("%501s",&file_name[0]);
    while (true){
        find_file = freopen(file_name.c_str(),"r",stdin);
        fclose(stdin);
        freopen("CON","r",stdin);
        if (find_file == NULL){
            printf("Sorry, but I can't find the file.\nPlease input the right path(at most 2000 characters).\n");
            file_name.clear();
            scanf("%2001s",&file_name[0]);
        }
        else{
            break;
        }
    }
    freopen(file_name.c_str(),"r",stdin);
    Sleep(3000);
    while (true){
        ch = (char)getchar();
        if (ch == EOF) break;
        if (ch == '\t') prdr(9);
        else if (ch == '\n') prdr(13);
        else if (ch == ' ') prdr(32);
        else if (isdigit(ch)) prdr((int)ch);
        else if (ch == ')') shprdr(48);
        else if (ch == '!') shprdr(49);
        else if (ch == '@') shprdr(50);
        else if (ch == '#') shprdr(51);
        else if (ch == '$') shprdr(52);
        else if (ch == '%') shprdr(53);
        else if (ch == '^') shprdr(54);
        else if (ch == '&') shprdr(55);
        else if (ch == '*') shprdr(56);
        else if (ch == '(') shprdr(57);
        else if (islower(ch)) prdr((int)ch - 32);
        else if (isupper(ch)) shprdr((int)tolower(ch) - 32);
        else if (ch == '*') prdr(106);
        else if (ch == '-') prdr(109);
        else if (ch == '/') prdr(111);
        else if (ch == ';') prdr(186);
        else if (ch == ':') shprdr(186);
        else if (ch == '=') prdr(187);
        else if (ch == ',') prdr(188);
        else if (ch == '<') shprdr(188);
        else if (ch == '_') shprdr(189);
        else if (ch == '.') prdr(190);
        else if (ch == '>') shprdr(190);
        else if (ch == '/') prdr(191);
        else if (ch == '?') shprdr(191);
        else if (ch == '`') prdr(192);
        else if (ch == '~') shprdr(192);
        else if (ch == '[') prdr(219);
        else if (ch == '{') shprdr(219);
        else if (ch == '\\') prdr(220);
        else if (ch == '|') shprdr(220);
        else if (ch == ']') prdr(221); 
        else if (ch == '}') shprdr(221);
        else if (ch == '\'') prdr(222);
        else if (ch == '"') shprdr(222);
    }
    fclose(stdin);
    return 0;
}

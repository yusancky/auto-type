#include <cctype>
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

void shiftprdr(int num){
	keybd_event(16,0,0,0);
	keybd_event(num,0,0,0);
	keybd_event(num,0,2,0);
	keybd_event(16,0,2,0);
	return ;
}

char ch;
int length;
string str;

int main(){
	Sleep(1000);
	ifstream inf;
	inf.open("input.txt");
	while (getline(inf,str)){
		length = str.length();
		for (int i = 0;i < str.length();i++){
			ch = str[i];
			if (ch == '\t') prdr(9);
			else if (ch == ' ') prdr(32);
			else if (isdigit(ch)) prdr((int)ch);
			else if (ch == ')') shiftprdr(48);
			else if (ch == '!') shiftprdr(49);
			else if (ch == '@') shiftprdr(50);
			else if (ch == '#') shiftprdr(51);
			else if (ch == '$') shiftprdr(52);
			else if (ch == '%') shiftprdr(53);
			else if (ch == '^') shiftprdr(54);
			else if (ch == '&') shiftprdr(55);
			else if (ch == '*') shiftprdr(56);
			else if (ch == '(') shiftprdr(57);
			else if (islower(ch)) prdr((int)ch - 32);
			else if (isupper(ch)) shiftprdr((int)tolower(ch) - 32);
			else if (ch == '*') prdr(106);
			else if (ch == '-') prdr(109);
			else if (ch == '/') prdr(111);
			else if (ch == ';') prdr(186);
			else if (ch == ':') shiftprdr(186);
			else if (ch == '=') prdr(187);
			else if (ch == ',') prdr(188);
			else if (ch == '<') shiftprdr(188);
			else if (ch == '_') shiftprdr(189);
			else if (ch == '.') prdr(190);
			else if (ch == '>') shiftprdr(190);
			else if (ch == '/') prdr(191);
			else if (ch == '?') shiftprdr(191);
			else if (ch == '`') prdr(192);
			else if (ch == '~') shiftprdr(192);
			else if (ch == '[') prdr(219);
			else if (ch == '{') shiftprdr(219);
			else if (ch == '\\') prdr(220);
			else if (ch == '|') shiftprdr(220);
			else if (ch == ']') prdr(221); 
			else if (ch == '}') shiftprdr(221);
			else if (ch == '\'') prdr(222);
			else if (ch == '"') shiftprdr(222);
		}
		prdr(13);
	}
	inf.close();
	return 0;
}

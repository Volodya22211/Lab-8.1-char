#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s)
{
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int pos = 0;
	char* t;

	while ((t = strchr(s + pos, '-'))) {
		pos = t - s + 1;
		count++;
	}
	while ((t = strchr(s + pos, '+'))) {
		pos = t - s + 1;
		count1++;
	}
	while ((t = strchr(s + pos, '='))) {
		pos = t - s + 1;
		count2++;
	}
	return count + count1 + count2;
}
char* Change(char* s) {
	char* t = new char[strlen(s) * 2 + 1];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = '\0';

	while ((p = strchr(s + pos1, '+'))) {
		pos2 = p - s + 1;
		strncat(t, s + pos1, pos2 - pos1 - 1);
		strcat(t, "**");
		pos1 = pos2;
	}
	while ((p = strchr(s + pos1, '-'))) {
		pos2 = p - s + 1;
		strncat(t, s + pos1, pos2 - pos1 - 1);
		strcat(t, "**");
		pos1 = pos2;
	}
	while ((p = strchr(s + pos1, '='))) {
		pos2 = p - s + 1;
		strncat(t, s + pos1, pos2 - pos1 - 1);
		strcat(t, "**");
		pos1 = pos2;
	}
	strcat(t, s + pos1);
	strcpy(s, t);

	delete[] t;

	return s;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "Number of char - or + or =: " << Count(str) << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}

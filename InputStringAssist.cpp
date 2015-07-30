#pragma once

#include "stdafx.h"
using namespace std;

#ifdef _WIN32
#define STRTOK_SAFE strtok_s
#elif __linux__
#define STRTOK_SAFE strtok_r
#else
#define STRTOK_SAFE strtok
#endif

const int MAX_LINE_SIZE = 65536;
const int SLEEP_DELAY = 3;


int getSepCharIndex(char line[], int length){
	if (length < 1){
		return -1;
	}
	int i = 0;
	for (i = 1; i < length - 1; i++){
		//int chr = line[i];
		//wcout << chr << endl;
		if (line[i] == '=' && line[i+1] == '=') {
			return i;
		}
	}
	return -1;
}

void event(int key, bool needShift = false){
	if (needShift){
		keybd_event(VK_LSHIFT, 0, 0, 0);
		Sleep(SLEEP_DELAY);
	}
	keybd_event(key, 0, 0, 0);
	Sleep(SLEEP_DELAY);
	if (needShift){
		keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0);
		Sleep(SLEEP_DELAY);
	}
	keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
	Sleep(SLEEP_DELAY);
}
void press(char a){
	if (('a' <= a) && (a <= 'z'))
	{
		event(a - 'a' + 65);
		return;
	}
	if (('A' <= a) && (a <= 'Z'))
	{
		event(a - 'A' + 65, true);
		return;
	}
	if (('0' <= a) && (a <= '9'))
	{
		event(a - '0' + 48);
		return;
	}
	switch (a){
	case '	':event(VK_TAB);
		return;
	case ',':event(VK_OEM_COMMA);
		return;
	case '.':event(VK_OEM_PERIOD); //event(VK_DECIMAL);?
		return;
	case '<':event(VK_OEM_COMMA, true);
		return;
	case '>':event(VK_OEM_PERIOD, true); //event(VK_DECIMAL);?
		return;
	case '/':event(VK_OEM_2);
		return;
	case '?':event(VK_OEM_2, true);
		return;
	case '`':event(VK_OEM_3);
		return;
	case '~':event(VK_OEM_3, true);
		return;
	case '[':event(VK_OEM_4);
		return;
	case '{':event(VK_OEM_4, true);
		return;
	case '\\':event(VK_OEM_5);
		return;
	case '|':event(VK_OEM_5, true);
		return;
	case ']':event(VK_OEM_6);
		return;
	case '}':event(VK_OEM_6, true);
		return;
	case '\'':event(VK_OEM_7);
		return;
	case '\"':event(VK_OEM_7, true);
		return;
	case '-':event(VK_OEM_MINUS);
		return;
	case '_':event(VK_OEM_MINUS, true);
		return;
	case '!':event('1', true);
		return;
	case '@':event('2', true);
		return;
	case '#':event('3', true);
		return;
	case '$':event('4', true);
		return;
	case '%':event('5', true);
		return;
	case '^':event('6', true);
		return;
	case '&':event('7', true);
		return;
	case '*':event('8', true);
		return;
	case '(':event('9', true);
		return;
	case ')':event('0', true);
		return;
	case ';':event(VK_OEM_1);
		return;
	case ':':event(VK_OEM_1, true);
		return;
	case '=':event(VK_OEM_PLUS);
		return;
	case '+':event(VK_OEM_PLUS, true);
		return;
	default:
		break;
	}

}
int main(int argc, char* argv[])
{
	/*for (int i = 0; i < argc; i++){
		printf("%s\n", argv[i]);
	}*/

	FILE* settingFile;
	char* inputFile = "InputAssistSettings.ini";
	if (fopen_s(&settingFile, inputFile, "rt") != 0){
		wcout << inputFile << "文件不存在" << endl;
		if (fopen_s(&settingFile, inputFile, "wt") != 0){
			wcout << "无法创建" << inputFile << "文件" << endl;
			return 1;
		}
		else{
			wcout << "已创建" << inputFile << "文件" << endl;
			fclose(settingFile);
			return 0;
		}
	}
	if (fopen_s(&settingFile, inputFile, "rt") != 0){
		wcout << inputFile << " file open failed." << endl;
		return 1;
	}

	if (feof(settingFile)){
		wcout << "Rules not exist in " << inputFile << "." << endl;
	}


	char* input = (char*)malloc(sizeof(char)*MAX_LINE_SIZE);
	memset(input, '\0', sizeof(char)*MAX_LINE_SIZE);
	scanf_s("%s", input, MAX_LINE_SIZE);

	char line[MAX_LINE_SIZE] = { '\0' };
	int currentIndex = 0;
	while (!feof(settingFile)){
		fgets(line, MAX_LINE_SIZE, settingFile);
		currentIndex++;
		unsigned int length = strlen(line);
		if (length < strlen("1==1")){
			continue;
		}
		int sepCharPos = getSepCharIndex(line, length);
		if (sepCharPos < 2){
			continue;
		}


		char* key = (char*)malloc(sizeof(char)*MAX_LINE_SIZE);
		memset(key, '\0', sizeof(char)*MAX_LINE_SIZE);
		left(key, line, sepCharPos);

		if (strcmp(input, key) == 0){
			char* value = (char*)malloc(sizeof(char)*MAX_LINE_SIZE);
			memset(value, '\0', sizeof(char)*MAX_LINE_SIZE);
			right(value, line, length - sepCharPos - 2);
			if (!value){ continue; }
			int valueLength = strlen(value);
			if (valueLength < 1){ continue; }

			Sleep(2000);
			for (int i = 0; i < valueLength; i++){
				//printf("%c", value[i]);
				press(value[i]);
			}


		}



	}


	fclose(settingFile);


	return 0;
}


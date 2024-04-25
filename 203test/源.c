#include<stdio.h>
#include<string.h>
#include<windows.h>

char god[] = { 14,25,8,19,26,63,36,4,15,17,8,7,39,26,29,0,10,0,28,42,18,18,28,30,8,30,69,11,8,16,1,5,54,11,25,54,5,6,30,54,6,18,28,30,8,30,20 };
char v1[] = {"welcome_to_203\n"};
char v2[] = { "It's an amazing country\n" };
char v3[] = { "A solitary old man cancer, if you can work out this problem, get the flag, miracles will happen\n" };
char grey_wolf[] = { 104,117,105,116,97,105,108,97,110,103,109,105,120,105,109,105,120,105,104,117,97,98,117,108,97,106,105,110,105,98,117,109,105,120,105,95,119,111,106,105,117,98,117,108,97,106,105 };
char str2[47];
void sub_40100() {
	printf("%s",v1);
	Sleep(1000);
	printf("%s",v2);
	Sleep(1000);
	printf("%s",v3);
	Sleep(1000);
}

void sub_401000() {

	for (int i = 0; i < strlen(str2); i++) {
		_asm
		{
			call sub10
			_emit 0xE8
			jmp label10
			sub10 :
			add dword ptr[esp], 1
				retn
				label10 :
		}
		str2[i] = str2[i] ^ grey_wolf[i];
	}
		
}
void sub_401001() {

	printf("Please input your flag: ");
	scanf_s("%s", &str2,48);
}
void sub_401002() {
	if (strncmp(str2, grey_wolf, strlen(str2)) == 0)
	{printf("Thank you, ctfer\n");
	system("pause");
}
	else {
		printf("It seems that you are not the chosen people\n");
		system("pause");
	}
	}


int main() {
	void (*fptr)() = sub_40100;
	fptr();
	sub_401001();
	fptr = sub_401000;
	fptr();
	sub_401002();
}



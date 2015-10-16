#include "common.h"

string intToStr(int iNum)
{
	char pid_ch[20];
	sprintf(pid_ch, "%d", iNum);
	string strNum(pid_ch);
	return strNum;
}

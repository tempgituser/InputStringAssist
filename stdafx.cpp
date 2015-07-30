#include "stdafx.h"


/*from:http://hddgf.blog.163.com/blog/static/1274137372010143041501/ */
/*从字符串的左边截取n个字符*/
char * left(char *dst, const char *src, int n)
{
	const char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len;
	/*p += (len-n);*/   /*从右边第n个字符开始*/
	while (n--) *(q++) = *(p++);
	*(q++) = '\0'; /*有必要吗？很有必要*/
	return dst;
}
/*从字符串的中间截取n个字符*/
char * mid(char *dst, const char *src, int n, int m) /*n为长度，m为位置*/
{
	const char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len - m;    /*从第m个到最后*/
	if (m<0) m = 0;    /*从第一个开始*/
	if (m>len) return NULL;
	p += m;
	while (n--) *(q++) = *(p++);
	*(q++) = '\0'; /*有必要吗？很有必要*/
	return dst;
}
/*从字符串的右边截取n个字符*/
char * right(char *dst, const char *src, int n)
{
	const char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len;
	p += (len - n);   /*从右边第n个字符开始*/
	while (*(q++) = *(p++));
	return dst;
}
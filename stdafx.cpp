#include "stdafx.h"


/*from:http://hddgf.blog.163.com/blog/static/1274137372010143041501/ */
/*���ַ�������߽�ȡn���ַ�*/
char * left(char *dst, const char *src, int n)
{
	const char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len;
	/*p += (len-n);*/   /*���ұߵ�n���ַ���ʼ*/
	while (n--) *(q++) = *(p++);
	*(q++) = '\0'; /*�б�Ҫ�𣿺��б�Ҫ*/
	return dst;
}
/*���ַ������м��ȡn���ַ�*/
char * mid(char *dst, const char *src, int n, int m) /*nΪ���ȣ�mΪλ��*/
{
	const char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len - m;    /*�ӵ�m�������*/
	if (m<0) m = 0;    /*�ӵ�һ����ʼ*/
	if (m>len) return NULL;
	p += m;
	while (n--) *(q++) = *(p++);
	*(q++) = '\0'; /*�б�Ҫ�𣿺��б�Ҫ*/
	return dst;
}
/*���ַ������ұ߽�ȡn���ַ�*/
char * right(char *dst, const char *src, int n)
{
	const char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len;
	p += (len - n);   /*���ұߵ�n���ַ���ʼ*/
	while (*(q++) = *(p++));
	return dst;
}
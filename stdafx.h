#pragma once

#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include<Windows.h>



/*from:http://hddgf.blog.163.com/blog/static/1274137372010143041501/ */
/*���ַ�������߽�ȡn���ַ�*/
char * left(char *dst, const char *src, int n);
/*���ַ������м��ȡn���ַ�*/
char * mid(char *dst, const char *src, int n, int m);
/*���ַ������ұ߽�ȡn���ַ�*/
char * right(char *dst, const char *src, int n);
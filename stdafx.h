#pragma once

#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include<Windows.h>



/*from:http://hddgf.blog.163.com/blog/static/1274137372010143041501/ */
/*从字符串的左边截取n个字符*/
char * left(char *dst, const char *src, int n);
/*从字符串的中间截取n个字符*/
char * mid(char *dst, const char *src, int n, int m);
/*从字符串的右边截取n个字符*/
char * right(char *dst, const char *src, int n);
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "demo_project.h"
#include "securec.h"

/*****************************************************************************
函 数 名  : TestStringFunctions
功能描述  : 测试字符串相关安全函数
输入参数  : 无
输出参数  : 无
返 回 值  : 无
*****************************************************************************/
void TestStringFunctions(void)
{
    printf("Testing string functions...\n");

    // Test strcpy_s
    char dest[50];
    const char* src = "Hello, World!";
    errno_t ret = strcpy_s(dest, sizeof(dest), src);
    if (ret == EOK) {
        printf("strcpy_s success: %s\n", dest);
    } else {
        printf("strcpy_s failed with error: %d\n", ret);
    }

    // Test strncpy_s
    char dest2[20];
    ret = strncpy_s(dest2, sizeof(dest2), src, 5);
    if (ret == EOK) {
        printf("strncpy_s success: %s\n", dest2);
    } else {
        printf("strncpy_s failed with error: %d\n", ret);
    }

    // Test strcat_s
    char dest3[50] = "Hello";
    ret = strcat_s(dest3, sizeof(dest3), ", World!");
    if (ret == EOK) {
        printf("strcat_s success: %s\n", dest3);
    } else {
        printf("strcat_s failed with error: %d\n", ret);
    }

    // Test strncat_s
    char dest4[50] = "Hello";
    ret = strncat_s(dest4, sizeof(dest4), ", World!", 2);
    if (ret == EOK) {
        printf("strncat_s success: %s\n", dest4);
    } else {
        printf("strncat_s failed with error: %d\n", ret);
    }
}

/*****************************************************************************
函 数 名  : TestMemoryFunctions
功能描述  : 测试内存相关安全函数
输入参数  : 无
输出参数  : 无
返 回 值  : 无
*****************************************************************************/
void TestMemoryFunctions(void)
{
    printf("\nTesting memory functions...\n");

    // Test memset_s
    char buffer[20];
    errno_t ret = memset_s(buffer, sizeof(buffer), 'A', 10);
    if (ret == EOK) {
        buffer[10] = '\0';
        printf("memset_s success: %s\n", buffer);
    } else {
        printf("memset_s failed with error: %d\n", ret);
    }

    // Test memcpy_s
    char src[] = "Source string";
    char dest[50];
    ret = memcpy_s(dest, sizeof(dest), src, strlen(src) + 1);
    if (ret == EOK) {
        printf("memcpy_s success: %s\n", dest);
    } else {
        printf("memcpy_s failed with error: %d\n", ret);
    }

    // Test memmove_s
    char str[] = "memmove can be very useful......";
    ret = memmove_s(str + 20, sizeof(str) - 20, str + 15, 11);
    if (ret == EOK) {
        printf("memmove_s success: %s\n", str);
    } else {
        printf("memmove_s failed with error: %d\n", ret);
    }
}

/*****************************************************************************
函 数 名  : TestFormattedIoFunctions
功能描述  : 测试格式化输入输出安全函数
输入参数  : 无
输出参数  : 无
返 回 值  : 无
*****************************************************************************/
void TestFormattedIoFunctions(void)
{
    printf("\nTesting formatted I/O functions...\n");

    // Test sprintf_s
    char buffer[50];
    int result = sprintf_s(buffer, sizeof(buffer), "Integer: %d, String: %s", 42, "test");
    if (result >= 0) {
        printf("sprintf_s success: %s\n", buffer);
    } else {
        printf("sprintf_s failed with error: %d\n", result);
    }

    // Test snprintf_s
    char buffer2[100];
    result = snprintf_s(buffer2, sizeof(buffer2), 100 - 1, "Truncated: %s", "This is a long string");
    if (result >= 0) {
        printf("snprintf_s success: %s (result: %d)\n", buffer2, result);
    } else {
        printf("snprintf_s failed with error: %d\n", result);
    }
}

/*****************************************************************************
函 数 名  : TestWideCharFunctions
功能描述  : 测试宽字符相关安全函数
输入参数  : 无
输出参数  : 无
返 回 值  : 无
*****************************************************************************/
void TestWideCharFunctions(void)
{
    printf("\nTesting wide character functions...\n");

    // Test wcscpy_s
    wchar_t dest[50];
    const wchar_t* src = L"Hello, Wide World!";
    errno_t ret = wcscpy_s(dest, sizeof(dest) / sizeof(wchar_t), src);
    if (ret == EOK) {
        wprintf(L"wcscpy_s success: %ls\n", dest);
    } else {
        printf("wcscpy_s failed with error: %d\n", ret);
    }
}

/*****************************************************************************
函 数 名  : TestTokenizationFunctions
功能描述  : 测试字符串分割安全函数
输入参数  : 无
输出参数  : 无
返 回 值  : 无
*****************************************************************************/
void TestTokenizationFunctions(void)
{
    printf("\nTesting tokenization functions...\n");

    // Test strtok_s
    char str[] = "Test,string,tokenization";
    char* context = NULL;
    char* token = strtok_s(str, ",", &context);
    printf("strtok_s tokens: ");
    while (token != NULL) {
        printf("%s ", token);
        token = strtok_s(NULL, ",", &context);
    }
    printf("\n");
}

/*****************************************************************************
函 数 名  : RunAllTests
功能描述  : 运行所有测试函数
输入参数  : 无
输出参数  : 无
返 回 值  : 无
*****************************************************************************/
void RunAllTests(void)
{
    printf("Running all securelib tests...\n");

    TestStringFunctions();
    TestMemoryFunctions();
    TestFormattedIoFunctions();
    TestWideCharFunctions();
    TestTokenizationFunctions();

    printf("\nAll tests completed.\n");
}
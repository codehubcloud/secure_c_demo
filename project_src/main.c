#include <stdio.h>
#include "demo_project.h"
#include "securec.h"

int main(void)
{
    printf("Secure C Demo Project\n");
    printf("=====================\n\n");

    // Run all tests
    RunAllTests();

    printf("\nDemo completed successfully.\n");
    return 0;
}
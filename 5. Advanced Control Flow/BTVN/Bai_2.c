#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
const char *errorCode;
enum ErrorCodes
{
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCULATION_ERROR
};
int bufStorage;

#define TRY if ((bufStorage = setjmp(buf)) == NO_ERROR)
#define CATCH(x) else if (bufStorage == x)
#define THROW(x, y) \
    y;              \
    longjmp(buf, x);

void readFile()
{
    printf("Reading file...\n");
    if (0) // Modify the condition to determine wether there is a error or not
    {
        errorCode = THROW(FILE_ERROR, "Error: File not found");
    }
    else
        printf("Read complete\n");
}

void networkOperation()
{
    printf("Connecting...\n");
    if (1) // Modify the condition to determine wether there is a error or not
    {
        errorCode = THROW(NETWORK_ERROR, "Error: Can't connect to the network");
    }
    else
        printf("Network connected\n");
}

void calculateData()
{
    printf("Calculating data...\n");
    if (1) // Modify the condition to determine wether there is a error or not
    {
        errorCode = THROW(CALCULATION_ERROR, "Error: Can't calculate the given data");
    }
    else
        printf("Data calculated\n");
}

int main()
{
    TRY
    {
        readFile();
        networkOperation();
        calculateData();
    }
    CATCH(FILE_ERROR)
    {
        printf("%s\n", errorCode);
    }
    CATCH(NETWORK_ERROR)
    {
        printf("%s\n", errorCode);
    }
    CATCH(CALCULATION_ERROR)
    {
        printf("%s\n", errorCode);
    }
    // Finish statement
    printf("Complete");
    return 0;
}
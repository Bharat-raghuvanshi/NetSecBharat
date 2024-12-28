#include <iostream>
#include <cstring>

void Function1()
{
    char buffer[10];
    const char *unsafeString = "This is an unsafe string";
    strcpy(buffer, unsafeString);
}

void Function2()
{
    char buffer[10];
    gets(buffer);
}

void Function3()
{
    char buffer[20];
    const char *safeString = "This is a safe string";
    strncpy(buffer, safeString, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
}
void Function4()
{
    char buffer[30];
    const char *safeString = "Another safe string";
    snprintf(buffer, sizeof(buffer), "%s", safeString);
    buffer[sizeof(buffer) - 1] = '\0';
}

void Function5()
{
    char buffer[10];
    const char *unsafeString = "This is an unsafe string";
    sprintf(buffer, "%s", unsafeString);
}

void Function6()
{
    char buffer[15];
    const char *safeString = "Safe with bounds checking";
    strncpy(buffer, safeString, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
}

void Function7()
{
    int num;
    scanf("%d", &num);
}

void Function8()
{
    char buffer[25];
    const char *safeString = "Another safe string with bounds checking";
    strncat(buffer, safeString, sizeof(buffer) - strlen(buffer) - 1);
}

void Function9()
{
    char dest[20] = "Destination";
    char src[] = "Source";
    strcat(dest, src);
}

void Function10()
{
    char buffer[25] = "Safe buffer";
    const char *safeString = "Appending safe string";
    strncat(buffer, safeString, sizeof(buffer) - strlen(buffer) - 1);
}
void Function11()
{
    char dest[20];
    char src[] = "Hello world";
    memcpy(dest, src, sizeof(src));
}

void Function12()
{
    char dest[20];
    char src[] = "Hello world";
    memmove(dest, src, sizeof(src));
}

void Function13()
{
    FILE *file = fopen("data.txt", "r");
    int num;
    // if (file != nullptr)
    {
        fscanf(file, "%d", &num);
        fclose(file);
    }
}

int main()
{
    char buffer[10];
    for (int i = 0; i < sizeof(buffer) - 1; ++i)
    {
        buffer[i] = 'a';
    }
    buffer[sizeof(buffer) - 1] = '\0';

    char buffer2[5];
    for (int i = 0; i <= sizeof(buffer2); ++i)
    {
        buffer2[i] = 'a';
    }
    buffer2[sizeof(buffer2) - 1] = '\0';

    char buffer3[15];
    size_t size = 10;
    if (size < sizeof(buffer3) - 1)
    {
        buffer3[size] = 'a';
    }

    char buffer4[20];
    int index = 21;
    if (index <= sizeof(buffer4))
    {
        buffer4[index] = 'a';
    }

    strncpy(buffer, "safestring", sizeof(buffer) - 1);
    snprintf(buffer, sizeof(buffer), "%s", "safestring");

    for (int i = 0; i < sizeof(buffer) - 1; ++i)
    {
        if (i < 5)
        {
            buffer[i] = 'a';
        }
    }

    for (int i = 0; i <= sizeof(buffer3); ++i)
    {
        buffer3[i] = 'a';
    }

    for (int i = 0; i < sizeof(buffer4); ++i)
    {
        buffer4[i] = 'a';
    }

    Function1();
    Function2();
    Function3();
    Function4();
    Function5();
    Function6();
    Function7();
    Function8();
    Function9();
    Function10();
    Function11();
    Function12();
    Function13();

    return 0;
}

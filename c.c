#include <stdio.h>

typedef struct data
{
    int key, value;
} Data;

Data table[27];

int hash(int x)
{
    return x % 27;
}

// function to insert data into hash table
int put(Data data)
{
    if (table[hash(data.key)].key == -1)
    {
        table[hash(data.key)] = data;
        return 1;
    }
    else
    {
        int loopCount = 0;
        int index = hash(data.key);

        while (table[index].key != data.key && table[index].key != -1)
        {
            index++;

            if (index >= 27)
            {
                if (loopCount >= 1)
                {
                    printf("Hash table is full");
                    return -1;
                }

                index = index % 27;
                loopCount++;
            }
        }

        table[index].value = data.value;
        table[index].key = data.key;
    }
}

// print the hash table
int printTable()
{
    for (int i = 0; i < 27; i++)
    {
        printf("key:%d value:%d ", table[i].key, table[i].value);
    }
    printf("\n");
}

// get value using key
int get(int key)
{
    if (table[hash(key)].key == key)
    {
        return table[hash(key)].value;
    }
    else
    {
        int loopCount = 0;
        int index = hash(key);

        while (table[index].key != key && table[index].key != key)
        {
            index++;

            if (index >= 27)
            {
                if (loopCount >= 1)
                {
                    printf("No record in hash table");
                    return -1;
                }

                index = index % 27;
                loopCount++;
            }
        }

        return table[index].value;
    }
}

int main()
{
    for (int i = 0; i < 27; i++)
    {
        table[i].key = -1;
    }

    Data data;

    for (int i = 0; i < 30; i++)
    {
        data.key = i;
        data.value = i * 23;
        put(data);
    }

    data.key = 1;
    data.value = 66666;
    put(data);

    data.key = 100;
    data.value = 77777;
    put(data);

    data.key = 28;
    data.value = 99999;
    put(data);

    data.key = 28;
    data.value = 42342;
    put(data);

    printf("%d \n", get(10));
    printf("%d \n", get(1));
    printf("%d \n", get(28));
    printf("%d \n", get(100));
    printf("%d \n", get(3424));
    printf("%d \n", get(2));

    printTable();
}
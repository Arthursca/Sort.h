#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int left_zeros(int obj_size, long num);

void insertion_sortc(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, char objs[num_obj][obj_size]);
void insertion_sortl(char* file_name ,int num_obj, int obj_size,  int obj_space, int line_size, long objs[num_obj]);
void finsertion_sortf(char* file_name, int ignore);

int left_zeros(int obj_size, long num)
{
    int i;
    if(num == 0)
    {
        return obj_size - 1;
    }
    else if (num < pow(10,obj_size))
    {
        i = left_zeros(obj_size - 1, num);
    }
    else
    {
        i = -2;
    }
    return i + 1;
}


int main()
{
    long arr[6] = {0,35,2,52,7,3};
    insertion_sortl("teste1.txt", 6,2,3,3,arr);
}


/*
 * INSERTION SORT WITH CHAR ARRAY
 */
//*****************************************************************************************************************************
void insertion_sortc(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, char objs[num_obj][obj_size])
{
    //Sort objects
    //_______________________________________________________________________________________________________________
    
    char key[obj_size];
    
    for (int i = 1, j; i < num_obj; i++) {
        memcpy(key ,objs[i], obj_size);
        j = i - 1;
        
        
        while (j >= 0 && strcmp(objs[j], key) > 0) {
            memcpy(objs[j + 1] ,objs[j], obj_size);
            j--;
        }
        memcpy(objs[j + 1], key, obj_size);
    }
    
    //_______________________________________________________________________________________________________________    

    //get new name
    //_______________________________________________________________________________________________________________
    
    char sort[] = "_sorted", txt[] = ".txt";
    char new_file[strlen(file_name) + strlen(sort) + 1];

    //copy the name without the .txt
    memcpy(new_file,file_name,strlen(file_name) - strlen(txt));
    
    //write the filename_sorted.txt
    for(int i = 0; i < strlen(sort) + strlen(txt) + 1; i++)
    {
        if(i < strlen(sort))
        {
            new_file[strlen(file_name) - strlen(txt) + i] = sort[i];
        }
        else if(i < strlen(sort) + strlen(txt))
        {
            new_file[strlen(file_name) - strlen(txt) + i] = txt[i - strlen(sort)];
        }
        else
        {
            new_file[strlen(file_name) - strlen(txt) + i] = '\0';
        }
    }

    //_______________________________________________________________________________________________________________
    
    //writes the new ordered file
    //_______________________________________________________________________________________________________________

    char enter = '\n', space = ' ';

    FILE *file = fopen(new_file, "w");

    for(int i = 0; i < num_obj; i++)
    {

        fwrite(objs[i], sizeof(objs[obj_size - 1]) , 1, file);

        if(i % line_size == line_size - 1)
        {
            fwrite(&enter, sizeof(char), 1, file);
        }
        else
        {
            for(int j = 0; j < obj_space; j++)
            {
                fwrite(&space, sizeof(char), 1, file);
            }
        }     
    }
    fclose(file);
    //_______________________________________________________________________________________________________________
}
//*****************************************************************************************************************************

/*
 * INSERTION SORT WITH LONG ARRAY
 */
//*****************************************************************************************************************************


void insertion_sortl(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, long objs[num_obj])
{
    //Sort objects
    //_______________________________________________________________________________________________________________
    
    long key;
    
    printf("%d\n", objs[1]);

    for (int i = 1, j; i < num_obj; i++) {
        key = objs[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && objs[j] > key) {
            objs[j + 1] = objs[j];
            j = j - 1;
        }
        objs[j + 1] = key;
    }
    printf("%d\n", objs[1]);
    
    //_______________________________________________________________________________________________________________    

    //get new name
    //_______________________________________________________________________________________________________________
    
    char sort[] = "_sorted", txt[] = ".txt";
    char new_file[strlen(file_name) + strlen(sort) + 1];

    //copy the name without the .txt
    memcpy(new_file,file_name,strlen(file_name) - strlen(txt));
    
    //write the filename_sorted.txt
    for(int i = 0; i < strlen(sort) + strlen(txt) + 1; i++)
    {
        if(i < strlen(sort))
        {
            new_file[strlen(file_name) - strlen(txt) + i] = sort[i];
        }
        else if(i < strlen(sort) + strlen(txt))
        {
            new_file[strlen(file_name) - strlen(txt) + i] = txt[i - strlen(sort)];
        }
        else
        {
            new_file[strlen(file_name) - strlen(txt) + i] = '\0';
        }
    }

    //_______________________________________________________________________________________________________________
    
    //writes the new ordered file
    //_______________________________________________________________________________________________________________

    char enter = '\n', space = ' ', zero = '0';

    FILE *file = fopen(new_file, "w");
    

    char tmp[20];
    int l_zero;
    
    for(int i = 0; i < num_obj; i++)
    {
        l_zero = left_zeros(obj_size, objs[i]);
        ltoa(objs[i],tmp,10);
        printf("%s\n", tmp);
        for (int j = 0; j < l_zero; j++)
        {

            fwrite(&zero, sizeof(char), 1, file);

        }

        fwrite(tmp, obj_size - l_zero, 1, file);
        
        if(i % line_size == line_size - 1)
        {
            fwrite(&enter, sizeof(char), 1, file);
        }
        else
        {
            for(int j = 0; j < obj_space; j++)
            {
                fwrite(&space, sizeof(char), 1, file);
            }
        }     
    }
    fclose(file);
    //_______________________________________________________________________________________________________________
}

//*****************************************************************************************************************************
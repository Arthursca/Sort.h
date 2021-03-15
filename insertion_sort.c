#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int left_zeros(int obj_size, long num);

int insertion_sortc(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, char objs[num_obj][obj_size]);
int insertion_sortl(char* file_name ,int num_obj, int obj_size,  int obj_space, int line_size, long objs[num_obj]);
int insertion_sortd(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, int decimal_places, double objs[num_obj]);
int insertion_sortf(char* file_name, int ignore_spaces, int ignore_line, int skip_line);


int right_zeros(int obj_size, long num)
{
    int i;
    if(num == 0)
    {
        return obj_size - 1;
    }
    else if (num < pow(10,obj_size))
    {
        i = right_zeros(obj_size, num*10);
    }
    else if (num >= pow(10,obj_size))
    {
        i = -1;
    }
    return i + 1;
}

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

int counter = 0;

int main()
{
    double arr3[6] = {40.11,20.45,09.35,65.24,12.98,15.00};
    insertion_sortd("tested.txt", 6,2,3,3,6, arr3);
    

    long arr[50] = {40,33,90,97,34,48,98,60,11,51,42,26,70,6,45,79,95,99,86,89,6,74,29,68,41,48,15,81,83,56,64,22,89,54,18,22,1,16,82,12,66,24,38,35,30,83,13,24,81,98};
    insertion_sortl("teste1.txt", 50,2,3,10,arr);
    
    char arr1[6][3] = {"001","abc","cds","asd","bcc", "052"};
    insertion_sortc("teste.txt",6,3,2,4,arr1); 
}


/*
 * INSERTION SORT WITH CHAR ARRAY
 */
//*****************************************************************************************************************************
int insertion_sortc(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, char objs[num_obj][obj_size])
{
    //Sort objects
    //_______________________________________________________________________________________________________________
    
    char key[obj_size];
    
    for (int i = 1, j; i < num_obj; i++) {
        counter++;
        memcpy(key ,objs[i], obj_size);
        j = i - 1;
        
        
        while (j >= 0 && strcmp(objs[j], key) > 0) {
            counter++;
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
        counter++;
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
        counter++;

        fwrite(objs[i], sizeof(objs[obj_size - 1]) , 1, file);

        if (i % line_size == line_size - 1 && i != num_obj - 1)
        {
            fwrite(&enter, sizeof(char), 1, file);
        }
        else if (i != num_obj - 1)
        {
            for(int j = 0; j < obj_space; j++)
            {
                counter++;
                fwrite(&space, sizeof(char), 1, file);
            }
        }     
    }
    
    fclose(file);
    //_______________________________________________________________________________________________________________
    
    printf("%d\n",counter);
    int steps = counter;
    counter = 0;
    return steps;
}
//*****************************************************************************************************************************

/*
 * INSERTION SORT WITH LONG ARRAY
 */
//*****************************************************************************************************************************

int insertion_sortl(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, long objs[num_obj])
{
    counter = 0;
    //Sort objects
    //_______________________________________________________________________________________________________________
    
    long key;

    for (int i = 1, j; i < num_obj; i++) {
        counter++;
        key = objs[i];
        j = i - 1;
 
        while (j >= 0 && objs[j] > key) {
            counter++;
            objs[j + 1] = objs[j];
            j = j - 1;
        }
        objs[j + 1] = key;
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
        counter++;
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
        counter++;
        l_zero = left_zeros(obj_size, objs[i]);
        ltoa(objs[i],tmp,10);
        for (int j = 0; j < l_zero; j++)
        {
            counter++;
            fwrite(&zero, sizeof(char), 1, file);
        }

        fwrite(tmp, obj_size - l_zero, 1, file);
        
        if(i % line_size == line_size - 1 && i != num_obj - 1)
        {
            fwrite(&enter, sizeof(char), 1, file);
        }
        else if(i != num_obj - 1)
        {
            for(int j = 0; j < obj_space; j++)
            {
                counter++;
                fwrite(&space, sizeof(char), 1, file);
            }
        }     
    }
    fclose(file);
    //_______________________________________________________________________________________________________________
    printf("%d\n",counter);
    int steps = counter;
    counter = 0;
    return steps;
}

//*****************************************************************************************************************************

/*
 * INSERTION SORT WITH DOUBLE ARRAY
 */
//*****************************************************************************************************************************

int insertion_sortd(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, int decimal_places, double objs[num_obj])
{
    counter = 0;
    //Sort objects
    //_______________________________________________________________________________________________________________
    
    double key;
    
    for (int i = 1, j; i < num_obj; i++) {
        counter++;
        key = objs[i];
        j = i - 1;
 
        
        while (j >= 0 && objs[j] > key) {
            counter++;
            objs[j + 1] = objs[j];
            j = j - 1;
        }
        objs[j + 1] = key;
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
        counter++;
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

    char enter = '\n', space = ' ', zero = '0', dot = '.';

    FILE *file = fopen(new_file, "w");
    


    long integer, decimal;
    char tmp[20];
    int l_zero, r_zero;
    
    for(int i = 0; i < num_obj; i++)
    {
        counter++;
        //integer part
        integer = (long) objs[i];
        l_zero = left_zeros(obj_size, integer);
        ltoa(integer,tmp,10);
        for (int j = 0; j < l_zero; j++)
        {
            counter++;
            fwrite(&zero, sizeof(char), 1, file);
        }
        fwrite(tmp, obj_size - l_zero, 1, file);

        fwrite(&dot, sizeof(char), 1, file);

        //decimal part
        decimal  = round((objs[i] - integer)*10000);
        r_zero = right_zeros(decimal_places, decimal);
        printf("%d\n", r_zero);
        ltoa(decimal,tmp,10);
        
        fwrite(tmp, decimal_places - r_zero, 1, file);
        
        for (int j = 0; j < r_zero; j++)
        {
            counter++;
            fwrite(&zero, sizeof(char), 1, file);
        }

        if(i % line_size == line_size - 1)
        {
            fwrite(&enter, sizeof(char), 1, file);
        }
        else
        {
            for(int j = 0; j < obj_space; j++)
            {
                counter++;
                fwrite(&space, sizeof(char), 1, file);
            }
        }     
    }
    fclose(file);
    //_______________________________________________________________________________________________________________
    printf("\n%d\n",counter);
    int steps = counter;
    counter = 0;
    return steps;
}

//*****************************************************************************************************************************
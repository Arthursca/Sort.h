#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, char objs[num_obj][obj_size]);
void finsertion_sort(char* file_name, int ignore);




int main()
{
    char arr[6][3] = {"abc","acr", "bbc", "bab", "aae", "001"};
    insertion_sort("teste.txt", 6,3,3,3,arr);
}

void insertion_sort(char* file_name ,int num_obj, int obj_size, int obj_space, int line_size, char objs[num_obj][obj_size])
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
    //_______________________________________________________________________________________________________________
}
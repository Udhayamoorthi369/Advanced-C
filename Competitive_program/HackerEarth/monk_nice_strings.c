/**
 * @author Udhayamoorthi
 * @email udhayamoorthi651@gmail.com 
 * @problem_id monk-and-nice-strings-3
 **/

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    char **words = (char **)malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++){
        words[i] = (char *)malloc(11 * sizeof(char));
        scanf("%s", words[i]);
    }
    for(int i = 0; i < n; i++){
        int res = 0;
        for(int j = 0; j < i; j++){
            if(strcmp(words[j], words[i]) < 0){
                res += 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

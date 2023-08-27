#include <stdio.h>
#include <string.h>

int L_head = 0;
int L_neck = 0;
int L_bicep = 0;
int L_tricep = 0;
int L_forearm = 0;
int L_shoulder = 0;
int L_back = 0;
int L_thigh = 0;
int L_calf = 0;
int L_fleg= 0;
int R_head = 0;
int R_neck = 0;
int R_bicep = 0;
int R_tricep = 0;
int R_forearm = 0;
int R_back = 0;
int R_thigh = 0;
int R_calf = 0;
int R_fleg = 0;
int L_eyelid = 0;
int R_eyelid = 0;


const char *body_parts[] = {
    "L_head", "L_neck", "L_bicep", "L_tricep", "L_forearm", "L_shoulder", "L_back",
    "L_thigh", "L_calf", "L_fleg", "R_head", "R_neck", "R_bicep","R_eyelid",
    "R_tricep", "R_forearm", "R_back", "R_thigh", "R_calf", "R_fleg", "L_eyelid"
};

int *part_varr[] = {
    &L_head, &L_neck, &L_bicep, &L_tricep, &L_forearm, &L_shoulder, &L_back,
    &L_thigh, &L_calf, &L_fleg, &R_head, &R_neck, &R_bicep, &R_tricep, &R_forearm,
    &R_back, &R_thigh, &R_calf, &R_fleg, &R_eyelid, &L_eyelid,
};
void save_values() {
    FILE *file = fopen("body_part_values.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < sizeof(body_parts) / sizeof(body_parts[0]); i++) {
        fprintf(file, "%s %d\n", body_parts[i], *part_varr[i]);
    }

    fclose(file);
}
void load_values() {
    FILE *file = fopen("body_part_values.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char body_part_name[20];
    int value;

    while (fscanf(file, "%s %d", body_part_name, &value) == 2) {
        for (int i = 0; i < sizeof(body_parts) / sizeof(body_parts[0]); i++) {
            if (strcmp(body_part_name, body_parts[i]) == 0) {
                *part_varr[i] = value;
                break;
            }
        }
    }

    fclose(file);
}

void print_values() {
    for (int i = 0; i < sizeof(body_parts) / sizeof(body_parts[0]); i++) {
        printf("%s: %d\n", body_parts[i], *part_varr[i]);
    }
}

int main() {
    load_values();
    char get_inputu[20];
    
    while (1) {
        print_values();
        printf(" input body part || exit to exit ): ");
        scanf("%s", get_inputu);
        
        if (strcmp(get_inputu, "exit") == 0) {
            save_values();
            break;
        }
        
        int found = 0;
        for (int i = 0; i < sizeof(body_parts) / sizeof(body_parts[0]); i++) {
            if (strcmp(get_inputu, body_parts[i]) == 0) {
                (*part_varr[i])++;
                printf("%s +1 1.\n\n", get_inputu);
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("wrong brother\n\n");
        }
    }
    
    return 0;
}
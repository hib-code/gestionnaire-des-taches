#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

char tasks[MAX_TASKS][50];  // Tableau pour stocker les t�ches
int num_tasks = 0;  // Nombre actuel de t�ches

void addTask() {
    if (num_tasks < MAX_TASKS) {  // V�rifie si la liste de t�ches n'est pas pleine
        printf("Entrez la nouvelle t�che : ");
        scanf("%s", tasks[num_tasks]);  // Ajoute une nouvelle t�che � la liste
        num_tasks++;
        printf("T�che ajout�e avec succ�s !\n");
    } else {
        printf("La liste de t�ches est pleine. Supprimez une t�che pour en ajouter une nouvelle.\n");
    }
}

void removeTask() {
    if (num_tasks == 0) {
        printf("Aucune t�che � supprimer.\n");
    } else {
        printf("Liste des t�ches :\n");
        for (int i = 0; i < num_tasks; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);  // Affiche la liste des t�ches avec leur num�ro
        }
        int task_to_remove;
        printf("Entrez le num�ro de la t�che � supprimer : ");
        scanf("%d", &task_to_remove);

        if (task_to_remove > 0 && task_to_remove <= num_tasks) {
            for (int i = task_to_remove - 1; i < num_tasks - 1; i++) {
                strcpy(tasks[i], tasks[i + 1]);  // Supprime la t�che en d�calant les t�ches suivantes
            }
            num_tasks--;
            printf("T�che supprim�e avec succ�s !\n");
        } else {
            printf("Num�ro de t�che invalide.\n");
        }
    }
}

void displayTasks() {
    if (num_tasks == 0) {
        printf("Aucune t�che � afficher.\n");
    } else {
        printf("Liste des t�ches :\n");
        for (int i = 0; i < num_tasks; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);  // Affiche la liste des t�ches avec leur num�ro
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Ajouter une t�che\n");
        printf("2. Supprimer une t�che\n");
        printf("3. Afficher les t�ches\n");
        printf("4. Quitter\n");
        printf("Choisissez une action : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                exit(0);  // Quitte le programme
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    }

    return 0;
}

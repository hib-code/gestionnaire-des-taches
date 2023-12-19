#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

char tasks[MAX_TASKS][50];  // Tableau pour stocker les tâches
int num_tasks = 0;  // Nombre actuel de tâches

void addTask() {
    if (num_tasks < MAX_TASKS) {  // Vérifie si la liste de tâches n'est pas pleine
        printf("Entrez la nouvelle tâche : ");
        scanf("%s", tasks[num_tasks]);  // Ajoute une nouvelle tâche à la liste
        num_tasks++;
        printf("Tâche ajoutée avec succès !\n");
    } else {
        printf("La liste de tâches est pleine. Supprimez une tâche pour en ajouter une nouvelle.\n");
    }
}

void removeTask() {
    if (num_tasks == 0) {
        printf("Aucune tâche à supprimer.\n");
    } else {
        printf("Liste des tâches :\n");
        for (int i = 0; i < num_tasks; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);  // Affiche la liste des tâches avec leur numéro
        }
        int task_to_remove;
        printf("Entrez le numéro de la tâche à supprimer : ");
        scanf("%d", &task_to_remove);

        if (task_to_remove > 0 && task_to_remove <= num_tasks) {
            for (int i = task_to_remove - 1; i < num_tasks - 1; i++) {
                strcpy(tasks[i], tasks[i + 1]);  // Supprime la tâche en décalant les tâches suivantes
            }
            num_tasks--;
            printf("Tâche supprimée avec succès !\n");
        } else {
            printf("Numéro de tâche invalide.\n");
        }
    }
}

void displayTasks() {
    if (num_tasks == 0) {
        printf("Aucune tâche à afficher.\n");
    } else {
        printf("Liste des tâches :\n");
        for (int i = 0; i < num_tasks; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);  // Affiche la liste des tâches avec leur numéro
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Ajouter une tâche\n");
        printf("2. Supprimer une tâche\n");
        printf("3. Afficher les tâches\n");
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
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}

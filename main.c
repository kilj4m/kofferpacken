#include <stdio.h>
#include <malloc.h>

typedef struct listnode{
    char data[15];
    struct listnode *nextnode;
}node;

char *fillarray(char *element, node *newnode){
    int i = 0;
    while(element[i] != NULL){
        newnode->data[i] = element[i];
        i++;
    }
    newnode->data[i]=NULL;
    return newnode;
}

char *addelement( char *element, node *koffer){

    node *current = koffer;
    node *newnode = (node *) malloc(sizeof(node));

    newnode = fillarray(element, newnode);

    if(koffer == NULL){
        newnode->nextnode = koffer;
        return  newnode;
    }
    else{

        while(current->nextnode != NULL){
            current = current->nextnode;
        }

        newnode->nextnode = current->nextnode;
        current->nextnode = newnode;
    }
    return koffer;
}


int *ueberpruefung(char *wort, node *koffer, int el){
    node *current = koffer;
    int i=0;
    while(el>0){
        koffer = koffer->nextnode;
        el--;
    }
    while(*wort == koffer->data[i]){

        if(*wort == NULL && koffer->data[i] == NULL){
            return  0;
        }
        wort++;
        i++;
    }
    return 1;
}

void terminalreset(int zeilen){
    while (zeilen>0){
        printf("\n");
        zeilen--;}
}

int main() {

    node *koffer = NULL;
    char eingabe[10] = "";
    char test[10] = "";
    int n = 0;

    int gameover = 0;
    int count = 0;
    int el = 0;
    int weiter;
    int probe;
    int level;


    //intro

    printf("\n");
    printf("\n");
    printf("Herzlich Wilkommen bei Ich packe meinen Koffer! \n");
    printf("\n");
    printf("\n");
    printf("->Waehlen sie ein Level aus. \n");
    printf("->Tippe 1 (leicht) oder 2 (schwer) in die Konsole ein:\n");
    scanf("%d", &level);
    terminalreset(100);



    //hauptspiel

    if (level == 1){

    while (gameover == 0) {
        printf("-> Ich packe in meinen Koffer ein(e): \n");
        scanf("%s", &eingabe);
        terminalreset(100);
        koffer = addelement(eingabe, koffer);
        count++;
        int curr = count;
        el = 0;
        while (curr > 0) {
            printf("-> In meinem Koffer ist ein(e): \n [Hint: %d Gegensaende im Koffer]\n", count);
            scanf("%s", &test);
            terminalreset(100);
            gameover = ueberpruefung(test, koffer, el);
            curr--;
            el++;
        }
        if (gameover == 1) {
            printf("Leider hat deine Reihenfolge nicht gestimmt! Nochmal spielen? (weiter 1 nein 0)\n");
            scanf("%d", &weiter);
            terminalreset(100);

            if (weiter == 1) {
                gameover = 0;
                el = 0;
                curr = 0;
                count = 0;
            }
        }
    }}

    else{
        while (gameover == 0) {
            printf("-> Ich packe in meinen Koffer ein(e): \n");
            scanf("%s", &eingabe);
            terminalreset(100);

            koffer = addelement(eingabe, koffer);
            count++;
            int curr = count;
            el = 0;
            while (curr > 0) {
                printf("-> In meinem Koffer ist ein(e): \n");
                scanf("%s", &test);
                terminalreset(100);

                gameover = ueberpruefung(test, koffer, el);
                curr--;
                el++;
            }
            if (gameover == 1) {
                printf("Leider hat deine Reihenfolge nicht gestimmt! Nochmal spielen? (weiter 1 nein 0)\n");
                scanf("%d", &weiter);
                terminalreset(100);

                if (weiter == 1) {
                    gameover = 0;
                    el = 0;
                    curr = 0;
                    count = 0;
                }
            }

        }
    }
    return 0;
}


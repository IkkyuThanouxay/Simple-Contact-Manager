#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* コンタクトデータを保持する構造体を定義する */
typedef struct {
    char* Name;                 //名前と電話番号のために動的に割り当てられた文字列へのポインタ
    char * TelephoneNumber;
} Contact_Data;


Contact_Data** table;           //Contact_Dataへのポインタの動的に割り当てられた配列へのポインタ
int StartIndex = 0;             //配列 'table' 内の次に埋められる位置のカウンタ

void InputContact();                        //新しい連絡先を入力するための関数
void PrintContact(Contact_Data * Data);     //連絡先を出力するための関数


int main(){
    int numberofcontacts;
    printf("Enter the number of contacts: ");
    scanf("%d", &numberofcontacts);             //入力する連絡先の数を読み込む
    getchar();                                  //入力バッファ内に残っている改行文字を消費する

    /* Contact_Dataへのポインタのために 'numberofcontacts' の数だけメモリを割り当てる */
    table = (Contact_Data**)malloc(sizeof(Contact_Data*) * numberofcontacts);

    /* 連絡先を入力する */
    for (int i = 0; i < numberofcontacts; i++) {
        InputContact();
    }

    /* 連絡先を出力する */
    for (int i = 0; i < StartIndex; i++) {
        PrintContact(table[i]);
    }

    /* 連絡先と配列 'table' のために割り当てられたメモリを解放する */
    for (int i = 0; i < StartIndex; i++) {
        free(table[i]->Name); 
        free(table[i]->TelephoneNumber); 
    }
    free(table);

    return 0;
}

void InputContact(){
    int buffersize = 50;                                    // 入力バッファの初期サイズ
    /* 名前と電話番号のためのメモリを割り当てる */
    char* name = calloc(buffersize, sizeof(char));
    char* telephonenumber = calloc(buffersize, sizeof(char));
    int input;
    int len = 0;

    /* メモリの割り当てが成功したかどうかを確認する */
    if( name==NULL || telephonenumber==NULL){
        fprintf(stderr, "Memory inefficiency\n");
        return;
    }
    
    /* 新しいContact_Data構造体のためのメモリを割り当てる */
    table[StartIndex] = (Contact_Data*)malloc(sizeof(Contact_Data));

    /* メモリの割り当てが成功したかどうかを確認する */
    if( table[StartIndex] == NULL ){
        fprintf(stderr, "Memory inefficiency\n");
        return ;
    }

    /* 連絡先の名前と電話番号を入力する */
    if(table[StartIndex]){
        printf("Enter Name: ");
        while( (input = getchar()) != '\n' && input != EOF){
            name[len++] = input;

            /* 入力バッファが一杯になったら、バッファのサイズを2倍にする */
            if(len == buffersize){
                buffersize *= 2;
                name = realloc(name, buffersize);
                if(name == NULL){
                    fprintf(stderr, "Memory inefficiency\n");
                    return ;
                }
            }
        }
        name[len] = '\0';

        len = 0;
        buffersize = 50;
        printf("Enter Phone Number: ");
        while( (input = getchar()) != '\n' && input != EOF){
            telephonenumber[len++] = input;

            /* 入力バッファが一杯になったら、バッファのサイズを2倍にする */
            if(len == buffersize){
                buffersize *= 2;
                telephonenumber = realloc(telephonenumber, buffersize);
                if(telephonenumber == NULL){
                    fprintf(stderr, "Memory inefficiency\n");
                    return ;
                }
            }
        }
        telephonenumber[len] = '\0';
        
        /* 入力された名前と電話番号をContact_Data構造体に割り当てる */
        table[StartIndex]->Name = name;
        table[StartIndex]->TelephoneNumber = telephonenumber;
        StartIndex++;           //'table' 配列内の位置のカウンタを増やす
        putchar('\n');
    }
}
void PrintContact(Contact_Data * Data){
    printf("\n\n");
    /* 名前と電話番号がnullでなければ出力する */
    if (Data->Name != NULL || Data->TelephoneNumber != NULL ){
        printf("Name: %s\nPhone Number: %s\n\n", Data->Name, Data->TelephoneNumber);
    }
    else{
        fprintf(stderr, "Null pointer encountered\n");
    }
}
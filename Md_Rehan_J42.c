#include<stdio.h>

char player1[20];
char player2[20];

char* get_name(int turn){

    if(turn == 1){
        return player1;
    }else{
        return player2;
    }

}

void display(char arr[], int turn){

    printf("    %c | %c | %c\n", arr[0], arr[1], arr[2]);
    printf("    __________\n");
    printf("    %c | %c | %c\n", arr[3], arr[4], arr[5]);
    printf("    __________\n");
    printf("    %c | %c | %c\n\n", arr[6], arr[7], arr[8]);
    printf("%s's turn : ", get_name(turn));

}

void change_turn(int* prevTurn){

    if(*prevTurn == 1){
        *prevTurn = 2;
    }else{
        *prevTurn = 1;
    }

}

int check_input(int inp, char arr[]){

    if((inp <= 9) && (inp >= 1) && (arr[inp - 1] != 'X') && (arr[inp - 1] != 'O')){
        return 1;
    }else{
        return 0;
    }

}

char get_token(int num){

    if(num == 1){
        return 'X';
    }else{
        return 'O';
    }

}

int check_win(char arr[]){

    if(arr[0] == arr[1] && arr[1] == arr[2]){
        return 1;
    }
    else if(arr[3] == arr[4] && arr[4] == arr[5]){
        return 1;
    }
    else if(arr[6] == arr[7] && arr[7] == arr[8]){
        return 1;
    }
    else if(arr[0] == arr[3] && arr[3] == arr[6]){
        return 1;
    }
    else if(arr[1] == arr[4] && arr[4] == arr[7]){
        return 1;
    }
    else if(arr[2] == arr[5] && arr[5] == arr[8]){
        return 1;
    }
    else if(arr[0] == arr[4] && arr[4] == arr[8]){
        return 1;
    }
    else if(arr[2] == arr[4] && arr[4] == arr[6]){
        return 1;
    }else{
        return 0;
    }

}

void play(char arr[]){

    int turns = 0;
    int turn = 1;

    while(turns < 9){
        display(arr, turn);

        int n;
        scanf("%d", &n);
        printf("\n");

        if(!check_input(n, arr)){
            printf("Please Enter The Correct Input\n");
            continue;
        }

        char token = get_token(turn);
        arr[n-1] = token;

        if(check_win(arr)){
            printf("%s Won!!!\n", get_name(turn));
            return;
        }
        turns++;
        change_turn(&turn);
    }

    printf("Its A Draw...");
}

void main(){
    char arr[] = {'1','2','3','4','5','6','7','8','9'};

    printf("Player 1 : X\n");
    printf("Player 2 : O\n");

    printf("Enter The Name Of Player 1 : ");
    fgets(player1, 20, stdin);   
    printf("Enter The Name Of Player 2 : ");
    fgets(player2, 20, stdin);

    play(arr);
}
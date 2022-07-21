#include <stdio.h>
int main(void){
    char letter;
    char string[100];
    int a,j,m,row,column,x=1,y=1,sum=0,g,f,r,t,ro,co,p,z,money,loop=1;
    int amount;
    if(x==1){
        scanf("%d %d",&row,&column);
        char ar[row][column];
        int array[row][column];
        for(j=0;j<row;j++){
            if(j==0){
                for(a=0;a<column;a++){
                    if(a==column-1){
                        ar[j][a]='*';
                        break;    
                    }
                    else{
                        ar[j][a]='*';
                    }
                }
            }
            else if(j==(row-1)){
                for(a=0;a<column;a++){
                    if(a==column-1){
                        ar[j][a]='*';
                        break;  
                    }
                    else{
                        ar[j][a]='*';
                        continue;
                    }
                }
            }
            else{
                for(m=0;m<column;m++){
                    if (m==0){
                        ar[j][m]='*';
                        continue;
                    }
                    if(m==(column-2)){
                        ar[j][m]=' ';
                        ar[j][column-1]='*';
                        break;
                    }
                    else{
                        ar[j][m]=' ';
                        continue;
                    }
                }
            }
        }
        while (y=1){
            scanf("%s",string);
            if(string[0]=='s'){
                scanf("%d %d",&ro,&co);
                ar[ro][co]='O';
                g=ro;
                f=co;
                continue;
            }
            if(string[0]=='f'){
                scanf("%d %d",&ro,&co);
                ar[ro][co]=' ';
                p=ro;
                z=co;
                continue;
            }
            if(string[0]=='b'){
                scanf("%d %d",&ro,&co);
                ar[ro][co]='*';
                continue;
            }
            if(string[0]=='$'){
                scanf("%d %d %d",&ro,&co,&amount);
                ar[ro][co]='$';
                array[ro][co]=amount;
                continue;
            }
            if(string[0]=='X'){
                scanf("%d %d",&ro,&co);
                ar[ro][co]='X';
                continue;
            }
            if(string[0]=='e' && string[1]=='n' && string[2]=='d'){
                for(int r=0;r<row;r++) {
                    for(int t=0;t<column;t++){
                        if(t==(column-1)){
                            printf("%c\n",ar[r][t]);
                        }
                        else{
                            printf("%c",ar[r][t]);
                        }
                    }
                }
		        printf("\n");
                y+=1;
                break;
            }
        }
        while(scanf("%c",&letter)!=EOF){
            if(letter=='d'){
                if(ar[(g+1)][f]=='*'){
                    printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
		            printf("\n");	
                    continue;
                }
                else if(ar[(g+1)][f]=='$'){
                    money = array[(g+1)][f];
                    printf("YOU GOT %d $.\n",money);
                    sum +=money;
                    ar[g][f]=' ';
                    g=g+1;
                    ar[g][f]='O';
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
		            printf("\n");
                    continue;
                }
                else if(ar[(g+1)][f]=='X'){
                    printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
			
                    }
                    printf("\n");
                    loop=2;
                    y+=1;
                    break;
                }
                else if(ar[g+1][f]==' '){
                    ar[g][f]=' ';
                    g=g+1;
                    ar[g][f]='O';
                    if(g==p && f==z){
                        printf("CONGRATS! YOU GOT %d BONUS:)\n",sum);
                        for(int r=0;r<row;r++) {
                            for(int t=0;t<column;t++){
                                if(t==(column-1)){
                                    printf("%c\n",ar[r][t]);
                                }
                                else{
                                    printf("%c",ar[r][t]);
                                }
                            }
                        }
                        printf("\n");
                        loop=2;
                        y+=1;
                        break;
                    }
                    else{
                        for(int r=0;r<row;r++) {
                            for(int t=0;t<column;t++){
                                if(t==(column-1)){
                                    printf("%c\n",ar[r][t]);
                                }
                                else{
                                    printf("%c",ar[r][t]);
                                }
                            }
                        }
                        printf("\n");
                        continue;
                    }
                }   
            }
            else if(letter=='r'){
                if(ar[g][(f+1)]=='*'){
                    printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    continue;
                }
                else if(ar[g][(f+1)]=='$'){
                    money = array[g][(f+1)];
                    printf("YOU GOT %d $.\n",money);
                    sum +=money;
                    ar[g][f]=' ';
                    f=f+1;
                    ar[g][f]='O';
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    continue;
                }
                else if(ar[g][(f+1)]=='X'){
                    printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    loop=2;
                    y+=1;
                    break;
                }
                else if(ar[g][(f+1)]==' '){
                    ar[g][f]=' ';
                    f=f+1;
                    ar[g][f]='O';
                    if(g==p && f==z){
                        printf("CONGRATS! YOU GOT %d BONUS:)\n",sum);
                        for(int r=0;r<row;r++) {
                            for(int t=0;t<column;t++){
                                if(t==(column-1)){
                                    printf("%c\n",ar[r][t]);
                                }
                                else{
                                    printf("%c",ar[r][t]);
                                }
                            }
                        }
                        printf("\n");
                        loop=2;
                        y+=1;
                        break;
                    }
                    else{
                        for(int r=0;r<row;r++) {
                            for(int t=0;t<column;t++){
                                if(t==(column-1)){
                                    printf("%c\n",ar[r][t]);
                                }
                                else{
                                    printf("%c",ar[r][t]);
                                }
                            }
                        }
                        printf("\n");
                        continue;
                    }
                }   
            }
            else if(letter=='u'){
                if(ar[(g-1)][f]=='*'){
                    printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    continue;
                }
                else if(ar[(g-1)][f]=='$'){
                    money = array[(g-1)][f];
                    printf("YOU GOT %d $.\n",money);
                    sum +=money;
                    ar[g][f]=' ';
                    g=g-1;
                    ar[g][f]='O';
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    continue;
                }
                else if(ar[(g-1)][f]=='X'){
                    printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    loop=2;
                    y+=1;
                    break;
                }
                else if(ar[(g-1)][f]==' '){
                    ar[g][f]=' ';
                    g=g-1;
                    ar[g][f]='O';
                    if(g==p && f==z){
                        printf("CONGRATS! YOU GOT %d BONUS:)\n",sum);
                        for(int r=0;r<row;r++) {
                            for(int t=0;t<column;t++){
                                if(t==(column-1)){
                                    printf("%c\n",ar[r][t]);
                                }
                                else{
                                    printf("%c",ar[r][t]);
                                }
                            }
                        }
                        printf("\n");
                        loop=2;
                        y+=1;
                        break;
                    }
                    else{
                        for(int r=0;r<row;r++) {
                            for(int t=0;t<column;t++){
                                if(t==(column-1)){
                                    printf("%c\n",ar[r][t]);
                                }
                                else{
                                    printf("%c",ar[r][t]);
                                }
                            }
                        }
                        printf("\n");
                        continue;
                    }
                }   
            }
            else if(letter=='l'){
                if(ar[g][(f-1)]=='*'){
                    printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    continue;
                }
                else if(ar[g][(f-1)]=='$'){
                    money = array[g][(f-1)];
                    printf("YOU GOT %d $.\n",money);
                    sum +=money;
                    ar[g][f]=' ';
                    f=f-1;
                    ar[g][f]='O';
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    continue;
                }
                else if(ar[g][(f-1)]=='X'){
                    printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
                    for(int r=0;r<row;r++) {
                        for(int t=0;t<column;t++){
                            if(t==(column-1)){
                                printf("%c\n",ar[r][t]);
                            }
                            else{
                                printf("%c",ar[r][t]);
                            }
                        }
                    }
                    printf("\n");
                    loop=2;
                    y+=1;
                    break;
                }
                else if(ar[g][(f-1)]==' '){
                    ar[g][f]=' ';
                    f=f-1;
                    ar[g][f]='O';
                    if(g==p && f==z){
                        printf("CONGRATS! YOU GOT %d BONUS:)\n",sum);
                        for(int r=0;r<row;r++) {
                            for(int t=0;t<column;t++){
                                if(t==(column-1)){
                                    printf("%c\n",ar[r][t]);
                                }
                                else{
                                    printf("%c",ar[r][t]);
                                }
                            }
                        }
                        printf("\n");
                        loop=2;
                        y+=1;
                        break;
                    }
                    else{
                        for(int r=0;r<row;r++) {
                            for(int t=0;t<column;t++){
                                if(t==(column-1)){
                                    printf("%c\n",ar[r][t]);
                                }
                                else{
                                    printf("%c",ar[r][t]);
                                }
                            }
                        }
                        printf("\n");
                        continue;
                    }
                }   
            }
            else if(letter=='q'){
                printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
                for(int r=0;r<row;r++) {
                    for(int t=0;t<column;t++){
                         if(t==(column-1)){
                             printf("%c\n",ar[r][t]);
                         }
                         else{
                             printf("%c",ar[r][t]);
                         }
                     }
                }
                printf("\n");
                loop=2;
                y+=1;
                break;
            }
          
        }
        if(letter!='q' && loop!=2){
            printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
            for(int r=0;r<row;r++) {
                for(int t=0;t<column;t++){
                    if(t==(column-1)){
                        printf("%c\n",ar[r][t]);
                    }
                    else{
                        printf("%c",ar[r][t]);
                    }
                }
            }
            printf("\n");
        }
        x+=1;

    }
    return 0;
}



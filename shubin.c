 #include <stdio.h>
 #include <windows.h>
 void greet(char name[],char dec1);
 int main()
 {  
    char name[10];
    char dec1;
    printf("whats your name homie?\n");
    scanf("%s",name);

    getchar();

    printf("Nice name!! \n And whats your religion?\n");
    scanf("%c",&dec1);
   greet(name,dec1);
   Beep(100, 500);

 }  

 void greet(char name[],char dec1){
    if(dec1 == 'm'){
        printf("Asslamu Alaikum brother,%s",name);
    }
    else if (dec1 == 'h')
    {
        printf("Namashkar,%s dada sob valo to??",name);
    }
    else if (dec1 == 'c')
    {
        printf("Holy moly,%s ,lord save you brother",name);
    }
     else if (dec1 == 'j')
    {
        printf("whassup mr,%s asshole",name);
    }
    else{
        printf("you better change your religion nigga");
    }
    
 }
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int is_num(char *arg){
    /*if(arg == NULL)
        printf("null geldi");
    else{
        printf("%s\n",arg);
    }*/
    int flag;
    int i;
    
    flag = 0;
    i = 0 ;
    
    if (arg[i] == '-')
        i++;
    if(arg[i] == '\0')  //argüman olarak "-" gönderildiğinde flag 1 olsun diye
        flag = 1;
    while (arg[i] != '\0'){
        if (arg[i] < '0' || arg[i] > '9')
            flag = 1;
        i++;
    }
    return (flag);
}

static int is_exist(char **args){
    
    int temp1;
    int temp2;
    int i;
    int j;
  
    temp1 = 0;
    temp2 = 0;
    i = 0;
    j = 0;
    
    while(args[i] != NULL){ //tüm sayıları gezeceğiz.
        temp1 = ft_atoi(args[i]);
        j = i + 1;
        while(args[j] != NULL){ //bulunduğumuz sayıyı tüm sayılarla karşılaştıracağız
            temp2 = ft_atoi(args[j]);
            if (temp1 == temp2) //i != j && eklenebilir
                return (1);
            j++;
        }
        i++;
    }
    return (0); //satır yetmediği için (25 satırı geçiyor) devamını başka fonksiyona aktardık.
}


void ft_control2(char *str){

    char **args;
    int is_num_flag;
    int is_exist_flag;
    int i;
    
    args = ft_split(str, ' '); // split kendi icinde null durumunu kontrol ediyor dolayisiyla null kontrolu yapmaya gerek yok ? //tüm argümanları ayırdık.
    is_num_flag = 0;
    is_exist_flag = 0;
    i = 0;
    
    
    while(args[i] != NULL){ //tüm argümanlar için sayı olup olmadıklarını kontrol ediyoruz.
        if (is_num(args[i]) == 1) //1 ise sayı değildir. içinde harf veya noktalama işareti vs. bulunuyor demektir.
            is_num_flag = 1; 
        i++;    
    }
    is_exist_flag = is_exist(args);
    free(str); //tüm argümanları tek string haline getirdik , bunu kullandık ve artık ihtiyacımız yok dolayısıyla free'ledik.
    ft_control3(is_num_flag, is_exist_flag,args); //satır yetmediği için (25 satırı geçiyor) devamını başka fonksiyona aktardık.
}


void ft_join1(int argc, char **argv, int total_size){

    char *str;
    int i;
    int j;
    int k;
    
    str = (char *)malloc(sizeof(char) *total_size + 1 + 10000000000 +(argc -1 -1)); //fazladan yer ayırmak sorun olur mu burada ? str ye atacağım argümanların boyutu tam doğru hesaplanıyor mu ? //argümanlar birleşirken aralarına boşluk koymak için argc -1 -1 ekledik.
    if (str == NULL)  //gerekli mi
         exit (0);
    i = 1;
    j = 0;
    
    while(i < argc){
        k = 0;
        while(argv[i] != NULL && argv[i][k] != '\0'){
            str[j] = argv[i][k++];
            j++;
    }
    if (i != argc - 1) //son argümanı eklerken sona space koymasın.
        str[j++] = ' ';
     // boşluk ekledikten sonra döngüye girerken doğru konumda olmak için.   str [j++] yaptık 
    i++;
  }
    str[j] = '\0';
    ft_control2(str); //satır yetmediği için (25 satırı geçiyor) devamını başka fonksiyona aktardık.
}

void ft_control (int argc , char **argv){

    int i;
    int j;
    int flag;
    int size;

    i = 1;
    size = 0;

    while (i < argc){
        j = 0;
        flag = 0;
        while(argv[i] != NULL && argv[i][j] != '\0'){
            if ((argv[i][j] != 32) && (argv[i][j] != '\t')) //gönderilen argümanların sadece space ,tab  ve space + tab olup olmadığını kontrol ediyoruz.
                flag = 1;
            size++;
            j++;
        }
        if (flag == 0) //flag == 0 ise argüman tamamen space , tab veya space + tab'dır.
            print_error();  //free gerekli mi ?
        size--; // \0 saymasin birleştirirken ekleyeceğiz 
        i++;
    }
    
    ft_join1(argc, argv, size);  //satır yetmediği için (25 satırı geçiyor) devamını başka fonksiyona aktardık.
}


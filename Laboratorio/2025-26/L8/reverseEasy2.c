void reverse (char * s, char * t){
    int i = 0, j = 0;
    int cont = 0;
    while(*(s+i) != '\0')
        i++; 
    while((t[j] = s[i - 1])){
        j++;
        i--;
        cont++;
    }
}


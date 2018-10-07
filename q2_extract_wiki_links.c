#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*decides whether the string has the pattern of the wiki website,
 returns 0 if false, 1 if true*/
int containString(char* line, char *phrase);
int isTheSite(char *line){
    char *t;
    /*search for <a href="/wiki/"  */
    int i1 = containString(line,"<a href=\"/wiki/");
    int i2 = containString(line,"title=");
    int i3 = containString(line,"</a>");


    if(i1*i2*i3 !=0){
        return 1;
    }

    return 0;
}

int containString(char* line, char *phrase){
    char *ret;

    ret = strstr(line,phrase);

    if(!ret){
        return 0;
    }else{
        return 1;
    }
}


void getName(char *line){
    int i=0;
    //puts("running the first for loop");
    for(i; line[i+5]!='\0';i++){
        //puts("222\n");
        //printf("%c",line[6]);
        if (line[i]=='w'&&line[i+1] =='i' && line[i+2] =='k' &&line[i+3] =='i' &&line[i+4] =='/'){
            int j=i+5;

            //puts("running the second for loop");
            while( line[j] !='"'&&line[j]!='\0'){
                printf("%c",line[j]);
                j++;
            } 
            
            printf("\n");
            break;

        }

       
        
    }
}

int main(int argc, char* argv[]){
  FILE *fp = fopen(argv[1] , "r" );
  if( !fp ) return -1;
  
  fseek( fp, 0, SEEK_END );
  int size = ftell( fp );
  rewind(fp);
  
  char array[size+1];
  fread( array, 1, size+1, fp );
  
  int this_line_start=0;
  char *copy;
  copy = (char *)malloc(size);
  int sz=0;
  for( int pos=0; pos<size; pos++ ){
    sz++;
    if(  array[pos] == '\n' ){
        //puts("1");
       array[pos] = '\0';
       int a=0;
       for(a;a<sz;a++){
           copy[a]=array[pos+a];
       }
//test
    


//
      int i = isTheSite(array + this_line_start);
      //printf("%d",i);

      
      if(i==1){
          //puts("here is the website\n");
          getName(array+this_line_start);
      }
          
          this_line_start=pos+1;
    }

    sz=0;
  }
}
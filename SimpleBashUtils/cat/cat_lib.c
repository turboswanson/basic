#include "cat_lib.h"

void parser(int argc, char *argv[], opt * options)
{
    int x = 0;

    const char *shorts = "+benstvET";
    const struct option longs[] = {
        {"number-nonblank",no_argument,NULL,'b'},
        {"number",no_argument,NULL,'n'},
        {"squeeze-blank",no_argument,NULL,'s'},
        {NULL,no_argument,NULL,0}
    };

    int index;

    while((x = getopt_long(argc,argv,shorts,longs,&index)) != -1)
    {
        switch(x)
        {
            case 'b' :
                 options->b = 1;break;
            case 'e' :
                 options->e = 1;
                 options->v = 1; break;
            case 'v' :
                 options->v = 1;break;
            case 'n' :
                 options->n = 1;break;
            case 's' :
                 options->s = 1;break;
            case 't' : 
                options->t = 1;
                options->v = 1; break;
            case 'E' :
                 options->E = 1;break;
            case 'T' :
                 options->T = 1;break;
            default:
                fprintf(stderr,"cat: invalid option --'%c'\n",x);break;     
                    
        }
    }
}


void cat(int z,char *argv[], opt options)
{
     FILE *f = fopen(argv[z],"r");
     
     if(!f)
     {
          fprintf(stderr,"cat: %s : No such file or directory\n",argv[z]);

          
     }

     else
     {
          char c;
          int count = 0,counter_check = 0;

          while((c = getc(f)) != EOF)
          {           
               if(options.b)
               {
                    if(c != '\n')
                    {
                         if(counter_check == 0)
                         {
                              printf("%6d  ",++count);
                              counter_check = 1;
                         }

                    }

                    else
                    {
                         counter_check = 0;
                    }
               }

               else if (options.n)
               {
                    if(counter_check == 0)
                    {
                         printf("%6d  ",++count);
                         counter_check = 1;
                    }
                    
                    if(c == '\n')
                    {
                         counter_check = 0;
                    }
               }
               printf("%c",c);
          }

          fclose(f);
     }
}


#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <sys/stat.h>

off_t fsize(const char *filename) {
    struct stat st;

    if (stat(filename, &st) == 0)
        return st.st_size;

    return -1;
}

char * strsep(char **sp, char *sep){
    char *p, *s;
    if (sp == NULL || *sp == NULL || **sp == '\0') return(NULL);
    s = *sp;
    p = s + strcspn(s, sep);
    if (*p != '\0') *p++ = '\0';
    *sp = p;
    return(s);
}
int main()
{
   FILE *fp;
   char *linha;
   char *arquivo;
   char *arquivo_copy;
   char *token;
   int tamanho[9];
   int i;

   for (i=0;i<10;i++) {
        tamanho[i] = 0;
   }

   /* opening file for reading */
   fp = fopen("routes.dat" , "rb");
   if(fp == NULL)
   {
      perror("Erro abrindo arquivo");
      return(-1);
   }

   off_t filesize = fsize("routes.dat");

   arquivo = malloc((sizeof(char) * filesize) + 1) ;
   arquivo_copy = malloc((sizeof(char) * filesize) + 1);
   size_t lido = fread(arquivo, sizeof(char), (sizeof(char) * filesize) + 1, fp);
   arquivo[lido] = '\0';
   fclose(fp);
   memcpy(arquivo_copy, arquivo, sizeof(char) * filesize);

   linha = strsep(&arquivo, "\n");
   while (linha != NULL) {
      i = 0;

      token = strsep(&linha, ",");
      while (token != NULL) {
        if (strlen(token) > tamanho[i]) {
               tamanho[i] = strlen(token);
	      }
        token = strsep(&linha, ",");
        i++;
      }
      linha = strsep(&arquivo, "\n");
   }


   for (i=0;i<10;i++) {
        printf("%i --> %i \n", i, tamanho[i]);
   }

   FILE *outfile;
   outfile = fopen("routes.out", "w");

   int padLen, toklen;

   linha = strsep(&arquivo_copy, "\n");
   while (linha != NULL) {
      i = 0;
      token = strsep(&linha, ",");
      while (token != NULL) {
          toklen = strlen(token);
          if (token[toklen-1] == '\r') {
              token[toklen-1] = '\0';
          }
	        padLen = tamanho[i] - toklen;
	        if(padLen < 0) padLen = 0;
	        fprintf(outfile,"%s%*.*s", token, padLen, padLen, " ");
          token = strsep(&linha, ",");
	       i++;
        if (token != NULL) {
           fprintf(outfile,",");
        }
      }
      linha = strsep(&arquivo_copy, "\n");
      fprintf(outfile,"\n");
   }
   fclose(outfile);
   free(arquivo);
   free(arquivo_copy);
   return(0);
}

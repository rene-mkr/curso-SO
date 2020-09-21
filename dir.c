#include <stdio.h>
#include <dirent.h>

int main() {
   struct s_dir {
	   int tipo;
	   char *nombre;
   } res[128];

   DIR *dir = opendir(".");
   struct dirent *dp;
   int i=0;
   while((dp=readdir(dir)) != NULL) {
      res[i].tipo = dp->d_type;
      res[i].nombre=dp->d_name;
      i++;
   }
   for(int j=0; j<i; j++) {
	  if (res[j].tipo == DT_DIR) {
		 printf("D ");
	  }
	  else {
		 printf("F ");
	  }
      printf("%s\n",res[j].nombre);
   }

   closedir(dir);
   return 0;
}

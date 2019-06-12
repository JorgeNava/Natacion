#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    struct registro {
     int nombre;
	 int edad;
	 };
	 struct registro punt;
	 struct registro *sptr=&punt;
	 
int main()
{
	 
  printf("Ingresa el nombre\t");
  scanf("%d",&(sptr->nombre));
  printf("Ingresa la edad\t");
  fflush(stdin);
    scanf("%d",&(sptr->edad));
	
	
  return 0;
}
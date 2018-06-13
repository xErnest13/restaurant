#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

struct mese{
  int nr;
  int locuri;
  int pret;
  int rez;
  struct mese*urm;
 } ;
 typedef struct mese Tnod;
 typedef Tnod *ref;
 ref p,q,r,h,n,rc;

 struct rezervari{
  int pretMasa;
  char nume[30];
  int nrMasa;
  char telefon[30];
  char  cnp[30];
  int loc;
  struct rezervari*urm2;
  struct rezervari*prec2;
 };
 typedef struct rezervari Tnod2;
 typedef Tnod2 *ref2;
   ref2 p2,q2,r2,h2,n2,hn,rr,t,i,j;
void citFis(){
  FILE *out1;
  char *p1; char*p22; char *p3; char s[31],ss[31],sss[31]; char s2[31]; char s3[31]; char s4[31];
  out1=fopen("rez.txt","rt");
  fflush(stdin);
  fseek(out1,0,0);
  while(!feof(out1)){
     if(p2==NULL){
  p2=(ref2)malloc(sizeof(Tnod2));
  fgets(s,31,out1);
 char s2[31]={""};
  p1=strtok(s," \n");
  strcat(s2,p1);
 while(p1)
 {
  p1=strtok(NULL," \n");
  if(p1!=NULL){
   strcat(s2," ");
   strcat(s2,p1);
  }
}
  strcpy(p2->nume,s2);

  fgets(ss,31,out1);
  strtok(ss," \n");
  strcpy(p2->telefon,ss);

  fgets(sss,31,out1);
  strtok(sss,"\n");
  strcpy(p2->cnp,sss);

  fscanf(out1,"%d\n",&p2->pretMasa);
  fscanf(out1,"%d\n",&p2->loc);
  fscanf(out1,"%d\n",&p2->nrMasa);

   p2->urm2=NULL;
   p2->prec2=NULL;
   h2=p2;
    }
  else{
  fflush(stdin);
  r2=(ref2)malloc(sizeof(Tnod2));
  fgets(s,31,out1);
  char s2[31]={""};
  p1=strtok(s," \n");
  strcat(s2,p1);
 while(p1)
 {
  p1=strtok(NULL," \n");
  if(p1!=NULL){
   strcat(s2," ");
   strcat(s2,p1);
  }
}
  strcpy(r2->nume,s2);

  fgets(ss,31,out1);
  strtok(ss,"\n");
  strcpy(r2->telefon,ss);

  fgets(sss,31,out1);
  strtok(sss,"\n");
  strcpy(r2->cnp,sss);

  fscanf(out1,"%d\n",&r2->pretMasa);
  fscanf(out1,"%d\n",&r2->loc);
  fscanf(out1,"%d\n",&r2->nrMasa);


  r2->prec2=p2;
  p2->urm2=r2;
  r2->urm2=NULL;
  p2=r2;
  }
 }
 fclose(out1);
 FILE *out2=fopen("masa.txt","rt");
 while(!feof(out2))
 {
   if(p==NULL){
  p=(ref)malloc(sizeof(Tnod));
  fscanf(out1,"%d\n",&p->nr);
  fscanf(out1,"%d\n",&p->locuri);
  fscanf(out1,"%d\n",&p->pret);
  fscanf(out1,"%d\n",&p->rez);
   p->urm=NULL;
   h=p;
 }
 else{
  r=(ref)malloc(sizeof(Tnod));
  fscanf(out1,"%d\n",&r->nr);
  fscanf(out1,"%d\n",&r->locuri);
  fscanf(out1,"%d\n",&r->pret);
  fscanf(out1,"%d\n",&r->rez);
  p->urm=r;
  r->urm=NULL;
  p=r;
  }
 }
 fclose(out2);
 }
 void scrie1(void)
 {
   fflush(stdin);
   r=h;
   printf("\n");
   while(r!=NULL)
   {
       printf("    nr. Mesei :%d locuri: %d pretul: %d RON  stare: %d\n",r->nr,r->locuri,r->pret,r->rez);
       r=r->urm;
   }
 }
 void scrie2(void)
 {
   fflush(stdin);
   rr=p2;
   while(rr!=NULL)
   {
       printf("%s\n%s\n%s\n%d\n%d\n%d\n\n",rr->nume,rr->telefon,rr->cnp,rr->loc,rr->pretMasa,rr->nrMasa);
       rr=rr->prec2;
   }
 }
 void anuRez(void){
   char pl[31],cl[31];  float s=1;
   fflush(stdin);
     puts("  Numele: ");gets(pl);
     puts("  Cnp-ul: ");gets(cl);
     rr=h2;
     while((strcmp(rr->nume,pl)!=0)&&(strcmp(rr->cnp,cl)!=0)&&(rr!=NULL))
          rr=rr->urm2;
   s=(rr->loc)*(rr->pretMasa);
   fflush(stdin);
   printf("  Clientul %s trebuie sa plateaca suma de :%.2f lei\n",rr->nume,s);
   n=(ref)malloc(sizeof(Tnod));
   fflush(stdin);
   n->nr=rr->nrMasa;
   n->locuri=rr->loc;
   n->pret=rr->pretMasa;
   n->rez=0;
   r->urm=n;
   n->urm=NULL;
   r=n;
   free(rr);
   FILE *out1=fopen("masa.txt","a");
   fprintf(out1,"%d\n",n->nr);
   fprintf(out1,"%d\n",n->locuri);
   fprintf(out1,"%d\n",n->pret);
   fprintf(out1,"%d\n",n->rez);
   fclose(out1);
   FILE *out2=fopen("rez.txt","wt");
   t=h2;
   while(t!=NULL){
    fprintf(out2,"%s\n",t->nume);
    fprintf(out2,"%s\n",t->telefon);
    fprintf(out2,"%s\n",t->cnp);
    fprintf(out2,"%d\n",t->pretMasa);
    fprintf(out2,"%d\n",t->loc);
    fprintf(out2,"%d\n",t->nrMasa);
    t=t->urm2;
 }
  fclose(out2);
  if(rr->prec2!=NULL &&rr->urm2!=NULL)
  { rr->urm2->prec2=rr->prec2;
    rr->prec2->urm2=rr->urm2;
    free(rr);
   }
  else
    if(rr->prec2==NULL&&rr->urm2!=NULL)
    {
      h2=h2->urm2;
      h2->prec2=NULL;
      rr=NULL;
      free(rr);
    }
   else
      if(rr->prec2!=NULL &&rr->urm2==NULL)
   {
      p2=p2->prec2;
      p2->urm2=NULL;
      rr=NULL;
      free(rr);
   }
  else
  {
    h2=p2=NULL;
    free(h2);
  }
 }
 void cauta1(char s[])
  {
   rr=h2; int ok=0;
   while((rr!=NULL) && (ok==0))
    {
        if(strcmp(rr->nume,s)==0)
        {
            ok=1;
            break;
        }
        rr=rr->urm2;
    }
  if(ok==1)
  {
    printf("  Datele lui sunt urmatoarele:\n");
    printf("\n   Nr telefon: %s\n  Cnp: %s\n  Pret masa: %d\n  locuri ocupate: %d%\n  Nr masa: %d\n\n",rr->telefon,rr->cnp,rr->pretMasa,rr->loc,rr->nrMasa);
  }
  else
    printf("  Nu se mai afla persoana respectiva in data de baza!\n");
  }

 void cauta2(char s[])
  {
   rr=p2; int ok=0;
   while((rr!=NULL) &&(ok==0))
    {
     if(strcmp(rr->nume,s)==0)
        {
            ok=1;
            break;
        }
          rr=rr->prec2;
    }
  if(ok==1)
  {
    printf("\n  Nr telefon: %s\n  Cnp: %s\n  Pret masa: %d\n  locuri ocupate: %d%\n  Nr masa: %d\n\n",rr->telefon,rr->cnp,rr->pretMasa,rr->loc,rr->nrMasa);
  }
  else
    printf("  Nu se mai afla persoana respectiva in data de baza!\n");
  }
 void cautaNume()
{
    char s[31];
    fflush(stdin);
    printf("  Cine este clientul respectiv:");gets(s);
    if((s[0]>=65) && (s[0]<=78))
    {
        cauta1(s);}
    else
    {
        cauta2(s);}
}
void abc()
 {
  int aux,aux2,aux3; char aux4[0],aux5[0],aux6[0];
  for(i=h2;i!=NULL;i=i->urm2)
    for(j=i->urm2;j!=NULL;j=j->urm2)
      if(strcmp(i->nume,j->nume)>0)
  {
      aux=i->pretMasa;
      i->pretMasa=j->pretMasa;
      j->pretMasa=aux;

      aux2=i->nrMasa;
      i->nrMasa=j->nrMasa;
      j->nrMasa=aux2;

      aux3=i->loc;
      i->loc=j->loc;
      j->loc=aux3;

      strcpy(aux4,i->nume);
      strcpy(i->nume,j->nume);
      strcpy(j->nume,aux4);

      strcpy(aux5,i->telefon);
      strcpy(i->telefon,j->telefon);
      strcpy(j->telefon,aux5);

      strcpy(aux6,i->cnp);
      strcpy(i->cnp,j->cnp);
      strcpy(j->cnp,aux6);
  }

 }
 void rezi()
{
  int l,e=0,ok=0;
  fflush(stdin);
  printf("  Cate locuri vret? : ");scanf("%d",&l);
  r=h;
  while((r!=NULL )&&(ok==0))
   {

     if((r->locuri==l))
  {
      printf("  Am gasit cu atatea locuri!\n");
      ok=1;
      break;
  }
  r=r->urm;
   }
   if(ok)
   {
  n2=(ref2)malloc(sizeof(Tnod2));
  fflush(stdin);
  puts("  Numele dvs.: ");gets(n2->nume);
  puts("  CNP: ");gets(n2->cnp);
  puts("  Nr. de telefon: ");gets(n2->telefon);
  n2->loc=l;
  n2->pretMasa=r->pret;
  n2->nrMasa=r->nr;
  n2->prec2=p2;
  r2->urm2=n2;

  n2->urm2=NULL;
  p2=n2;

 r->nr=r->urm->nr;
 r->locuri=r->urm->locuri;
 r->pret=r->urm->pret;
 r->rez=r->urm->rez;
 r->urm=r->urm->urm;
 r=NULL;
 free(r);

 FILE *out2=fopen("rez.txt","a");
 fprintf(out2,"%s\n",n2->nume);
 fprintf(out2,"%s\n",n2->telefon);
 fprintf(out2,"%s\n",n2->cnp);
 fprintf(out2,"%d\n",n2->pretMasa);
 fprintf(out2,"%d\n",n2->loc);
 fprintf(out2,"%d\n",n2->nrMasa);
 fclose(out2);
 FILE *out1=fopen("masa.txt","wt");
 rc=h;
 while(rc!=NULL)
 {
     fprintf(out1,"%d\n",rc->nr);
     fprintf(out1,"%d\n",rc->locuri);
     fprintf(out1,"%d\n",rc->pret);
     fprintf(out1,"%d\n",rc->rez);
     rc=rc->urm;
     }
     fclose(out1);
   }
   else
     printf("  Nu s-a gasit masa libera cu cerinta data!\n");
}typedef int tipel;
struct nod
{
 tipel cheie;
 struct nod *st, *dr;
};
typedef struct nod Tnod3;
typedef Tnod3 *ref3;
ref3 radacina;

ref3 Arbore(int N)
{
  int NS, ND;
  ref3 nod_nou;
  if(N==0)
    return NULL;
  else
  {
    NS=N/2;
    ND=N-NS-1;
    nod_nou=(ref3)malloc(sizeof(Tnod3));
    printf("  Care mese vreti sa modificati?: \n"); scanf("%d", &nod_nou->cheie);
    nod_nou->st=Arbore(NS);
    nod_nou->dr=Arbore(ND);
    return nod_nou;
  }
}

void inordine(ref3 t, int nivel)
{
 if(t!=NULL)
 {
 inordine(t->st, nivel+1);
 printf("%d",t->cheie);
 inordine(t->dr, nivel+1);
 }
}

void preordine(ref3 t, int nivel)
{
 if(t!=NULL)
{
printf("%d",t->cheie);
preordine(t->st, nivel+1);
preordine(t->dr, nivel+1);
 }
}

void postordine(ref3 t, int nivel)
{
 if(t!=NULL)
 {
postordine(t->st, nivel+1);
postordine(t->dr, nivel+1);
printf("%d",t->cheie);
 }
}

void Tiparire(ref3 anod, int nivel)
{
  int i;
  for (i=1; i<=nivel; i++)
    printf("%d", anod->cheie);
  printf("\n");
}

int main()
{   int choice;
    printf("\n                           #################################################");
    printf("\n                           ##                                             ##");
    printf("\n                           ##     Bine ati venit la Ernest Restaurant!    ##");
    printf("\n                           ##                                             ##");
    printf("\n                           #################################################");
    do {
        printf("\n   1. Arata-mi mesele!");
        printf("\n   2. Rezervare!");
        printf("\n   3. Sterge rezervare!");
        printf("\n   4. Administrator");
        printf("\n   5. Exit");
        printf("\n");
        printf("\n   Aleget:");
        scanf("%d",&choice);
        switch(choice)
	    {
	    	case 1:{citFis();
	    	       scrie1();
                   break;}
	    	case 2:rezi();
	    	       break;
            case 3:anuRez();
                   break;
	    	case 4:{
            FILE *text;
            char p[10],password[10];
            text=fopen("Pass.txt","r");
            fscanf(text,"%s",p);
            printf("\n   Introduceti parola:");
            scanf("%s",&password);
              while ((strcmp(password,p)!=0))
                {   printf("\n   Parola gresita! Introduceti inca o data: ");
	    			scanf("%s",&password);
				}
            fclose(text);
	    	int choice1;
	    	do{
               printf("\n   1. Rezervarile!");
	    	   printf("\n   2. Cauta un client!");
	    	   printf("\n   3. Ordine alfabetica clientilor!(Inversa Z->A)");
	    	   printf("\n   4. Plan de modificare a meselor!(pentru petreceri)");
	    	   printf("\n   5. Inapoi");
	    	   printf("\n");
               printf("\n   Aleget: ");
               scanf("%d",&choice1);
               switch(choice1){
                case 1:{citFis();
                      scrie2();
                       break;}
                case 2:cautaNume();
                       break;
                case 3:abc();
                       break;
               case 4:{int choice2;
                       do{
                       printf("\n   1. Inordine");
	    	           printf("\n   2. Postordine");
	    	           printf("\n   3. Preordine");
	    	           printf("\n   4. Inapoi");
	    	           printf("\n");
                       printf("\n   Aleget: ");
                       scanf("%d",&choice2);
	    	           switch(choice2){
                       case 1: {  int y;
                                  printf("  Cate mese vreti sa aranjati?");
                                  scanf("%d",&y);
                                  radacina=Arbore(y);
                                  printf("Inordinea:");
                                  inordine(radacina,1);
                                  break;}
                       case 2: {  int y;
                                  printf("  Cate mese vreti sa aranjati?");
                                  scanf("%d",&y);
                                  radacina=Arbore(y);
                                  printf("Postordinea:");
                                  postordine(radacina,1);
                                  break;}
                       case 3: {  int y;
                                  printf("  Cate mese vreti sa aranjati?");
                                  scanf("%d",&y);
                                  radacina=Arbore(y);
                                  printf("Preordinea:");
                                  preordine(radacina,1);
                                  break;}
                       }
                       }while(choice2!=4);
                       break;}
               }
	    	}while(choice1!=5);
	    	break;
	    	}
	    }
    }while(choice!=5);
    return 0;
}

 void ordo()
 {
  int aux,aux2,aux3; char aux4[0],aux5[0],aux6[0];
  for(i=h2;i!=NULL;i=i->urm2)
    for(j=i->urm2;j!=NULL;j=j->urm2)
      if(strcmp(i->nume,j->nume)<0)
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
 ordo();
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
}

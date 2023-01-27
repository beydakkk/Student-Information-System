#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>

typedef struct dersler{
	
	char dersKodu[10];
	char dersAdi[50];
	int kredi;
	int kontenjan;
	int mevcut;
	struct dersler *next;
	int *ogrenciler;
	
}DERSLER;

typedef struct ogrenci{
	
	int no;
	char isim[20];
	char soyisim[20];
	int toplamDers;
	int toplamKredi;
	struct ogrenci *next; 
	struct ogrenci *prev;
	
}OGRENCI;

typedef struct kayit{
	
	int ID;
	char dersKodu[10];
	int num;
	char tarih[20];
	char durum[20];
	struct kayit *next;
	
}KAYIT;


//dersler için fonksiyonlar:

void dersEkle(DERSLER **d_head); 
void dersSil(DERSLER **d_head,KAYIT **k_head,OGRENCI **o_head,char tarih[10]);
void dersYazdir(DERSLER **d_head);
void dersOkuma(DERSLER **d_head);
void DersDosyayaKaydet(DERSLER *d_head);
int DersVarYok(DERSLER *d_head,char kod[10]);

// öðrenciler için fonksiyonlar

void ogrenciOkuma(OGRENCI **o_head);  
void ogrenciYazdir(OGRENCI **o_head);
void ogrenciSiralaNum(OGRENCI *o_head);
void OgrenciDosyayaKaydet(OGRENCI *head);
void OgrenciEkle(OGRENCI **head);
void OgrenciSil(OGRENCI **head,KAYIT **k_head,DERSLER **d_head,char tarih[10]);
int OgrenciVarYok(OGRENCI *o_head,int numara);
void OgrencidenDersSilme(OGRENCI **o_head,DERSLER **d_head,KAYIT **k_head,char tarih[10]);

//ders kayýtlarý için fonksiyonlar

void KayitOkuma(KAYIT **head);
void KayitYazdir(KAYIT **k_head);
void KayitDosyayaKaydet(KAYIT *k_head);

void ListeyeKaydet(DERSLER **d_head,KAYIT **k_head);
void OgrenciDerseKaydet(OGRENCI **o_head,DERSLER **d_head,KAYIT **k_head,int max_ders,int max_kredi,char tarih[10]);
void OgrencininDersleriniListeleme(OGRENCI **o_head,KAYIT **k_head);
void SinifListesiOlustur(DERSLER **d_head);
void ListedenSilme(DERSLER **d_head,int sil);

int main(){
	
	setlocale(LC_ALL, "Turkish");
	int secim;
	int max_ders,max_kredi;
	char tarih[10];
	DERSLER *d_head = NULL;
	OGRENCI *o_head = NULL;
	KAYIT *k_head = NULL;
	
	printf("Öðrencilerin alabileceði maximum ders sayýsýný giriniz:\n");
	scanf("%d",&max_ders);
	printf("Öðrencilerin alabileceði maximum kredi sayýsýný giriniz:\n");
	scanf("%d",&max_kredi);
	printf("Bugünün tarihini giriniz (XX.XX.XXX seklinde) : \n");
	scanf("%s",tarih);
	
	printf("\n\n");
	printf("\t\t\tYAPISAL PROGRAMLAMA DÖNEM PROJESI\n\t\t\t\t  BEYDA GÜLER\n\t\t\t\t    19011010\n\n");
	printf("              >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
	printf(" \t\t\t1-Ders Listesi Yazdýr\n \t\t\t2-Ders Ekle\n \t\t\t3-Ders Sil\n \t\t\t4-Öðrenci Listesi Yazdýr\n \t\t\t5-Öðrenci Ekle\n \t\t\t6-Öðrenci Sil\n \t\t\t7-Öðrenciyi Derse Kaydetme\n \t\t\t8-Ders Kayýt Listesini Yazdýr\n \t\t\t9-Öðrenciden Ders Silme\n \t\t\t10-Derse Ait Sýnýf Listesi Oluþturma\n \t\t\t11-Öðrenci Ders Programý Oluþturma\n \t\t\t12-Çýkýþ\n\n");
	printf("              <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	printf("Seciminiz -->");
	scanf("%d",&secim);
	
	
	dersOkuma(&d_head);
	KayitOkuma(&k_head);
	ogrenciOkuma(&o_head);
	ListeyeKaydet(&d_head,&k_head);
	
	while(secim != 12){
	
		switch(secim){
			
			case 1:
				
				printf("\nDers Listesi :\n");
				dersYazdir(&d_head);
				printf("\n");
				break;
			case 2:
				
				dersEkle(&d_head);
				ListeyeKaydet(&d_head,&k_head);
				DersDosyayaKaydet(d_head);
				
				break;
			case 3:
			
				dersSil(&d_head,&k_head,&o_head,tarih);
				DersDosyayaKaydet(d_head);
			
				break;
			case 4:
				printf("Öðrenci Listesi :\n");
				ogrenciYazdir(&o_head);
				break;
			case 5:
			
				OgrenciEkle(&o_head);
				//ogrenciSiralaNum(o_head);
				OgrenciDosyayaKaydet(o_head);
				break;
			case 6:
			
				OgrenciSil(&o_head,&k_head,&d_head,tarih);
				OgrenciDosyayaKaydet(o_head);
				break;
			case 7:
				OgrenciDerseKaydet(&o_head,&d_head,&k_head,max_ders,max_kredi,tarih);
			//	ListeyeKaydet(&d_head,&k_head);
				
				break;
			case 8:
				printf("Ders Kayýt Listesi:");
				KayitYazdir(&k_head);
				break;
			case 9:
				OgrencidenDersSilme(&o_head,&d_head,&k_head,tarih);
				break;
			case 10:
				SinifListesiOlustur(&d_head);
				break;
			case 11:
				OgrencininDersleriniListeleme(&o_head,&k_head);
				break;		
		}
		printf("              >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
		printf(" \t\t\t1-Ders Listesi Yazdýr\n \t\t\t2-Ders Ekle\n \t\t\t3-Ders Sil\n \t\t\t4-Öðrenci Listesi Yazdýr\n \t\t\t5-Öðrenci Ekle\n \t\t\t6-Öðrenci Sil\n \t\t\t7-Öðrenciyi Derse Kaydetme\n \t\t\t8-Ders Kayýt Listesini Yazdýr\n \t\t\t9-Öðrenciden Ders Silme\n \t\t\t10-Derse Ait Sýnýf Listesi Oluþturma\n \t\t\t11-Öðrenci Ders Programý Oluþturma\n \t\t\t12-Çýkýþ\n\n");
		printf("              <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
		printf("Yeni islem seciniz---->");
		scanf("%d",&secim);

	}
	return 0;
}

void KayitOkuma(KAYIT **k_head){   
	FILE *dosya;
	KAYIT *tmp = *k_head;
	if((dosya = fopen("OgrenciDersKayit.txt","r"))==NULL){
		printf("Dosya Acilamadi!\n");
		return;
	}

	while(!feof(dosya)){
		if(*k_head == NULL){
			*k_head =(KAYIT*)malloc(sizeof(KAYIT));
			(*k_head)->next = NULL;
			fscanf(dosya,"%d,%[^,],%d,%[^,],%[^\n]\n",&(*k_head)->ID,(*k_head)->dersKodu,&(*k_head)->num,(*k_head)->tarih,(*k_head)->durum);
		}
		else{
			tmp = *k_head;
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			
			tmp->next = (KAYIT*)malloc(sizeof(KAYIT));
			fscanf(dosya,"%d,%[^,],%d,%[^,],%[^\n]\n",&(tmp->next->ID),&(tmp->next->dersKodu),&(tmp->next->num),&(tmp->next->tarih),&(tmp->next->durum));
			tmp->next->next = NULL;
		}
	}
	fclose(dosya);
}

void ListeyeKaydet(DERSLER **d_head,KAYIT **k_head){   
	
	int i=0;
	KAYIT *tmp2 = *k_head;
	DERSLER *tmp = *d_head;
	while(tmp != NULL){
		i=0;
		tmp2= *k_head;
		tmp->mevcut=0;
		while(tmp2 != NULL){
			

			if((strcmp(tmp2->dersKodu,tmp->dersKodu))==0 && (strcmp((tmp2->durum),"kayitli"))==0){
			
				if(tmp->mevcut == 0){
					(tmp->mevcut)++;
					tmp->ogrenciler = (int*)malloc(sizeof(int));
					tmp->ogrenciler[i]=tmp2->num;
					i++;
				}
				else{
					(tmp->mevcut)++;
					tmp->ogrenciler = (int*)realloc((tmp->ogrenciler),(tmp->mevcut)*sizeof(int));
					tmp->ogrenciler[i] = tmp2->num;
					i++;
				}
			}
			tmp2 = tmp2->next ;
		}
		tmp = tmp->next;
	}
}

void KayitYazdir(KAYIT **k_head){    
	printf("\n");
	KAYIT *tmp =*k_head;
	while(tmp != NULL ){
		printf("%d %s %d %s %s\n",tmp->ID,tmp->dersKodu,tmp->num,tmp->tarih,tmp->durum);
		tmp = tmp->next ;
	}
	printf("\n");
}

void dersOkuma(DERSLER **d_head){      
	FILE *fp;
	DERSLER *tmp=*d_head;
	
	if((fp = fopen("dersler.txt","r"))== NULL){
    	printf("Dosya Acilamadi!\n");
        return;
    }
	while(!feof(fp)){
		if(*d_head == NULL){
    		*d_head = (DERSLER*)malloc(sizeof(DERSLER));
    		(*d_head)->next =NULL;
			fscanf(fp,"%[^,],%[^,],%d,%d\n",(*d_head)->dersKodu,(*d_head)->dersAdi,&(*d_head)->kredi,&(*d_head)->kontenjan);
		}
		else{
			tmp=*d_head;
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			tmp->next = (DERSLER*)malloc(sizeof(DERSLER));
			tmp->next->next =NULL;
			fscanf(fp,"%[^,],%[^,],%d,%d\n",tmp->next->dersKodu,tmp->next->dersAdi,&(tmp->next->kredi),&(tmp->next->kontenjan));
		}
	}
	fclose(fp);
}

void dersYazdir(DERSLER **d_head){       
	printf("\n");
	DERSLER *tmp =*d_head;
	while(tmp != NULL ){
		printf("%s   %s %d %d\n",tmp->dersKodu,tmp->dersAdi,tmp->kredi,tmp->kontenjan);
		tmp = tmp->next ;
	}
	printf("\n");
	
}

void DersDosyayaKaydet(DERSLER *d_head){      
	DERSLER *tmp = d_head;
	FILE *ders = fopen("dersler.txt","w");
	
	while(tmp !=NULL){
		fprintf(ders,"%s,%s,%d,%d\n",tmp->dersKodu,tmp->dersAdi,tmp->kredi,tmp->kontenjan,setlocale(LC_ALL,"Turkish"));
		tmp = tmp->next;
	}
	fclose(ders);
}

void KayitDosyayaKaydet(KAYIT *k_head){       
	KAYIT *tmp = k_head;
	FILE *fp = fopen("OgrenciDersKayit.txt","w");
	
	while(tmp != NULL){
		
		fprintf(fp,"%d %s %d %s %s\n",tmp->ID,tmp->dersKodu,tmp->num,tmp->tarih,tmp->durum);
		tmp = tmp->next;
	}
	fclose(fp);
}

void dersEkle(DERSLER **d_head){      
	int found = 0;
	DERSLER *tmp =*d_head;
	DERSLER *yeniDers = (DERSLER*)malloc(sizeof(DERSLER));
	
	printf("Acilacak yeni ders icin ders kodunu , ismini ,kredisini ve kontenjani giriniz...\n");
	scanf("%s %s %d %d",yeniDers->dersKodu,yeniDers->dersAdi,&yeniDers->kredi,&yeniDers->kontenjan);
	

	
	while(tmp != NULL && !found){
		if(strcmp(yeniDers->dersKodu,tmp->dersKodu) == 0){
			found++;
			printf("Bu ders zaten acik!\n");
		}
		else{
			tmp = tmp->next;
		}
	}
	tmp =*d_head;
	if(*d_head == NULL){
		*d_head = yeniDers ;
		(*d_head)->next =NULL;

	}
	else if(strcmp(yeniDers->dersKodu,(*d_head)->dersKodu) < 0){   //ilkinden daha küçükse
		yeniDers->next= *d_head;
		*d_head = yeniDers;
	}
	else{
		tmp = *d_head;
		while(tmp->next != NULL && strcmp(tmp->next->dersKodu,yeniDers->dersKodu) < 0){
			tmp = tmp->next ;
		}
		yeniDers->next = tmp->next;
		tmp->next = yeniDers ;
		
	}
	//free(yeniDers);
	

}

void dersSil(DERSLER **d_head,KAYIT **k_head,OGRENCI **o_head,char tarih[10]){    
	char sil[20];
	int i;
	DERSLER *tmp;
	DERSLER *tmp4;
	KAYIT *tmp2 = *k_head;
	DERSLER *iter = *d_head;
	OGRENCI *tmp3=*o_head;
	
	printf("Silmek istediginiz dersin kodunu giriniz:\n");
	scanf("%s",sil);
	
	if(strcmp((*d_head)->dersKodu,sil)==0 ){    //baþtaysa
		tmp = (*d_head);
		(*d_head) = (*d_head)->next;
		printf("Ders Silindi\n");
		DersDosyayaKaydet(*d_head);
		
		while(tmp2 != NULL){
			
			if(strcmp(sil,tmp2->dersKodu)==0 && strcmp(tmp2->durum,"kayitli")==0){
				strcpy(tmp2->tarih,tarih);
				strcpy(tmp2->durum,"ders kapandi");
				KayitDosyayaKaydet(*k_head);
			}
			tmp2= tmp2->next;
		}
		
		while(tmp3 != NULL){
	
			for(i=0;i<(tmp->mevcut);i++){
				if(tmp3->no == tmp->ogrenciler[i]){
					tmp3->toplamDers -= 1;
					tmp3->toplamKredi -= tmp->kredi;
				}
			}
			tmp3 = tmp3->next ;
			OgrenciDosyayaKaydet(*o_head);
		}
		tmp=NULL;
		free(tmp);
		
		char sil2[20];
		strcpy(sil2,sil);
		strcat(sil2,".txt");
		if(remove(sil2)==0){
			printf("%s adlý dosya silindi.\n\n",sil2);
		}
		
	}
	
	
	else{           //baþta deðilse
	
		while(iter->next != NULL && strcmp(iter->next->dersKodu,sil) !=0 ){
			iter = iter->next;
		}
		if(iter->next==NULL){
			printf("Boyle bir ders yok !\n");
			return;
		}
		tmp = iter->next;
		iter->next = iter->next->next;
		printf("Ders Silindi\n");
		DersDosyayaKaydet(*d_head);
		
		tmp2 = *k_head;
		
		while(tmp2 != NULL){
			if(strcmp(sil,tmp2->dersKodu)==0 && strcmp(tmp2->durum,"kayitli")==0){
				strcpy(tmp2->tarih,tarih);
				strcpy(tmp2->durum,"ders kapandi");
				KayitDosyayaKaydet(*k_head);
			}
			tmp2= tmp2->next;
		}
		tmp3 = *o_head;
		while(tmp3 != NULL){
			if(tmp->mevcut!=0){
				for(i=0;i<(tmp->mevcut);i++){
					if(tmp3->no == tmp->ogrenciler[i]){
						tmp3->toplamDers -= 1;
						tmp3->toplamKredi -= tmp->kredi;
						OgrenciDosyayaKaydet(*o_head);
					}
				}
			}
			
			tmp3 = tmp3->next;
		}
		
	}
	tmp=NULL;
	free(tmp);
	
}

void OgrenciSil(OGRENCI **head,KAYIT **k_head,DERSLER **d_head,char tarih[10]){  
	int sil,i,j;
	int var=0;
	OGRENCI *tmp = *head;
	KAYIT *tmp2 = *k_head;
	DERSLER *tmp3;
	printf("Silmek istediðiniz öðrencinin numarasýný giriniz:\n");
	scanf("%d",&sil);
	
	while(tmp != NULL && tmp->no != sil){
		tmp = tmp->next;
	}
	if(tmp==NULL){
		printf("Boyle bir ogrenci yok!\n");
		return;
	}
	
	if (sil == (*head)->no){   //baþtaysa
		*head =(*head)->next;
		(*head)->prev = NULL;
		free((*head)->prev);
		
		printf("Ogrenci Silindi\n");
	}
	else {
		tmp = *head;
		while(tmp->next != NULL && tmp->no != sil){
			tmp = tmp->next ;
		}
		if(tmp->next== NULL){            //sondaysa
			tmp->prev->next = NULL;
		//	free(tmp);
			printf("Ogrenci Silindi\n");
		}
		else{                           //ortadaysa
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		//	free(tmp);
			printf("Ogrenci Silindi\n");
		}	
	}
	
	while(tmp2 != NULL){
		if(tmp2->num == sil && strcmp(tmp2->durum,"kayitli")==0){
			strcpy(tmp2->durum,"birakti");
			strcpy(tmp2->tarih,tarih); 
			KayitDosyayaKaydet(*k_head);
			tmp3 = *d_head;
			while(strcmp(tmp2->dersKodu,tmp3->dersKodu)!=0){
				tmp3 = tmp3->next;
			}
			ListedenSilme(&tmp3,sil);
		}
		tmp2 = tmp2->next;
	}
	tmp=NULL;
	free(tmp);
	

}

void ListedenSilme(DERSLER **tmp,int sil){  
	((*tmp)->mevcut)--;
	int i=0,j;
	while(i < ((*tmp)->mevcut-1) && (*tmp)->ogrenciler[i] != sil){
		i++;
	}
	for(j=i;j<=((*tmp)->mevcut-1);j++){
		(*tmp)->ogrenciler[j] = (*tmp)->ogrenciler[j+1] ;
	}
	(*tmp)->ogrenciler = realloc(((*tmp)->ogrenciler),((*tmp)->mevcut)*sizeof(int));
}

void ogrenciOkuma(OGRENCI **o_head){         
	FILE *fp;
	OGRENCI *tmp = *o_head;
	OGRENCI *iter;
	
	if((fp = fopen("ogrenciler.txt","r"))== NULL){
    	printf("Dosya Acilamadi!\n");
        return;
    }
    while(!feof(fp)){
    	if(*o_head == NULL){
    		*o_head = (OGRENCI*)malloc(sizeof(OGRENCI));
    		(*o_head)->next = NULL;
    		(*o_head)->prev =NULL;
    		fscanf(fp,"%d,%[^,],%[^,],%d,%d\n",&(*o_head)->no,(*o_head)->isim,(*o_head)->soyisim,&(*o_head)->toplamKredi,&(*o_head)->toplamDers);
		}
		else{
			tmp = *o_head;
			
			while(tmp->next != NULL){
				tmp = tmp->next ;
				
			}
			tmp->next = (OGRENCI*)malloc(sizeof(OGRENCI));
			tmp->next->prev = tmp;
			tmp->next->next = NULL;
			fscanf(fp,"%d,%[^,],%[^,],%d,%d\n",&tmp->next->no,tmp->next->isim,tmp->next->soyisim,&tmp->next->toplamKredi,&tmp->next->toplamDers);

		}  
	}	
	fclose(fp);
}

void ogrenciYazdir(OGRENCI **o_head){      


	OGRENCI *tmp =*o_head;
	while(tmp != NULL){
		printf("%d,%s,%s,%d,%d\n",tmp->no,tmp->isim,tmp->soyisim,tmp->toplamKredi,tmp->toplamDers);
		tmp = tmp->next;
		//tmp->next = NULL;
	}
	printf("\n");
}

void ogrenciSiralaNum(OGRENCI *head) {  //numaralar artacak þekilde sort iþlemi yapar
    OGRENCI *current = NULL;
	OGRENCI *index = NULL;  
    OGRENCI *temp;   
    if(head == NULL) {  
        return;  
    }  
    else {  
        for(current = head; current->next != NULL; current = current->next) {    
            for(index = current->next; index != NULL; index = index->next) {  
                if(current->no > index->no) {  
                    temp = current;  
                    current = index;  
                    index = temp;  
                }  
            }  
        }  
    } 
} 

void OgrenciDosyayaKaydet(OGRENCI *head){        
	OGRENCI *tmp = head;
	FILE *fp = fopen("ogrenciler.txt","w");;
	
	while(tmp->next != NULL){
		fprintf(fp,"%d,%s,%s,%d,%d\n",tmp->no,tmp->isim,tmp->soyisim,tmp->toplamKredi,tmp->toplamDers);
		tmp = tmp->next;
	}
	fclose(fp);
}

void OgrenciEkle(OGRENCI **head){        
	int found = 0;
	OGRENCI *tmp =*head;
	OGRENCI *yeni = (OGRENCI*)malloc(sizeof(OGRENCI));
	
	printf("Yeni ogrenci icin numara,isim,soyisim,toplam ders ve toplam kredi bilgisi giriniz...\n");
	scanf("%d %s %s %d %d",&yeni->no,yeni->isim,yeni->soyisim,&yeni->toplamKredi,&yeni->toplamDers);
	
	while(tmp != NULL && !found){    
		if(yeni->no == tmp->no ){
			found=1;
			printf("Bu ogrenci zaten var!\n");
			return;
		}
		else{
			tmp = tmp->next;
		}
	}
	if(*head == NULL){
		*head == yeni ;
	}
	else if(yeni->no < (*head)->no ){      //ilkinden küçükse
	
		(*head)->prev = yeni;
		yeni->next = *head;
		*head = yeni;
	}
	else{
		tmp = *head;
		while(tmp->next != NULL && tmp->no < yeni->no){
			tmp = tmp->next ;
		}
		if(tmp->next == NULL){            //sona ekleme durumu
			yeni->next=NULL;
			tmp->next = yeni;
			yeni->prev = tmp;
		}
		else{                             //ortaya ekleme
			tmp->prev->next =yeni;
			yeni->prev =tmp->prev;
			yeni->next =tmp;
			tmp->prev =yeni;
		}
	}
}

void OgrenciDerseKaydet(OGRENCI **o_head,DERSLER **d_head,KAYIT **k_head,int max_ders,int max_kredi,char tarih[10]){      
	int var=0;
	int no;
	char kod[10];
	DERSLER *tmp = *d_head ;
	OGRENCI *tmp2 = *o_head;
	KAYIT *tmp3 = *k_head;
	
	printf("Kaydetmek istediginiz ogrencinin numarasini giriniz:\n");
	scanf("%d",&no);
	
	while(tmp2 != NULL && tmp2->no != no){
		tmp2 = tmp2->next;
	}
	if(tmp2 == NULL){
		printf("Boyle bir ogrenci yok!\n\n");
		return;
	}
	
	printf("Kaydetmek istediginiz dersin kodunu giriniz:\n");
	scanf("%s",kod);
	while(tmp != NULL && strcmp(tmp->dersKodu,kod) != 0){
			tmp = tmp->next;
		}
	if(tmp == NULL){
		printf("Boyle bir ders yok!\n\n");
		return;
	}
	else if(tmp2->toplamDers >= max_ders ){
		printf("Bu ogrenci maksimum ders sayisina ulasmistir yeni ders alamaz!\n\n");
		return;
		}
	else if(tmp2->toplamKredi >= max_kredi){
		printf("Bu ogrenci maksimum kredi sayisina ulasmistir yeni ders alamaz!\n\n");
		return;
	}
	else if(tmp->kontenjan < tmp->mevcut+1){
		printf("Bu dersin kontenjani dolu!\n\n");
		return;
	}
	else{
		
		tmp2->toplamDers += 1 ;
		tmp2->toplamKredi += tmp->kredi ;
		OgrenciDosyayaKaydet(*o_head);
		if(*k_head==NULL){
			*k_head = (KAYIT*)malloc(sizeof(KAYIT));
			(*k_head)->ID = 1001;
			strcpy((*k_head)->dersKodu,tmp->dersKodu);
			(*k_head)->num = tmp2->no;
			strcpy((*k_head)->tarih,tarih);
			strcpy((*k_head)->durum,"kayitli");
			(*k_head)->next=NULL; 
			KayitDosyayaKaydet(*k_head);
		}
		else{
		
			while(tmp3->next != NULL){
				tmp3=tmp3->next;
			}
			tmp3->next = (KAYIT*)malloc(sizeof(KAYIT));
			tmp3->next->ID =tmp3->ID + 1;
			strcpy(tmp3->next->dersKodu,tmp->dersKodu);
			tmp3->next->num=tmp2->no;
			strcpy(tmp3->next->tarih,tarih);
			strcpy(tmp3->next->durum,"kayitli");
			tmp3->next->next=NULL; 
			KayitDosyayaKaydet(*k_head);
		}	
	}
	DersDosyayaKaydet(*d_head);
	ListeyeKaydet(d_head,k_head);	
}

void SinifListesiOlustur(DERSLER **d_head){       
	char code[40];
	char code2[40];
	int i,found=0;
	FILE *liste;
	DERSLER *tmp = *d_head ;
	printf("Sinif listesini olusturmak istediginiz dersin kodunu giriniz:\n");
	scanf("%s",code);
	
	if(!DersVarYok(*d_head,code)){
		printf("Olmayan bir ders kodu girdiniz!\n\n");
		return;
	}
	strcpy(code2,code);
	strcat(code,".txt");
	liste = fopen(code,"w+");
	
	while(tmp!=NULL ){
		if(strcmp(tmp->dersKodu,code2)==0){
			if(tmp->mevcut !=0){
				for(i=0;i<(tmp->mevcut);i++){
					fprintf(liste,"%d\n",tmp->ogrenciler[i]);
					printf("%d\n",tmp->ogrenciler[i]);
				}
			}
			else{
				printf("Bu dersi alan bir öðrenci bulunamadý!\n\n");
				return;
			}
		}
		tmp = tmp->next;
	}
	printf("\n");
	fclose(liste);
}

void OgrencininDersleriniListeleme(OGRENCI **o_head,KAYIT **k_head){      
	
	int num;
	char no[40];
	char filename[40]="DERSPROGRAMI";
	OGRENCI *tmp = *o_head;
	KAYIT *tmp2 = *k_head;
	FILE *fp;
	
	printf("Derslerini listelemek istediðiniz öðrencinin numarasýný giriniz:\n");
	scanf("%d",&num);
	
	if(!OgrenciVarYok(*o_head,num)){
		printf("Olmayan bir öðrenci numarasý girdiniz!\n\n");
		return;
	}
	itoa(num,no,10);
	strcat(no,"_");
	strcat(no,filename);
	strcat(no,".txt");
	fp = fopen(no,"w+");
	while(tmp2 != NULL){
		if(tmp2->num == num && strcmp(tmp2->durum,"kayitli")==0){
			fprintf(fp,"%s\n",tmp2->dersKodu);
			printf("%s\n",tmp2->dersKodu);
		}
		tmp2 = tmp2->next;
	}
	printf("\n");
	fclose(fp);
	
}

int OgrenciVarYok(OGRENCI *o_head,int numara){       
	int found=0;
	OGRENCI *tmp = o_head;
	while(tmp!=NULL){
		if(numara == tmp->no){
			found++;
		}
		tmp = tmp->next;
	}
	if(found == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int DersVarYok(DERSLER *d_head,char kod[10]){           
	int found=0;
	DERSLER *tmp = d_head;
	while(tmp!=NULL){
		if(strcmp(tmp->dersKodu,kod)==0){
			found++;
		}
		tmp=tmp->next;
	}
	if(found==0) {
		return 0;
	}
	else {
		return 1;
	}
}

void OgrencidenDersSilme(OGRENCI **o_head,DERSLER **d_head,KAYIT **k_head,char tarih[10]){  
	
	int no;
	int i;
	char kod[10];
	OGRENCI *tmp=*o_head;
	DERSLER *tmp2=*d_head;
	KAYIT *tmp3=*k_head;
	
	printf("Öðrenci no giriniz:\n");
	scanf("%d",&no);
	printf("Hangi dersi silmek istiyorsanýz ders kodunu giriniz:\n");
	scanf("%s",kod);
	
	if(!OgrenciVarYok(*o_head,no)){
		printf("Öðrenci bulunamadý!\n");
		return;
	}
	else if(!DersVarYok(*d_head,kod)){
		printf("Ders bulunamadý!\n");
		return;
	}
	else{
		while(tmp!= NULL && no != tmp->no){
			tmp= tmp->next;
		}
		tmp->toplamDers -= 1;
		while(tmp2 != NULL && strcmp(kod,tmp2->dersKodu)!=0 ){
			tmp2 = tmp2->next;
		}
		tmp->toplamKredi -= tmp2->kredi;
		
		while(tmp3 != NULL){
			if(no==tmp3->num && strcmp(kod,tmp3->dersKodu)==0){
				strcpy(tmp3->tarih,tarih);
				strcpy(tmp3->durum,"sildi");
				tmp2 = *d_head;
				while(strcmp(tmp3->dersKodu,tmp2->dersKodu)!=0){
					tmp2 = tmp2->next;
				}
			ListedenSilme(&tmp2,no);
			}
			tmp3 = tmp3->next;
		}
		DersDosyayaKaydet(*d_head);
		OgrenciDosyayaKaydet(*o_head);
		KayitDosyayaKaydet(*k_head);
	}	
}

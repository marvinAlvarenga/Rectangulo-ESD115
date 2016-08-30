#include<stdlib.h>
#include<stdio.h>

struct nodo{
	char *linea1;
	char *linea2;
	int x;
	int y;
};
typedef struct nodo* rect;

//funcion para crear rectangulo en memoria debuelve un puntero
rect crear(){
	rect r=(struct nodo*)malloc(sizeof(struct nodo));
	return r;
}

//inicializar rectangulo
void init(rect r){
	r->x=0;
	r->y=0;
	
	r->linea1=(char *)malloc(8*sizeof(char));
	r->linea2=(char *)malloc(8*sizeof(char));
	
	for(int i=0;i<7;i++){
		if(i==0||i==6){
			*(r->linea2+i)='*';
		}else{
			*(r->linea2+i)=' ';
		}
		*(r->linea1+i)='*';
	}
	
	*(r->linea1+7)='\0';
	*(r->linea2+7)='\0';
	
	return;
}

//mover las coordenadas del rectangulo
//1:arriba 2: abajo 3:izquierda  4:derecha
void cambiarCoordenadas(rect r,int tipoMovi,int numMovi){
	switch(tipoMovi){
		case 1: r->y-=numMovi; break; //a la coordenada actual en Y restarle el num movi para subir el rectangulo
		case 2: r->y+=numMovi; break; //a la coordenada actual en Y sumarle el num movi para bajar el rectangulo
		case 3: r->x-=numMovi; break;
		case 4: r->x+=numMovi;
	}
	return ;
}

//despliegue del rectangulo
void imprimir(rect r){
	system("cls");
	int i,j;
	
	for(i=0;i<r->y;i++){ //bajando el rectangulo
		printf("\n");
	}
	
	for(i=1;i<=4;i++){
		for(j=0;j<r->x;j++){
			printf(" ");
		}
		switch(i){
			case 1: case 4:
				printf("%s",r->linea1);
			break;
			case 2: case 3:
				printf("%s",r->linea2);
		}
		printf("\n");
	}
	return;
}

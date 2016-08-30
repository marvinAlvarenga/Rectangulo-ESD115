#include"rectanguloLib.h"

int main(){
	int b=1,selec,n;
	rect r = crear();
	init(r);
	
	
	while(b){
		imprimir(r);	
		printf("\n\nComo desea mover el rectangulo:??");
		printf("\n1: arriba\n2: abajo\n3: izquierda\n4: derecha\n0: salir");
		printf("\nSu seleccion es: ");
		scanf("%i",&selec);
		if(selec!=0){
			printf("\nNumero de desplazamientos: ");
			scanf("%i",&n);
			cambiarCoordenadas(r,selec,n);
			imprimir(r);
		}else{
			b=0;
		}
	}
	free(r);
	return 0;
}

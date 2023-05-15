#include "Listas.h"

void primos(lista **p){
  lista *aux= *p ,  *t;
	int EsPrimo = 1;
	while ((aux)&&(aux->prx != NULL)){
        t= aux->prx;
				EsPrimo = 1;
     for(int i = 2; i< t->valor;i++) {if(t->valor %i==0){EsPrimo = 0;}};       
		 if(EsPrimo){
          aux->prx= t->prx;
					delete t; }else{aux = aux->prx;}
	}
}



void burbuja(lista **p){
	lista *ax=*p, *t=*p;
	int s;
	
	while((ax)&&(ax->prx != NULL)){
		t= ax->prx;
		
		while (t!=NULL){
			if(ax->valor > t->valor){
				s=t->valor;
				t->valor=ax->valor;
				ax->valor=s;
			}
			t=t->prx;
		}
		ax=ax->prx;
		t=ax->prx;
		
	}
	
}

void insercion(lista **p){
	lista *ax=*p, *t=*p; 
	int temp;
	while (ax->prx!=NULL){
		t=ax->prx;		
		while (t!=NULL){							
			if(ax->valor > t->valor){ // "< de Mayor a menor" y "> de menor a mayor"
				temp = ax->valor;
				ax->valor=t->valor;
				t->valor=temp;
			}
			t=t->prx;
		}
	ax=ax->prx;	
	}
}

void insertarCabeza(lista **p, int x){
// inserta x por cabeza de la lista
	lista *t = new lista;
	t->valor = x;
	t->prx = *p;
	*p= t;
}	

void muestra(lista *p){
// muestra la lista por pantalla
	lista *t = p;
	printf("\n\n\n\t\t");
	while (t){
		printf("[%d]->",t->valor);
		t = t->prx;
		};
	printf("NULL\n\n");
	};

void borrartodo(lista **p){
	lista *ax=*p;
	while(*p){
		*p= (*p)->prx;
		delete ax;
		ax= *p;
	}
}

void voltear (lista **p){
	lista *t = NULL, *ax=*p, *temp;
	while(ax){
		insertarCabeza(&t, ax->valor);
		ax=ax->prx;
	}
	temp=*p;
	*p=t;
	borrartodo(&temp);
}

void voltear2 (lista **p){
	lista *t = *p, *ax;
	while((t)&&(t->prx)){
		ax=t->prx;
		t->prx=ax->prx;
		ax->prx=*p;
		*p=ax;
	}
}

void pospar (lista **p){
	lista *t=*p, *ax;
	while ((t)&&(t->prx)){
		ax = t->prx;
		t = t->prx->prx;
		delete ax;
	}
	t = t->prx;
}

void separadig (lista *p){
	lista *t = p, *ax;
	while (t){
		while (t->valor > 9){
			ax = new lista;
			ax->valor = t->valor%10;
			t->valor = t->valor/10;
			ax->prx = t->prx;
			t->prx = ax;
		}
		t = t->prx;
	}
}

void elimrep (lista *p){
	lista *t = p, *ax, *temp;
	while ((t)&&(t->prx)){
		ax = t;
		while (ax->prx){
			if (t->valor == ax->prx->valor){
				temp = ax->prx;
				ax->prx = temp->prx;
				delete temp;
			}
			else
				ax = ax->prx;
		}
		t = t->prx;
	}
}

int cuenta (lista *p){
	int cont=0;
	lista *t = p;
	while(t){
		t=t->prx;
		cont++;
	}
	return cont;
}

int busca (lista *p, int x){
	lista *t = p;
	while ((t)&&(t->valor == x)){
		t = t->prx;
	}
	return (t!=NULL);
}

//REVISAR ESTE PROCEDIMIENTO DEBIDO A QUE "EXPLOTA" AL TRATAR 
//DE ELIMINAR ELEMENTOS QUE TIENEN OTRAS OCURRENCIAS
void elimina (lista **p, int x){
	lista *t = *p, *ax;
	int c=0;
	if (t){
		if (t->valor == x){
			*p = (*p)->prx;
			delete t;
			c++;
		}
		else
			while ((t->prx)&&(t->prx->valor != x))
				t = t->prx;
				if (t->prx){
					ax = t->prx;
					t->prx = t->prx->prx;
					delete ax;
					c++;
		}
	}
	
	if  (c == 0){
		printf ("\n\t EL ELEMENTO NO SE ENCUENTRA EN LA LISTA\n\n");
	}else
		printf ("\n\t EL ELEMENTO FUE ELIMINADO CORRECTAMENTE\n\n");
}

int cuentarep (lista *p, int x){
	lista *t = p;
	int cont = 0;
	while (t){
		if(t->valor == x){
			cont++;
		}
		t = t->prx;
	}
	return cont;
}

void elimult (lista **p, int x){
	lista *ax = *p, *ul = ax, *t;
	if (ax){
		if (ax->valor == x){
			ul = ax; t = NULL;
		}
		while (ax->prx){
			if (ax->prx->valor == x){
				ul = ax->prx; t = ax;
			}
			ax = ax->prx;
		}
		if ((!t)&&(ax->valor == x)){
			*p=(*p)->prx; delete ax;
		}else{
			if ((ul)&&(ul->valor == x)){
				t->prx = ul->prx;
				delete ul;
			}
		}
	}
}

void insertarfinal(lista **p, int x){
	lista *t = *p;
	while ((t)&&(t->prx))t=t->prx;
	lista *aux = new lista;
	aux->valor = x;

	aux->prx = t->prx;
	t->prx = aux;
}

void insertarPreciso(lista **p, int x, int a){
	lista *t = *p;
	while ((t)&&(t->valor != a))t=t->prx;
	lista *aux = new lista;
	aux->valor = x;
	aux->prx = t->prx;
	t->prx = aux;
}



void swap (int *x, int *y){
	int c = *x;
	*x = *y;
	*y = c;
}

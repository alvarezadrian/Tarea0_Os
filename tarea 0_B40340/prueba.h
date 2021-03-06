#ifndef I_TAREA_PROGRAMADA_COLA_H_
#define I_TAREA_PROGRAMADA_COLA_H_
#define MAX_COLA 20
#include <iostream>	
using namespace std;
template <typename T>
class Cola{
public:
	Cola();
	~Cola();
	void Vaciar();bool Vacia();
	void Encolar(T e);
	T Desencolar();                T Frente();
    T Ultimo();
						int NumElem();private:
						int primero;
						int ultimo;
						int numElemF;
						T arreglo[MAX_COLA];
					};

					template<typename T>
					Cola<T>::Cola() {
	numElemF = 0;        primero = 1;
	ultimo = 0;
} template<typename T>Cola<T>::~Cola() {//delete[] arreglo;
												}

												template<typename T>
												void Cola<T>::Vaciar() { primero = 1;
												}

												template<typename T>
												bool Cola<T>::Vacia() {
													return !numElemF;
												}

												template<typename T>
												void Cola<T>::Encolar(T e) {
													if(ultimo == MAX_COLA - 1){
														ultimo = -1;
													}
													arreglo[++ultimo] = e;
													++numElemF;
												}template<typename T> T Cola<T>::Desencolar() {
													int i = primero;
													if(primero == MAX_COLA - 1){
														primero = - 1;
													}
													primero++;
	--numElemF;
	return arreglo[i];
}

template<typename T>T Cola<T>::Frente() {
				return arreglo[primero];
			} template<typename T>
			T Cola<T>::Ultimo() {
				return arreglo[ultimo];
			}

			
			
			
			
			
			
			
			
			
			
			
			template<typename T>
			int Cola<T>::NumElem() {
				
				
				
				
				
				
				
				
	return numElemF;
	}
}
#endif /* I_TAREA_PROGRAMADA_COLA_H_ */

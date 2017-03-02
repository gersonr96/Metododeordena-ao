//
//  MetodosDeOrdenacao.hpp
//  Métodos de Ordenação
//
//  Created by Gerson Rodrigo on 13/06/16.
//  Copyright © 2016 Gerson Rodrigo. All rights reserved.
//

#ifndef MetodosDeOrdenacao_hpp
#define MetodosDeOrdenacao_hpp

#include <stdio.h>
class ComandosPadrao {
public:
    long TAM;
    long *vetor;
    long *vetorB;
    int indice;
    int numeros_de_repeticoes;
    int numero_de_comparacoes;
    void inserir(long N);
    void mostrar();
   
};
class SelectionSort{
public:
    SelectionSort(long tam);
    void ordenaSelectionSort();
    ComandosPadrao Selection;
    void inserir(long N);
    void mostrar();
    void trocar(int i, int j);

};

class QuickSort{
public:
    QuickSort(long tam);
    long particao(long inicio, long fim);
    void quicksort(long inicio, long fim);
    ComandosPadrao Quick;
    void inserir(long N);
    void mostrar();
    void trocar();
    
};

class CountSort{
public:
    CountSort(long tam);
    long maximo();
    void ordenaCountSort();
    ComandosPadrao Count;
    void inserir(long N);
    
};


#endif /* SelectionSort_hpp */

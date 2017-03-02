//
//  main.cpp
//  SelectionSort
//
//  Created by Gerson Rodrigo on 12/06/16.
//  Copyright © 2016 Gerson Rodrigo. All rights reserved.
//

#include <iostream>
#include "MetodosDeOrdenacao.hpp"
#include <time.h>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
void sabertempoSelection(long tamanho, string porextenso);
void sabertempoSelectionInvertido(long tamanho, string porextenso);
void sabertempoSelectionMetade(long tamanho, string porextenso);
void menuSelection();
//------------------------------------------------------------
void menuQuickSort();
void saberTempoQuick(long tamanho, string porextenso);
void saberTempoQuickInvertido(long tamanho, string porextenso);
void saberTempoQuickMetade(long tamanho, string porextenso);
//------------------------------------------------------------
void menuCountSort();
void saberTempoCount(long tamanho, string porextenso);
void saberTempoCountInvertido(long tamanho, string porextenso);
void saberTempoCountMetade(long tamanho, string porextenso);
//------------------------------------------------------------
void gravardados(double teempo,long tamanho, string porextenso);

// Criando o arquio golbal para que seja acessado por todos o metodos
//FILE *file;
//char nome[] = "/Users/gerson_r96/Desktop/Trabalho\ Antonio/ DadosDosMetodos.txt";

int main(int argc, const char * argv[]) {
  //  file = fopen(nome,"wa");
    
    
    bool sair = true;
    int op;
    while(sair){
    cout << "Escolha um metodo de ordenacao:\n [1]- SelectionSort\n [2]- QuickSort\n [3]- CountSort\n [9]- Sair" <<endl;
    cin >> op;
    switch (op) {
        case 1:
            menuSelection();
            //getch();
            break;
        case 2:
            menuQuickSort();
            break;
        case 3:
            menuCountSort();
            break;
        case 9:
            sair = false;
            break;
        default:
            cout << "Errado" << endl;
            break;
      }
    }
    return 0;
}
//---------------------------QUICKSORT--------------------------------------------

void menuQuickSort(){

  //  fprintf(file, "-------------------------Quick Sort-----------------------\n\n");
    cout << "A ordenar 1 mil... 10 mil... 100 mil... 1 milhão..." <<endl;
    saberTempoQuick(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    saberTempoQuick(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    saberTempoQuick(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    saberTempoQuick(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
//    saberTempoQuick(10000000,"10 milhões");
//   cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    
    cout << "A ordenar Metade" <<endl;
    saberTempoQuickMetade(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    saberTempoQuickMetade(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    saberTempoQuickMetade(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    saberTempoQuickMetade(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
    //    saberTempoQuickMetade(10000000,"10 milhões");
    //    cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    
    
    cout << "A ordenar Quick Invertido" <<endl;
    saberTempoQuickInvertido(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    saberTempoQuickInvertido(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    saberTempoQuickInvertido(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    saberTempoQuickInvertido(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
//    saberTempoQuickInvertido(10000000,"10 milhões");
//    cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    

    
    
    
}
void saberTempoQuick(long tamanho, string porextenso){
    long maximo = tamanho*2;
    QuickSort vetor = QuickSort(tamanho);
    clock_t inicial, final;
    double tempo;
    for (int i = 0; i<tamanho;i++){
        vetor.Quick.inserir(rand()%maximo);
    }
    // vetor.Quick.mostrar();
    inicial = clock();
    vetor.quicksort(0,tamanho);
    final = clock();
    //vetor.mostrar();
    tempo = ((double)(final - inicial)/CLOCKS_PER_SEC);
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
     cout << "Numero de repeticoes: "<< vetor.Quick.numeros_de_repeticoes << endl;
    cout << "Numero de comparacoes: "<< vetor.Quick.numero_de_comparacoes << endl;
    

    
}
void saberTempoQuickInvertido(long tamanho, string porextenso){
  //
    //long maximo = tamanho*2;
    QuickSort vetor = QuickSort(tamanho);
    clock_t inicial, final;
    double tempo;
    for (long i = tamanho-1; i > 0;i --){
        vetor.Quick.inserir(i);
    }
    // vetor.Quick.mostrar();
    inicial = clock();
    vetor.quicksort(0,tamanho);
    final = clock();
    //vetor.mostrar();
    tempo = ((double)(final - inicial)/CLOCKS_PER_SEC);
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
     cout << "Numero de repeticoes: "<< vetor.Quick.numeros_de_repeticoes << endl;
     cout << "Numero de comparacoes "<< vetor.Quick.numero_de_comparacoes << endl;
    
}
void saberTempoQuickMetade(long tamanho, string porextenso){
    //
    long maximo = tamanho;
    QuickSort vetor = QuickSort(tamanho);
    clock_t inicial, final;
    double tempo;
    for (int i = 0; i<tamanho;i++){
        if(i>= tamanho/2){
        vetor.Quick.inserir(rand()%maximo);
        }else{
        vetor.Quick.inserir(i);
        }
    }
    // vetor.Quick.mostrar();
    inicial = clock();
    vetor.quicksort(0,tamanho);
    final = clock();
    //vetor.mostrar();
    tempo = ((double)(final - inicial)/CLOCKS_PER_SEC);
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
    cout << "Numero de repeticoes: "<< vetor.Quick.numeros_de_repeticoes << endl;
    cout << "Numero de comparacoes: "<< vetor.Quick.numero_de_comparacoes << endl;
    
}

//--------------------------SELECTIONSORT-----------------------------------------
void menuSelection(){
  
    
  //  fprintf(file, "----------------------Insertion Sort----------------------\n\n");
    cout << "A ordenar 1 mil... 10 mil... 100 mil... 1 milhão... " <<endl;
    sabertempoSelection(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    sabertempoSelection(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    sabertempoSelection(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    sabertempoSelection(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
//    sabertempoSelection(10000000,"10 milhões");
//    cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    
    
    cout << "A ordenar Selection Metade" <<endl;
    sabertempoSelectionMetade(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    sabertempoSelectionMetade(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    sabertempoSelectionMetade(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    sabertempoSelectionMetade(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
    //    sabertempoSelectionMetade(10000000,"10 milhões");
    //    cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    
    
    cout << "A ordenar Invertido" <<endl;
    sabertempoSelectionInvertido(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    sabertempoSelectionInvertido(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    sabertempoSelectionInvertido(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    sabertempoSelectionInvertido(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
//    sabertempoSelectionInvertido(10000000,"10 milhões");
//    cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    
    

}
void sabertempoSelection(long tamanho, string porextenso){
    long maximo = tamanho*2;
    SelectionSort vetor = SelectionSort(tamanho);
    clock_t inicial, final;
    double tempo;
    for (int i = 0; i<tamanho;i++){
        vetor.Selection.inserir(rand()%maximo);
    }
    
    inicial = clock();
    vetor.ordenaSelectionSort();
    final = clock();
    //vetor.mostrar();
    tempo = (double)(final - inicial)/CLOCKS_PER_SEC;
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
    cout << "Numero de repeticoes: "<< vetor.Selection.numeros_de_repeticoes << endl;
       cout << "Numero de rcomparacoes: "<< vetor.Selection.numero_de_comparacoes << endl;
    
}

void sabertempoSelectionInvertido(long tamanho, string porextenso){
    SelectionSort vetor = SelectionSort(tamanho);
    clock_t inicial, final;
    double tempo;
    for (long i = tamanho; i > 0;i --){
        vetor.Selection.inserir(i);
    }
    
    inicial = clock();
    vetor.ordenaSelectionSort();
    final = clock();
    //vetor.mostrar();
    tempo = (double)(final - inicial)/CLOCKS_PER_SEC;
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
    cout << "Numero de repeticoes: "<< vetor.Selection.numeros_de_repeticoes << endl;
    cout << "Numero de comparacoes: "<< vetor.Selection.numero_de_comparacoes << endl;
    
}
void sabertempoSelectionMetade(long tamanho, string porextenso){
    SelectionSort vetor = SelectionSort(tamanho);
    long maximo = tamanho;
    clock_t inicial, final;
    double tempo;
    for (int i = 0; i<tamanho;i++){
        if(i >= tamanho/2){
            vetor.Selection.inserir(rand()%maximo);
        }else{
            vetor.Selection.inserir(i);
        }
    }
    
    inicial = clock();
    vetor.ordenaSelectionSort();
    final = clock();
    //vetor.mostrar();
    tempo = (double)(final - inicial)/CLOCKS_PER_SEC;
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
    cout << "Numero de repeticoes: "<< vetor.Selection.numeros_de_repeticoes << endl;
     cout << "Numero de comparacoes: "<< vetor.Selection.numero_de_comparacoes << endl;
    
}
//-----------------------------------------COUNTSORT--------------------------------------

void menuCountSort(){
  //  fprintf(file, "------------------------Count Sort------------------------\n\n");
    cout << "A ordenar 1 mil... 10 mil... 100 mil... 1 milhão... " <<endl;
    saberTempoCount(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    saberTempoCount(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    saberTempoCount(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    saberTempoCount(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
//    saberTempoCount(10000000,"10 milhões");
//    cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    
    cout << "A ordenar Count Metade" <<endl;
    saberTempoCountMetade(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    saberTempoCountMetade(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    saberTempoCountMetade(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    saberTempoCountMetade(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
    //    saberTempoCountMetade(10000000,"10 milhões");
    //    cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    
    
    cout << "A ordenar Invertido" <<endl;
    saberTempoCountInvertido(1000,"1 mil");
    cout << "Vetor de 1 mil foi ordenado \n" << endl;
    saberTempoCountInvertido(10000,"10 mil");
    cout << "Vetor de 10 mil foi ordenado \n" << endl;
    saberTempoCountInvertido(100000, "100 mil");
    cout << "Vetor de 100 mil foi ordenado \n" << endl;
    saberTempoCountInvertido(1000000,"1 milhão");
    cout << "Vetor de 1 milhão foi ordenado \n" << endl;
//    saberTempoCountInvertido(10000000,"10 milhões");
//    cout << "Vetor de 10 milhões foi ordenado \n" << endl;
    

    
}
void saberTempoCount(long tamanho, string porextenso){
    long maximo = tamanho;
    CountSort vetor = CountSort(tamanho);
    clock_t inicial, final;
    double tempo;
    for (int i = 0; i < tamanho;i++){
        vetor.Count.inserir(rand()%maximo);
    }
    inicial = clock();
    vetor.ordenaCountSort();
    final = clock();
    //vetor.mostrar();
    tempo = ((double)(final - inicial)/CLOCKS_PER_SEC);
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
    cout << "Numero de repeticoes: "<< vetor.Count.numeros_de_repeticoes << endl;
        cout << "Numero de comparacoes: "<< vetor.Count.numero_de_comparacoes << endl;
}
void saberTempoCountInvertido(long tamanho, string porextenso){
    CountSort vetor = CountSort(tamanho);
    clock_t inicial, final;
    double tempo;
    for (long i = tamanho; i >0;i --){
        vetor.Count.inserir(i);
    }
    inicial = clock();
    vetor.ordenaCountSort();
    final = clock();
    //vetor.mostrar();
    tempo = ((double)(final - inicial)/CLOCKS_PER_SEC);
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
    cout << "Numero de repeticoes: "<< vetor.Count.numeros_de_repeticoes << endl;
        cout << "Numero de comparacoes: "<< vetor.Count.numero_de_comparacoes << endl;
}
void saberTempoCountMetade(long tamanho, string porextenso){
    CountSort vetor = CountSort(tamanho);
    long maximo = tamanho;
    clock_t inicial, final;
    double tempo;
    for (int i = 0; i < tamanho;i++){
        if(i>=tamanho/2){
        vetor.Count.inserir(rand()%maximo);
        }
        vetor.Count.inserir(i);
    }
    inicial = clock();
    vetor.ordenaCountSort();
    final = clock();
    //vetor.mostrar();
    tempo = ((double)(final - inicial)/CLOCKS_PER_SEC);
    cout << "Tempo gasto: "<< tempo << " segundos" << endl;
    cout << "Numero de repeticoes: "<< vetor.Count.numeros_de_repeticoes << endl;
        cout << "Numero de comparacoes: "<< vetor.Count.numero_de_comparacoes << endl;
}

//----------------------------------------GRAVARDADOS-------------------------------------
//void gravardados(double teempo,long tamanho,string porextenso){
//    if(file){
//        fprintf(file,"Tempo %.2f segundos para %s numeros\n", teempo,porextenso.c_str());
//    }else{
//        cout <<"ERRO AO GRAVAR DADO"<<endl;
//    }
//    
//}



#include "ordenacao.hpp"
#include <chrono>  // Biblioteca para medir o tempo
using namespace std;
using namespace std::chrono;  // Para facilitar o uso das funções de tempo

int main() {
    vector<DishRecord> dataset_dishes_bubble = readCSV("dishes.csv");
    vector<DishRecord> dataset_dishes_quick = readCSV("dishes.csv");
    Ordenacao* dishes_bubble = new Ordenacao(dataset_dishes_bubble);
    Ordenacao* dishes_quick = new Ordenacao(dataset_dishes_quick);

    cout << "Iniciando a ordenacao BUBBLE: " << endl;
    auto inicio = high_resolution_clock::now();
    dishes_bubble->bubble_ordenation(dataset_dishes_bubble);
    auto fim = high_resolution_clock::now();
    duration<double> duracao = fim - inicio;

    cout << "Ordenacao finalizada" << endl;
    cout << "Tempo de execucao: " << duracao.count() << " segundos" << endl;
    
    cout << "Iniciando a ordenacao QUICK: " << endl;
    inicio = high_resolution_clock::now();
    dishes_quick->quick_sort(dataset_dishes_quick);
    fim = high_resolution_clock::now();
    duracao = fim - inicio;

    cout << "Ordenacao finalizada" << endl;
    cout << "Tempo de execucao: " << duracao.count() << " segundos" << endl;

    cout << endl;
    dishes_quick->print_dataset_100(dataset_dishes_quick);

    dataset_dishes_bubble.clear();
    dataset_dishes_bubble.shrink_to_fit();
    dataset_dishes_quick.clear();
    dataset_dishes_quick.shrink_to_fit();
    return 0;
}
#include "ordenacao.hpp"
#include <chrono>  // Biblioteca para medir o tempo
using namespace std;
using namespace std::chrono;  // Para facilitar o uso das funções de tempo

int main() {
    vector<DishRecord> dataset_dishes = readCSV("dishes.csv");
    Ordenacao* dishes = new Ordenacao(dataset_dishes);

    cout << "Iniciando a ordenacao: " << endl;
    auto inicio = high_resolution_clock::now();
    dishes->bubble_ordenation(dataset_dishes);
    auto fim = high_resolution_clock::now();
    duration<double> duracao = fim - inicio;

    cout << "Ordenacao finalizada" << endl;
    cout << "Tempo de execucao: " << duracao.count() << " segundos" << endl;
    
    dishes->print_dataset_50(dataset_dishes);

    dataset_dishes.clear();
    dataset_dishes.shrink_to_fit();
    return 0;
}
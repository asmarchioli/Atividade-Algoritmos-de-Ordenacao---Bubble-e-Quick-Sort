#include <string>
#include"readCSV.hpp"
using namespace std;

class Ordenacao{
    protected:
        vector<DishRecord> dishes;

    public:
        Ordenacao(vector<DishRecord> vetor_dishes){
            dishes = vetor_dishes;
        };

        void bubble_ordenation(vector<DishRecord>& vetor_dishes) {
            int tamanho_vetor_dishes = vetor_dishes.size();
            bool trocado;
            int nova_posicao;
            int n = tamanho_vetor_dishes - 1;
            int passo = 0;////////////////////////////////////////////////////////////////////

            do {
                trocado = false;
                nova_posicao = 0;
                std::cout << "Passo " << passo+1 << ": ";///////////////////////////////////
                for (int i = 0; i < n; ++i) {
                    if (vetor_dishes[i].priority < vetor_dishes[i + 1].priority || 
                    (vetor_dishes[i].priority == vetor_dishes[i + 1].priority && vetor_dishes[i].time > vetor_dishes[i + 1].time)) {
                        swap(vetor_dishes[i], vetor_dishes[i + 1]);
                        trocado = true;
                        nova_posicao = i;
                    }
                }
                n = nova_posicao;
                passo++;////////////////////////////////////////////////////////////////////
            } while (trocado);
        }

        void quickSort(vector<DishRecord>& vetor_dishes, int low, int high) {
            if (low < high) {
                int pi = partition(vetor_dishes, low, high);
                quickSort(vetor_dishes, low, pi - 1);
                quickSort(vetor_dishes, pi + 1, high);
            }
        }

        int partition(vector<DishRecord>& vetor_dishes, int low, int high) {
            DishRecord pivot = vetor_dishes[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (vetor_dishes[j].priority > pivot.priority || 
                    (vetor_dishes[j].priority == pivot.priority && vetor_dishes[j].time < pivot.time)) {
                    i++;
                    swap(vetor_dishes[i], vetor_dishes[j]);
                }
            }
            swap(vetor_dishes[i + 1], vetor_dishes[high]);
            return i + 1;
        }

        void quick_sort(vector<DishRecord>& vetor_dishes) {
            quickSort(vetor_dishes, 0, vetor_dishes.size() - 1);
        }


        void print_dataset_50(const std::vector<DishRecord>& dishes) {
            //int tamanho_vetor_dishes = dishes.size();
            for (int i = 0; i < 50; ++i) {
                const DishRecord& dish = dishes[i];
                std::cout << dish.priority << std::setw(10) << dish.time << std::setw(22) << dish.name << std::endl;
            }
        }





};
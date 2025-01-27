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
            for (int i = 0; i < tamanho_vetor_dishes - 1; ++i) {
                cout << i+1 << endl;
                for (int j = 0; j < tamanho_vetor_dishes - i - 1; ++j) {
                    if (vetor_dishes[j].priority < vetor_dishes[j + 1].priority || 
                        (vetor_dishes[j].priority == vetor_dishes[j + 1].priority && vetor_dishes[j].time > vetor_dishes[j + 1].time)) {
                        swap(vetor_dishes[j], vetor_dishes[j + 1]);
                    }
                }
            }
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
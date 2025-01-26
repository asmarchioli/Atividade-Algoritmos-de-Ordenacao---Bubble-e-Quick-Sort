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

        /*void bubble_ordenation(vector<DishRecord>& vetor_dishes){
            int tamanho_vetor_dishes = vetor_dishes.size();
            for (int i = 0; i < tamanho_vetor_dishes; i++){
                for (int j = i +1; j < tamanho_vetor_dishes; j++){
                    if(vetor_dishes[i].priority > vetor_dishes[j].priority){
                        swap(vetor_dishes[i], vetor_dishes[j]);
                    }
                }
            }
        }*/
        void bubble_ordenation(vector<DishRecord>& vetor_dishes) {
            int tamanho_vetor_dishes = vetor_dishes.size();
            bool trocado;
            int nova_posicao;
            int n = tamanho_vetor_dishes - 1;
            do {
                trocado = false;
                nova_posicao = 0;
                for (int i = 0; i < n; ++i) {
                    if (vetor_dishes[i].priority < vetor_dishes[i + 1].priority || 
                    (vetor_dishes[i].priority == vetor_dishes[i + 1].priority && vetor_dishes[i].time > vetor_dishes[i + 1].time)) {
                        swap(vetor_dishes[i], vetor_dishes[i + 1]);
                        trocado = true;
                        nova_posicao = i;
                    }
                }
                n = nova_posicao;
            } while (trocado);
        }


        void print_dataset_50(const std::vector<DishRecord>& dishes) {
            //int tamanho_vetor_dishes = dishes.size();
            for (int i = 0; i < 50; ++i) {
                const DishRecord& dish = dishes[i];
                std::cout << dish.priority << std::setw(10) << dish.time << std::setw(22) << dish.name << std::endl;
            }
        }





};
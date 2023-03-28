#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int N = 100;
    const int MAX_NUM = 10000;
    int numbers[N];

    // Generar números aleatorios en el arreglo
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % (MAX_NUM + 1);
    }

    // Encontrar el número más grande y el más pequeño
    int max_num = numbers[0];
    int min_num = numbers[0];
    for (int i = 1; i < N; i++) {
        if (numbers[i] > max_num) {
            max_num = numbers[i];
        }
        if (numbers[i] < min_num) {
            min_num = numbers[i];
        }
    }
    cout << "El número más grande es " << max_num << endl;
    cout << "El número más pequeño es " << min_num << endl;

    // Encontrar el número que más se repite y el segundo número que más se repite
    int freq[MAX_NUM + 1] = {0}; // Inicializar arreglo de frecuencias en cero
    for (int i = 0; i < N; i++) {
        freq[numbers[i]]++;
    }
    int max_freq = 0;
    int max_freq_num = 0;
    int second_max_freq = 0;
    int second_max_freq_num = 0;
    for (int i = 0; i <= MAX_NUM; i++) {
        if (freq[i] > max_freq) {
            second_max_freq = max_freq;
            second_max_freq_num = max_freq_num;
            max_freq = freq[i];
            max_freq_num = i;
        }
        else if (freq[i] > second_max_freq) {
            second_max_freq = freq[i];
            second_max_freq_num = i;
        }
    }
    cout << "El número que más se repite es " << max_freq_num << endl;
    cout << "El segundo número que más se repite es " << second_max_freq_num << endl;

    // Calcular la suma y el promedio de todos los números
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += numbers[i];
    }
    double avg = (double) sum / N;
    cout << "La suma de todos los números es " << sum << endl;
    cout << "El promedio de todos los números es " << avg << endl;

    // Ordenar los números en un segundo arreglo utilizando el método de selección
    int sorted_numbers[N];
    for (int i = 0; i < N; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (numbers[j] < numbers[min_idx]) {
                min_idx = j;
            }
        }
        sorted_numbers[i] = numbers[min_idx];
        numbers[min_idx] = numbers[i];
    }
    cout << "Los números ordenados son: ";
    for (int i = 0; i < N; i++) {
        cout << sorted_numbers[i] << " ";
    }

 cout << endl;




    return 0;
}

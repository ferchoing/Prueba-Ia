#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int N = 100;
    const int MAX_NUM = 10000;
    int numbers[N];

    // Generar n�meros aleatorios en el arreglo
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % (MAX_NUM + 1);
    }

    // Encontrar el n�mero m�s grande y el m�s peque�o
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
    cout << "El n�mero m�s grande es " << max_num << endl;
    cout << "El n�mero m�s peque�o es " << min_num << endl;

    // Encontrar el n�mero que m�s se repite y el segundo n�mero que m�s se repite
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
    cout << "El n�mero que m�s se repite es " << max_freq_num << endl;
    cout << "El segundo n�mero que m�s se repite es " << second_max_freq_num << endl;

    // Calcular la suma y el promedio de todos los n�meros
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += numbers[i];
    }
    double avg = (double) sum / N;
    cout << "La suma de todos los n�meros es " << sum << endl;
    cout << "El promedio de todos los n�meros es " << avg << endl;

    // Ordenar los n�meros en un segundo arreglo utilizando el m�todo de selecci�n
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
    cout << "Los n�meros ordenados son: ";
    for (int i = 0; i < N; i++) {
        cout << sorted_numbers[i] << " ";
    }

 cout << endl;




    return 0;
}

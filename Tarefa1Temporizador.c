// Inclusão das bibliotecas necessárias
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_G_PIN 11 // Correspondente à cor verde do semáforo
#define LED_Y_PIN 12 // Correspondente à cor amarela do semáforo
#define LED_R_PIN 13 // Correspondente à cor vermelha do semáforo

int semaforo_estado = 0; // Contador: 0 = Verde, 1 = Amarelo, 2 = Vermelho

// Função para inicializar os pinos dos LEDs
void inicializacaoleds() {
    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);

    gpio_init(LED_Y_PIN);
    gpio_set_dir(LED_Y_PIN, GPIO_OUT);

    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);
}

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {

     if (semaforo_estado == 0) {  // Estado vermelho
        gpio_put(LED_G_PIN, 1);
        gpio_put(LED_Y_PIN, 0);
        gpio_put(LED_R_PIN, 0);

        semaforo_estado = 1;  // Próximo estado: amarelo
    } else if (semaforo_estado == 1) {  // Estado amarelo
        gpio_put(LED_G_PIN, 0);
        gpio_put(LED_Y_PIN, 1);
        gpio_put(LED_R_PIN, 0);

        semaforo_estado = 2;  // Próximo estado: verde
    } else {  // Estado verde
        gpio_put(LED_G_PIN, 0);
        gpio_put(LED_Y_PIN, 0);
        gpio_put(LED_R_PIN, 1);

        semaforo_estado = 0;  // Retorna para o estado vermelho
    }
        printf("Altera o sinal.\n");
    return true;
}

int main() {
    stdio_init_all();
    inicializacaoleds(); // Inicializa os LEDs

    struct repeating_timer timer;

    // Configuração do temporizador para chamar a função de callback a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Rotina principal
    while (true) {
        // Contagem de 1 segundo para monitoramento
        sleep_ms(1000);
        printf("Passou 1 segundo.\n");
    }
    return 0;
}

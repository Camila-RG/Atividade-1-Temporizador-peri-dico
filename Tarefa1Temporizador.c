// Inclusão das bibliotecas necessárias
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_G_PIN 11 // Correspondente à cor verde do semáforo
#define LED_B_PIN 12 // Correspondente à cor amarela do semáforo
#define LED_R_PIN 13 // Correspondente à cor vermelha do semáforo

bool led_g_on = false; // Estado inicial do LED
bool led_b_on = false; // Estado inicial do LED
bool led_r_on = false; // Estado inicial do LED

int semaforo_estado = 0; // Contador: 0 = Verde, 1 = Amarelo, 2 = Vermelho

// Função para inicializar os pinos dos LEDs
void inicializacaoleds() {
    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);

    gpio_init(LED_B_PIN);
    gpio_set_dir(LED_B_PIN, GPIO_OUT);

    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);
}

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    printf("Altera o sinal.\n");

    // Desliga todos os LEDs
    gpio_put(LED_G_PIN, false);
    gpio_put(LED_B_PIN, false);
    gpio_put(LED_R_PIN, false);

    // Altera o estado dos LEDs baseado na sequência
    if (semaforo_estado == 0) {
        // Verde acende
        led_g_on = true;
        led_b_on = false;
        led_r_on = false;
        semaforo_estado = 1; // Próximo estado será o amarelo
    } else if (semaforo_estado == 1) {
        // Amarelo acende
        led_b_on = true;
        led_g_on = false;
        led_r_on = false;
        semaforo_estado = 2; // Próximo estado será o vermelho
    } else {
        // Vermelho acende
        led_r_on = true;
        led_b_on = false;
        led_g_on = false;
        semaforo_estado = 0; // Próximo estado será o verde
    }

    return true;
}

int main() {
    stdio_init_all();
    inicializacaoleds(); // Inicializa os LEDs

    struct repeating_timer timer;

    // Configuração do temporizador para chamar a função de callback a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Rotiina principal
    while (true) {
        // Contagem de 1 segundo para monitoramento
        sleep_ms(1000);
        printf("Passou 1 segundo.\n");
    }
    return 0;
}
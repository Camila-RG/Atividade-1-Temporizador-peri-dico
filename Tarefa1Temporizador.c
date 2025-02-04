// Inclusão das bibliotecas necessárias
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_G_PIN 11 // Correspondente à cor verde do semáforo
#define LED_B_PIN 12 // Correspondente à cor amarela do semáforo
#define LED_R_PIN 13 // Correspondente à cor vermelha do semáforo

bool led_g_on = false; // Estado inicial do LED verde
bool led_b_on = false; // Estado inicial do LED amarelo
bool led_r_on = false; // Estado inicial do LED vermelho

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
        // Contagem a cada segundo
        sleep_ms(1000);
        printf("Passou um segundo.\n");
    }

    return 0;
}
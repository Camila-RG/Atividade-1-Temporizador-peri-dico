// Inclusão das bibliotecas necessárias
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_G_PIN 11 // Correspondente a cor vermelho do semáforo
#define LED_B_PIN 12 // Correspondente a cor amarelo do semáforo
#define LED_R_PIN 13 // Correspondente a cor verde do semáforo

void inicializacaoleds(){
    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);
    
    gpio_init(LED_B_PIN);
    gpio_set_dir(LED_B_PIN, GPIO_OUT);

    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);
}
int main()
{
    stdio_init_all();
    inicializacaoleds();

    while (true)
    {
        
    }
}
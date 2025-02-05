# Atividade 01 - Temporizador Periódico 

Este repositório apresenta um projeto feito como resolução da Atividade 01 da U4 do EmbarcaTech da aula síncrona 29/01 sobre clock e temporização. O objetivo do projeto é simular o funcionamento de um semafóro utilizando um microcontrolador Raspberry Pi Pico W, aplicando conhecimentos sobre temporização e controle de LEDs RGB.

O semáforo funciona com três LEDs (vermelho, amarelo e verde), alternando suas cores a cada 3 segundos, enquanto mensagens de status são exibidas.

# Componentes e ferramentas utilizados 

- Raspberry Pi pico W (com Wokwi para simular os componentes)
- 3 Leds RGB (com Wokwi para simular os componentes)
- 3 resistores de 330 Ohms (com Wokwi para simular os componentes)
- Kit de desenvolvimento BitDogLab
- VS Code

# Linguagem utilizada
- C
  
# Funcionamento 

- Controle de LEDs RGB:
O código alterna entre as cores vermelha, amarela e verde, simulando o ciclo de um semáforo real.
- Temporização Precisa:
O temporizador periódico altera o estado do semáforo a cada 3 segundos.
- Feedback Serial:
  O programa exibe uma mensagem na porta serial a cada segundo, permitindo o monitoramento do funcionamento do sistema.
  
 *Lembrete:* O led amarelo será interpretado como azul caso utilize o kit de desenvolvimento BitDogLab.

# Como utilizar?

- Você pode baixar este repositório no GitHub ou clonar o link na sua IDE(VsCode) utilizando o Git/Github Desktop. 
- Instalar um compilador para C/C++ e as extensões: C/C++, Cmake, Raspberry Pi Pico e Wokwi.
- Compilar o código pelo ícone da Raspberry Pi do VSCode e enviar para sua placa, ou utilizar a extensão do Wokwi para testar o funcionamento do programa.

# Passo a Passo da Implementação

## Configuração dos Pinos:
Os pinos GPIO do Raspberry Pi Pico foram configurados como saídas para controlar os LEDs.

## Implementação do Temporizador:
O temporizador periódico (add_repeating_timer_ms) foi configurado para acionar uma função de callback a cada 3 segundos, alternando o estado dos LEDs.

## Exibição de Mensagens
O programa enviou uma mensagem a cada segundo para indicar o funcionamento do sistema.

## Testes e Validação:
O código foi testado tanto no hardware real quanto no simulador Wokwi para garantir o correto funcionamento da temporização e da alternância dos LEDs.

# Autor 
Camila Ramos Gomes

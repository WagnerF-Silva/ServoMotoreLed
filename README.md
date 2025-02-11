# LED e Servo Sincronizados com Raspberry Pi Pico

Este projeto utiliza um Raspberry Pi Pico para controlar um servo motor e um LED simultaneamente. O LED pisca na mesma frequência da movimentação do servo.

## Componentes Necessários
- Raspberry Pi Pico
- Servo motor
- LED
- Resistência (se necessário para o LED)
- Jumpers
- Fonte de alimentação adequada

## Conexões
- **Servo Motor**
  - Pino de sinal: GPIO 22
  - VCC: 5V (ou 3.3V, dependendo do servo)
  - GND: GND do Pico
- **LED**
  - Pino de sinal: GPIO 12
  - GND: GND do Pico

## Funcionamento
O código configura o Raspberry Pi Pico para controlar o servo e o LED via PWM:
- O servo oscila entre 180° --> 90° --> 0°  após isso entra em loop entre  0° e  180°  suavemente e continuamente.
- O LED pisca sincronizado com a movimentação do servo.

## Como Executar
1. Compile e carregue o código no Raspberry Pi Pico.
2. Conecte os componentes conforme indicado.
3. O servo começará a se movimentar e o LED piscará em sincronia.

## Ajustes Possíveis
- Alterar os pinos no código conforme necessário.
- Modificar a frequência de oscilação do servo.
- Ajustar o brilho do LED alterando o ciclo de trabalho do PWM.

## Autor
Desenvolvido por [Wagner Freitas].
Link do video:
https://drive.google.com/file/d/1qyU87Zl6BQvLYCDWpMdFPiIDCEXboGDL/view?usp=sharing

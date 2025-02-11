#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // Pino onde o servo está conectado
#define LED_PIN 12     // Pino do LED RGB para experimento
#define PWM_WRAP 25000 // Valor fixo para o "wrap", correspondente a 20ms (50Hz)

void set_servo_pulse(uint slice_num, uint channel, uint16_t pulse_width) {
    uint16_t level = (pulse_width * PWM_WRAP) / 20000;  // Período de 20ms
    pwm_set_chan_level(slice_num, channel, level);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel = pwm_gpio_to_channel(SERVO_PIN);
    uint led_slice = pwm_gpio_to_slice_num(LED_PIN);
    uint led_channel = pwm_gpio_to_channel(LED_PIN);
    
    pwm_set_wrap(slice_num, PWM_WRAP);  // Define o período de 20ms (50Hz)
    pwm_set_clkdiv(slice_num, 64.0f);
    pwm_set_enabled(slice_num, true);
    
    pwm_set_wrap(led_slice, PWM_WRAP);
    pwm_set_clkdiv(led_slice, 64.0f);
    pwm_set_enabled(led_slice, true);

    // Movimento do servo e piscar do LED sincronizado
    while (1) {
        // Anda entre 180º -> 90º -> 0º
        for (uint16_t pulse = 500; pulse <= 4800; pulse += 20) {
            if (pulse == 800 || pulse == 4800 || pulse == 2340) {
                pwm_set_chan_level(led_slice, led_channel, 0); // Apaga o LED
                sleep_ms(3000);
            }
            pwm_set_chan_level(led_slice, led_channel, PWM_WRAP / 2); // Acende o LED
            set_servo_pulse(slice_num, channel, pulse);
            sleep_ms(10);
        }
        
        // Movimentação periódica suave entre 0 e 180 graus
        while (1) {
            for (uint16_t pulse = 4800; pulse >= 500; pulse -= 5) {
                pwm_set_chan_level(led_slice, led_channel, PWM_WRAP / 2); // LED ligado
                set_servo_pulse(slice_num, channel, pulse);
                sleep_ms(10);
            } 
            for (uint16_t pulse = 500; pulse <= 4800; pulse += 5) {
                pwm_set_chan_level(led_slice, led_channel, 2); // LED desligado
                set_servo_pulse(slice_num, channel, pulse);
                sleep_ms(10);
            }
        }
    }
}

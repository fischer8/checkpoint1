#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
 
#define NOME_ALUNO1 "Henrique Fischer Ruiz"
#define NOME_ALUNO2 "Tiago Toledo Oliveira"
#define NOME_ALUNO3 "Renan Honda Espirito Santo"
 
SemaphoreHandle_t xSemaforo;
 
void tarefa1(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(xSemaforo, portMAX_DELAY) == pdTRUE) {
            printf("[Tarefa 1] Executou - %s\n", NOME_ALUNO1);
            xSemaphoreGive(xSemaforo);
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
}
 
void tarefa2(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(xSemaforo, portMAX_DELAY) == pdTRUE) {
            printf("[Tarefa 2] Executou - %s\n", NOME_ALUNO2);
            xSemaphoreGive(xSemaforo);
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
}
 
void tarefa3(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(xSemaforo, portMAX_DELAY) == pdTRUE) {
            printf("[Tarefa 3] Executou - %s\n", NOME_ALUNO3);
            xSemaphoreGive(xSemaforo);
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
}
 
void app_main() {
    xSemaforo = xSemaphoreCreateBinary();
    xSemaphoreGive(xSemaforo);
 
    xTaskCreate(tarefa1, "Tarefa 1", 2048, NULL, 1, NULL);
    xTaskCreate(tarefa2, "Tarefa 2", 2048, NULL, 1, NULL);
    xTaskCreate(tarefa3, "Tarefa 3", 2048, NULL, 1, NULL);
}
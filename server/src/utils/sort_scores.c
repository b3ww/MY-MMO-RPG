/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** sort_scores
*/

#include "rpg_online_manager.h"

void swap(score_t* a, score_t* b)
{
    score_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(score_t* arr, int low, int high)
{
    if (low < high) {
        int pivot = arr[high].score;
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j].score > pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

int intSize(int num)
{
    int size = 0;
    while (num != 0) {
        size++;
        num /= 10;
    }
    return size;
}

char *intToString(int num)
{
    int size = (num == 0) ? 1 : intSize(num);
    char* str = malloc(size + 1);
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    } else if (num < 0) {
        str[i++] = '-';
        num = -num;
    } while (num != 0) {
        str[i++] = '0' + (num % 10);
        num /= 10;
    }
    str[i] = '\0';
    int j = 0;
    int k = i - 1;
    while (j < k) {
        char tmp = str[j];
        str[j] = str[k]; str[k] = tmp; j++; k--;
    }
    return str;
}
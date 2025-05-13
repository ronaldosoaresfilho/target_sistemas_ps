/* install:
 * Debian: sudo apt install libjansson-dev
 * Arch: sudo pacman -S jansson
 * compile: gcc billing.c -o billing -ljansson
*/
#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>

int main() {
    json_error_t error;
    json_t *data = json_load_file("dados.json", 0, &error);

    if (!data) {
        fprintf(stderr, "Failed to load JSON: %s\n", error.text);
        return 1;
    }

    size_t i;
    json_t *entry;

    float total = 0.0;
    int valid_days = 0;
    float min = -1.0, max = -1.0;
    int above_average = 0;

    json_array_foreach(data, i, entry) {
        json_t *value_json = json_object_get(entry, "valor");
        if (!json_is_number(value_json)) continue;

        float value = json_number_value(value_json);
        if (value > 0.0f) {
            total += value;
            valid_days++;

            if (min < 0 || value < min) min = value;
            if (max < 0 || value > max) max = value;
        }
    }

    float average = total / valid_days;

    json_array_foreach(data, i, entry) {
        float value = json_number_value(json_object_get(entry, "valor"));
        if (value > average)
            above_average++;
    }

    printf("Lowest: R$ %.2f\n", min);
    printf("Highest: R$ %.2f\n", max);
    printf("Days above average: %d\n", above_average);

    json_decref(data);

    return 0;
}


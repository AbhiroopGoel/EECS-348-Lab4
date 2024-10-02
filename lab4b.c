#include <stdio.h>

// Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Function to categorize temperature and provide weather advisory
void categorize_temperature(float celsius) {
    if (celsius <= 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: It's freezing! Stay warm.\n");
    } else if (celsius > 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: It's hot! Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors! It's dangerously hot.\n");
    }
}

// Function to handle conversion based on user input
void convert_temperature(float temp, int current_scale, int target_scale) {
    float converted_temp = temp;
    float temp_in_celsius = temp;  // Store the temperature in Celsius for categorization
    
    // Convert current scale to Celsius first
    if (current_scale == 2) {
        // Fahrenheit to Celsius
        temp_in_celsius = fahrenheit_to_celsius(temp);
    } else if (current_scale == 3) {
        // Kelvin to Celsius
        temp_in_celsius = kelvin_to_celsius(temp);
    }

    // Convert Celsius to target scale
    if (target_scale == 1) {
        // Already in Celsius
        printf("Converted temperature: %.2f°C\n", temp_in_celsius);
    } else if (target_scale == 2) {
        // Celsius to Fahrenheit
        converted_temp = celsius_to_fahrenheit(temp_in_celsius);
        printf("Converted temperature: %.2f°F\n", converted_temp);
    } else if (target_scale == 3) {
        // Celsius to Kelvin
        converted_temp = celsius_to_kelvin(temp_in_celsius);
        printf("Converted temperature: %.2fK\n", converted_temp);
    }

    // Categorize temperature based on Celsius equivalent (temp_in_celsius)
    categorize_temperature(temp_in_celsius);
}

int main() {
    float temperature;
    int current_scale, target_scale;

    // Input loop
    while (1) {
        printf("Enter the temperature (negative value to exit): ");
        scanf("%f", &temperature);

        // Exit if temperature is negative
        if (temperature < 0) {
            printf("Exiting program.\n");
            break;
        }

        // Input validation for temperature scale
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &current_scale);

        // Validate temperature scale input
        if (current_scale < 1 || current_scale > 3) {
            printf("Invalid scale choice. Please enter 1, 2, or 3.\n");
            continue;
        }

        // Prevent invalid Kelvin values (below absolute zero)
        if (current_scale == 3 && temperature < 0) {
            printf("Invalid temperature! Kelvin cannot be negative.\n");
            continue;
        }

        // Input for conversion target
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &target_scale);

        // Validate conversion target input
        if (target_scale < 1 || target_scale > 3 || current_scale == target_scale) {
            printf("Invalid conversion choice or same scale as input. Please try again.\n");
            continue;
        }

        // Perform temperature conversion and display results
        convert_temperature(temperature, current_scale, target_scale);
    }

    return 0;
}

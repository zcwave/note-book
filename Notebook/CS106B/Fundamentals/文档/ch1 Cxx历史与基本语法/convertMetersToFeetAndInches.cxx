// - 1英寸＝0.0254米

// - 1英尺＝12英寸
#include <iostream>

void convertMetersToFeetAndInches(double meter, int &feet, double &inches) {
    int ft = feet;
    double is = inches;

    is = meter / 0.0254;
    ft = (int)(is / 12);
    is -= ft * 12;

    feet = ft;
    inches = is;
}

int main() {
    double meters;
    int feet;
    double inches;

    // Test cases
    double test_cases[] = {1.0, 2.5, 0.0, 10.0}; // Test cases for meters
    
    for (double test_case : test_cases) {
        meters = test_case;

        // Convert meters to feet and inches
      convertMetersToFeetAndInches(meters, feet, inches);

        // Output the result
        std::cout << meters << " meters is equal to " << feet << " feet and " << inches << " inches." << std::endl;
    }

    return 0;
}

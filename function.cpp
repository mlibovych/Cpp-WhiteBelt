#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class FunctionPart {
    public:
        FunctionPart (const char& c, const double& value) {
            operation = c;
            operation_value = value;
        }
        void Invert (void) {
            if (operation == '+') {
                operation = '-';
            }
            else if (operation == '-') {
                operation = '+';
            }
            else if (operation == '*') {
                operation = '/';
            }
            else if (operation == '/') {
                operation = '*';
            }
        }
        double Apply (double src_value) const {
            if (operation == '+') {
                return src_value + operation_value;
            }
            else if (operation == '-') {
                return src_value - operation_value;
            }
            else if (operation == '*') {
                return src_value * operation_value;
            }
            else {
                return src_value / operation_value;
            }
        }
    private:
        char operation;
        double operation_value;
};

class Function {
    public:
        void AddPart (const char& c, const double& value) {
            parts.push_back(FunctionPart(c, value));
        }
        void Invert (void) {
            for (FunctionPart& item : parts) {
                item.Invert();
            }
            reverse(parts.begin(), parts.end());
        }
        double Apply (double value) const {
            for (const FunctionPart& item : parts) {
                value = item.Apply(value);
            }
            return value;
        }
    private:
        vector<FunctionPart> parts;
};

// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

// Function MakeWeightFunction(const Params& params,
//                             const Image& image) {
//   Function function;
//   function.AddPart('*', params.a);
//   function.AddPart('-', image.freshness * params.b);
//   function.AddPart('+', image.rating * params.c);
//   return function;
// }

// double ComputeImageWeight(const Params& params, const Image& image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params& params,
//                               const Image& image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// }

// int main() {
//   Image image = {10, 2, 6};
//   Params params = {4, 2, 6};
//   cout << ComputeImageWeight(params, image) << endl;
//   cout << ComputeQualityByWeight(params, image, 52) << endl;
//   return 0;
// }
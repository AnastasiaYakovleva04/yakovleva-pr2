#include <iostream>

struct BankTransaction { 
    int transactionID;
    float amount;
    char type[20];
};

class Polynomial {
private:
    int degree;         
    float* coeffs;     

public:
  
    Polynomial(int deg = 0) {
        degree = deg;
        coeffs = new float[degree + 1];

        for (int i = 0; i <= degree; i++) {
            coeffs[i] = 0.0;
        }
    }

    void setCoefficients() {
        std::cout << "coefficients from x^0 to x^" << degree << ":\n";
        for (int i = 0; i <= degree; i++) {
            std::cout << "coefficient for x^" << i << ": ";
            std::cin >> coeffs[i];
        }
    }

    float count(float x) {
        float result = 0.0;
        for (int i = 0; i <= degree; i++) {
            result += coeffs[i] * pow(x, i);
        }
        return result;
    }

    ~Polynomial() {
        delete[] coeffs;
    }
};

int main()
{
    
    //1

    std::cout << "v25" << std::endl;
    std::cout << "\ntask1\n" << std::endl;

    int length;
    std::cout << "length: ";
    std::cin >> length;

    int* arr = new int[length];

    for (int i = 0; i < length; i++) {
        std::cout << (i+1) << ": ";
        std::cin >> arr[i];
    }
    for (int i = 0; i < length; i++) {
        std::cout << *(arr + i) << " ";
    }

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    std::cout << "\nsorted array: ";
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }

    float median;
    if (length % 2 == 1) {
        median = arr[length / 2];
    }
    else {
        median = (arr[length / 2 - 1] + arr[length / 2]) / 2;
    }

    std::cout << "\nmedian: " << median << std::endl;

    delete[] arr;

    //2

    std::cout << "\ntask2\n" << std::endl;

    int rows, cols;
    std::cout << "rows: ";
    std::cin >> rows;
    std::cout << "cols: ";
    std::cin >> cols;

    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "\n(" << i << ", " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    int total = rows * cols;
    int* flat = new int[total];
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            flat[index] = matrix[i][j];
            index++;
        }
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (flat[j] > flat[j + 1]) {
                float temp = flat[j];
                flat[j] = flat[j + 1];
                flat[j + 1] = temp;
            }
        }
    }

    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = flat[index];
            index++;
        }
    }

    std::cout << "sorted matrix" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    if (total % 2 == 1) {
        median = flat[total / 2];
    }
    else {
        median = (flat[total / 2 - 1] + flat[total / 2]) / 2;
    }

    std::cout << "\nmedian: " << median << std::endl;
    delete[] matrix;
    delete[] flat;
  
    //3

    std::cout << "\ntask3\n" << std::endl;

    int numOfTr = 0;
    int max = 10; 
    BankTransaction* bankTr = new BankTransaction[max];
    int choice;

    do {
        std::cout << "\n1. add new transaction\n";
        std::cout << "2. view all transactions\n";
        std::cout << "3. exit\n";
        std::cout << "choose: ";
        std::cin >> choice;

        switch (choice) {
        case 1: 
            if (numOfTr < max) {
                std::cout << "transaction " << numOfTr + 1 << std::endl;
                std::cout << "ID: ";
                std::cin >> bankTr[numOfTr].transactionID;
                std::cout << "amount: ";
                std::cin >> bankTr[numOfTr].amount;
                std::cin.ignore();
                std::cout << "type: ";
                std::cin.getline(bankTr[numOfTr].type, 20);
                numOfTr++;
                std::cout << "transaction added!\n";
            }
            else {
                std::cout << "maximum transactions\n";
            }
            break;

        case 2:
            if (numOfTr == 0) {
                std::cout << "no transactions\n";
            }
            else {
                std::cout << "\nall transactions:\n";
                for (int i = 0; i < numOfTr; i++) {
                    std::cout << i + 1 << ": ";
                    std::cout << "ID: " << bankTr[i].transactionID
                        << ", amount: " << bankTr[i].amount
                        << " rub, type: " << bankTr[i].type << std::endl;
                }
            }
            break;

        case 3: 
            break;

        default:
            std::cout << "invalid choice\n";
        }
    } while (choice != 3);

    delete[] bankTr;

    //4

    std::cout << "\ntask4\n" << std::endl;

    int deg;
    std::cout << "polynomial degree: ";
    std::cin >> deg;

    Polynomial poly(deg);
    poly.setCoefficients();

    float x;
    std::cout << "point x to count: ";
    std::cin >> x;

    std::cout << "P(" << x << ") = " << poly.count(x) << std::endl;

    system("pause");
    return 0;
}



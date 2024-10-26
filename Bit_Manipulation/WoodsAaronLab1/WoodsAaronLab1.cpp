#include <iostream>

unsigned int bitField = 0;

void TurnOn(int bitIndex) {
    bitField = bitField | (1 << bitIndex);
}

void TurnOff(int bitIndex) {
    bitField = bitField & ~(1 << bitIndex);
}

void Toggle(int bitIndex) {
    bitField = bitField ^ (1 << bitIndex);
}

void Negate() {
    bitField = ~bitField;
}

void LeftShift() {
    bitField = bitField << 1;
}

void RightShift() {
    bitField = bitField >> 1;
}

int main()
{
    char choice;
    do {
        std::cout << "bitField: " << bitField << std::endl;
        for (int i = 31; i >= 0; --i) {
            int bit = (bitField >> i) & 1;
            std::cout << bit;
        }
        std::cout << "\n";

        int operation;
        std::cout << "\nChoose Operation\n";
        std::cout << "\n1. TurnOn\n2. TurnOff\n3. Toggle\n4. Negate\n5. LeftShift\n6. Right Shift\n\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> operation;

        if (operation >= 1 && operation <= 6) {
            int bitIndex;
            
            switch (operation) {
            case 1:
                do {
                    std::cout << "\nEnter the bit index (0-31): ";
                    std::cin >> bitIndex;
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                } while (bitIndex < 0 || bitIndex > 31);
                TurnOn(bitIndex);
                break;
            case 2:
                do {
                    std::cout << "\nEnter the bit index (0-31): ";
                    std::cin >> bitIndex;
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                } while (bitIndex < 0 || bitIndex > 31);
                TurnOff(bitIndex);
                break;
            case 3:
                do {
                    std::cout << "\nEnter the bit index (0-31): ";
                    std::cin >> bitIndex;
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                } while (bitIndex < 0 || bitIndex > 31);
                Toggle(bitIndex);
                break;
            case 4:
                Negate();
                break;
            case 5:
                LeftShift();
                break;
            case 6:
                RightShift();
                break;
            default:
                std::cout << "\nInvalid operation!\n";
                return 0;
            }

            std::cout << "\nUpdated bitField: " << bitField << std::endl;
            for (int i = 31; i >= 0; --i) {
                int bit = (bitField >> i) & 1;
                std::cout << bit;
            }
            std::cout << "\n";
        }
        else {
            std::cout << "\nInvalid operation!\n";
        }

        std::cout << "\nDo you still want to play with bits? (y/n): ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "\n";

    } while (choice == 'y' || choice == 'Y');
    
    if (choice == 'n' || choice == 'N') {
        std::cout << "Alrighty then! Have a good one!!\n";
    }
    else {
        std::cout << "I'll take that as a NO...\n\n";
    }

    return 0;
}



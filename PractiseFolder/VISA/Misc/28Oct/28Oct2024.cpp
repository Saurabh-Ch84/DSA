#include<iostream>
using namespace std;

class PrinterSpooler {
private:
    static PrinterSpooler* instance;  // static instance pointer
    PrinterSpooler() {                // private constructor
        cout << "PrinterSpooler initialized.\n";
    }

public:
    // Delete copy constructor and assignment operator
    PrinterSpooler(const PrinterSpooler&) = delete;
    PrinterSpooler& operator=(const PrinterSpooler&) = delete;

    static PrinterSpooler* getInstance() {
        if (instance == nullptr) {
            instance = new PrinterSpooler();
        }
        return instance;
    }

    void printDocument(const string& doc) {
        cout << "Printing: " << doc << endl;
    }
};

// Initialize static member
PrinterSpooler* PrinterSpooler::instance = nullptr;

int main() {
    PrinterSpooler* spooler1 = PrinterSpooler::getInstance();
    spooler1->printDocument("Resume.pdf");

    PrinterSpooler* spooler2 = PrinterSpooler::getInstance();
    spooler2->printDocument("OfferLetter.docx");

    // Check if both pointers refer to the same instance
    if (spooler1 == spooler2) {
        cout << "Same instance used for both print jobs.\n";
    }
    return 0;
}